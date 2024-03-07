#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TSystem.h"

#include "RooWorkspace.h"
#include "RooSimultaneous.h"
#include "RooAbsData.h"
#include "RooRealVar.h"
#include "RooAbsArg.h"
#include "RooArgSet.h"
#include "RooDataSet.h"
#include "RooPoisson.h"
#include "RooGaussian.h"
#include "RooSimWSTool.h"
#include "RooProduct.h"
#include "RooAddition.h"

#include "RooStats/ModelConfig.h"
#include "RooStats/FeldmanCousins.h"
#include "RooStats/ToyMCSampler.h"
#include "RooStats/PointSetInterval.h"
#include "RooStats/ConfidenceBelt.h"
#include "RooClassFactory.h"
#include "RooPlot.h"

#include "RooStats/BayesianCalculator.h"
#include "RooStats/RooStatsUtils.h"
#include "RooStats/ProfileLikelihoodTestStat.h"
#include "RooStats/SimpleInterval.h"

bool useProof = false; // flag to control whether to use Proof
int nworkers = 0;      // number of workers (default use all available cores)

using namespace RooFit;
using namespace RooStats;

void MakeWorkspace(double SigEff, double nBkg, double flux_value, double xsec_value, string nuclearModel, string sample)
{
   //
   std::map<string, double> gz8_samples;

   // prior upper limits for gZ8
   gz8_samples.insert(pair<string, double>("b1p1_m05", 2.5e-11));
   gz8_samples.insert(pair<string, double>("b1p1_m10", 3.5e-11));
   gz8_samples.insert(pair<string, double>("b1p1_m20", 7e-11));
   gz8_samples.insert(pair<string, double>("b1p1_m40", 2.5e-10));
   gz8_samples.insert(pair<string, double>("b1p5_m05", 5e-12));
   gz8_samples.insert(pair<string, double>("b1p5_m10", 1e-11));
   gz8_samples.insert(pair<string, double>("b1p5_m20", 2e-11));
   gz8_samples.insert(pair<string, double>("b1p5_m40", 5e-11));
   gz8_samples.insert(pair<string, double>("b10_m05", 2e-12));
   gz8_samples.insert(pair<string, double>("b10_m10", 5e-12));
   gz8_samples.insert(pair<string, double>("b10_m20", 7e-12));
   gz8_samples.insert(pair<string, double>("b10_m40", 4.5e-11));

   // create workspace
   RooWorkspace *pWs = new RooWorkspace("myWS");

   // observable: number of events
   RooRealVar n("n", "n", nBkg,0.1*nBkg,10*nBkg);
   pWs->import(n);

   // exposure time of the detector
   RooRealVar expo("expo", "exposure", 3.154e8);
   pWs->import(expo);

   // number of targets in 40kt (argons nuclei) with systematics
   RooRealVar numtargets("numtargets", "number of targets", 6e32,4e32,8e32);
   pWs->import(numtargets);
   pWs->factory("Gaussian::constr_numtargets(glob_numtargets[6e32,4e32,8e32],numtargets, 3e31)"); // 5% uncertainty


   // coupling constant (g_Z')^8 - parameter of interest
   RooRealVar gZ8("gZ8", "#g_{Z'}^{8}", 0, 0, gz8_samples[sample]);
   pWs->import(gZ8);

   // cross-section \chi-Ar considering (g_Z'=1)
   RooRealVar xsec("xsec", "cross section X-Ar", xsec_value);
   pWs->import(xsec);

   //\chi-flux considering (g_Z'=1)
   RooRealVar flux("flux", "flux", flux_value);
   pWs->import(flux);

   // selection efficiency * acceptance with systematics
   RooRealVar eff("eff", "eff", SigEff, 0.01*SigEff, 10*SigEff);
   RooRealVar sigma_eff("sigma_eff","sigma_eff",0.1*SigEff,0.005*SigEff, 5*SigEff);
   RooRealVar glob_eff("glob_eff","glob_eff",SigEff,0.1*SigEff,10*SigEff);
   pWs->import(eff);
   pWs->import(sigma_eff);
   pWs->import(glob_eff);


   pWs->factory("Gaussian::constr_eff(glob_eff,eff, sigma_eff)"); // 10% uncertainty

   // signal yield
   pWs->factory("prod::nsig(expo,numtargets,flux,xsec,eff,gZ8)");

   // define Bayesian prior PDF for POI
   pWs->factory("Uniform::prior(gZ8)");

   // background yield with systematics
   RooRealVar nbkg("nbkg", "nbkg", nBkg);
   RooRealVar sigma_nBkg("sigma_nBkg", "sigma_nBkg", 0.40*nBkg, 0.04*nBkg, 4*nBkg);
   RooRealVar glob_nbkg("glob_nbkg", "glob_nbkg", nBkg,0.1*nBkg,10*nBkg);
   pWs->import(nbkg);
   pWs->import(sigma_nBkg);
   pWs->import(glob_nbkg);
   pWs->factory("Gaussian::constr_nbkg(glob_nbkg,nbkg,sigma_nBkg)"); // 40% uncertainty

   // full event yield
   pWs->factory("sum::yield(nsig,nbkg)");
   // Core model: Poisson probability with mean signal+bkg
   pWs->factory("Poisson::model_core(n,yield)");

   // model with systematics
   pWs->factory("PROD::model(model_core,constr_numtargets,constr_eff,constr_nbkg)");

   RooRealVar *pObs = pWs->var("n"); // get the pointer to the observable
   pWs->var("n")->Print();
   RooArgSet obs("observables");
   obs.add(*pObs);

   // create the dataset
   pObs->setVal(nBkg); // this is your observed data: same as expected background
   pObs->Print();
   RooDataSet *data = new RooDataSet("data", "data", obs);
   data->add(*pObs);

   // import dataset into workspace
   pWs->import(*data);

   // create set of global observables (need to be defined as constants!)
   pWs->var("glob_numtargets")->setConstant(true);
   pWs->var("glob_eff")->setConstant(true);
   pWs->var("glob_nbkg")->setConstant(true);
   RooArgSet globalObs("global_obs");
   globalObs.add(*pWs->var("glob_numtargets"));
   globalObs.add(*pWs->var("glob_eff"));
   globalObs.add(*pWs->var("glob_nbkg"));

   // create set of parameters of interest (POI)
   RooArgSet poi("poi");
   poi.add(*pWs->var("gZ8"));
   poi.Print();

   // create set of nuisance parameters
   RooArgSet nuis("nuis");
   nuis.add(*pWs->var("beta_eff"));
   nuis.add(*pWs->var("beta_nbkg"));

   // fix all other variables in model:
   // everything except observables, POI, and nuisance parameters
   // must be constant
   pWs->var("numtargets")->setConstant(true);
   pWs->var("eff_nom")->setConstant(true);
   pWs->var("flux")->setConstant(true);
   pWs->var("xsec")->setConstant(true);
   pWs->var("nbkg_nom")->setConstant(true);
   pWs->var("expo")->setConstant(true);
   pWs->var("eff_kappa")->setConstant(true);
   pWs->var("nbkg_kappa")->setConstant(true);
   RooArgSet fixed("fixed");
   fixed.add(*pWs->var("numtargets"));
   fixed.add(*pWs->var("eff_nom"));
   fixed.add(*pWs->var("nbkg_nom"));
   fixed.add(*pWs->var("expo"));
   fixed.add(*pWs->var("flux"));
   fixed.add(*pWs->var("xsec"));
   fixed.add(*pWs->var("eff_kappa"));
   fixed.add(*pWs->var("nbkg_kappa"));

   // create signal+background Model Config
   RooStats::ModelConfig sbHypo("SbHypo");
   sbHypo.SetWorkspace(*pWs);
   sbHypo.SetPdf(*pWs->pdf("model"));
   sbHypo.SetObservables(obs);
   sbHypo.SetGlobalObservables(globalObs);
   sbHypo.SetParametersOfInterest(poi);
   sbHypo.SetNuisanceParameters(nuis);

   // this is optional, for Bayesian analysis
   sbHypo.SetPriorPdf(*pWs->pdf("prior"));

   // set parameter snapshot that corresponds to the best fit to data
   RooAbsReal *pNll = sbHypo.GetPdf()->createNLL(*data);
   // do not profile global observables
   RooAbsReal *pProfile = pNll->createProfile(globalObs);
   // this will do fit and set POI and nuisance
   pProfile->getVal(); // parameters to fitted values

   RooArgSet *pPoiAndNuisance = new RooArgSet("poiAndNuisance");
   pPoiAndNuisance->add(*sbHypo.GetNuisanceParameters());
   pPoiAndNuisance->add(*sbHypo.GetParametersOfInterest());
   sbHypo.SetSnapshot(*pPoiAndNuisance);
   delete pProfile;
   delete pNll;
   delete pPoiAndNuisance;

   // create background-only Model Config from the S+B one
   RooStats::ModelConfig bHypo = sbHypo;
   bHypo.SetName("BHypo");
   bHypo.SetWorkspace(*pWs);

   // set parameter snapshot for bHypo, setting gZ^8=0
   // it is useful to understand how this block of code works
   // but you can also use it as a recipe to make a parameter snapshot
   pNll = bHypo.GetPdf()->createNLL(*data);
   RooArgSet poiAndGlobalObs("poiAndGlobalObs");
   poiAndGlobalObs.add(poi);
   poiAndGlobalObs.add(globalObs);
   // do not profile POI and global observables
   pProfile = pNll->createProfile(poiAndGlobalObs);
   ((RooRealVar *)poi.first())->setVal(0); // set gZ'^8=0 here
   pProfile->getVal();                     // this will do fit and set nuisance parameters to profiled values
   pPoiAndNuisance = new RooArgSet("poiAndNuisance");
   pPoiAndNuisance->add(nuis);
   pPoiAndNuisance->add(poi);
   bHypo.SetSnapshot(*pPoiAndNuisance);
   delete pProfile;
   delete pNll;
   delete pPoiAndNuisance;

   // import ModelConfig into workspace
   // bHypo.SetWorkspace(*pWs);
   pWs->import(bHypo);
   pWs->import(sbHypo);

   // print out the workspace contents
   pWs->Print();

   // save workspace to file
   string ws_out_name = "workspaces/workspace_" + nuclearModel.substr(nuclearModel.length() - 9, 5) + '_' + sample + ".root";
   pWs->SaveAs(ws_out_name.c_str());
   return;
}

// -------------------------------------------------------
// The actual macro

void OneSidedFrequentistUpperLimitWithBands_bdm(std::string filename = "workspace_test.root", const char *workspaceName = "myWS",
                                                const char *modelConfigName = "SbHypo",
                                                const char *dataName = "data")
{

   double confidenceLevel = 0.90;
   int nPointsToScan = 300;
   int nToyMC = 700;

   // Try to open the file
   TFile *file = TFile::Open(filename.c_str());

   // if input file was specified byt not found, quit
   if (!file)
   {
      cout << "StandardRooStatsDemoMacro: Input file " << filename << " is not found" << endl;
      return;
   }

   // -------------------------------------------------------
   // Now get the data and workspace

   // get the workspace out of the file
   RooWorkspace *w = (RooWorkspace *)file->Get(workspaceName);
   if (!w)
   {
      cout << "workspace not found" << endl;
      return;
   }

   // get the modelConfig out of the file
   ModelConfig *mc = (ModelConfig *)w->obj(modelConfigName);

   // get the modelConfig out of the file
   RooAbsData *data = w->data(dataName);

   // make sure ingredients are found
   if (!data || !mc)
   {
      w->Print();
      cout << "data or ModelConfig was not found" << endl;
      return;
   }

   // -------------------------------------------------------
   // Now get the POI for convenience
   // you may want to adjust the range of your POI

   RooRealVar *firstPOI = (RooRealVar *)mc->GetParametersOfInterest()->first();
   /*  firstPOI->setMin(0);*/
   /*  firstPOI->setMax(10);*/

   // --------------------------------------------
   // Create and use the FeldmanCousins tool
   // to find and plot the 95% confidence interval
   // on the parameter of interest as specified
   // in the model config
   // REMEMBER, we will change the test statistic
   // so this is NOT a Feldman-Cousins interval
   FeldmanCousins fc(*data, *mc);
   fc.SetConfidenceLevel(confidenceLevel);
   fc.AdditionalNToysFactor(0.5); // degrade/improve sampling that defines confidence belt: in this case makes the example faster
   /*  fc.UseAdaptiveSampling(true); // speed it up a bit, don't use for expected limits*/
   fc.SetNBins(nPointsToScan); // set how many points per parameter of interest to scan
   fc.CreateConfBelt(true);    // save the information in the belt for plotting
   // -------------------------------------------------------
   // Feldman-Cousins is a unified limit by definition
   // but the tool takes care of a few things for us like which values
   // of the nuisance parameters should be used to generate toys.
   // so let's just change the test statistic and realize this is
   // no longer "Feldman-Cousins" but is a fully frequentist Neyman-Construction.
   /*  ProfileLikelihoodTestStatModified onesided(*mc->GetPdf());*/
   /*  fc.GetTestStatSampler()->SetTestStatistic(&onesided);*/
   /* ((ToyMCSampler*) fc.GetTestStatSampler())->SetGenerateBinned(true); */
   ToyMCSampler *toymcsampler = (ToyMCSampler *)fc.GetTestStatSampler();
   ProfileLikelihoodTestStat *testStat = dynamic_cast<ProfileLikelihoodTestStat *>(toymcsampler->GetTestStatistic());
   testStat->SetOneSided(true);

   // Since this tool needs to throw toy MC the PDF needs to be
   // extended or the tool needs to know how many entries in a dataset
   // per pseudo experiment.
   // In the 'number counting form' where the entries in the dataset
   // are counts, and not values of discriminating variables, the
   // datasets typically only have one entry and the PDF is not
   // extended.
   if (!mc->GetPdf()->canBeExtended())
   {
      if (data->numEntries() == 1)
         fc.FluctuateNumDataEntries(false);
      else
         cout << "Not sure what to do about this model" << endl;
   }

   // We can use PROOF to speed things along in parallel
   // However, the test statistic has to be installed on the workers
   // so either turn off PROOF or include the modified test statistic
   // in your `$ROOTSYS/roofit/roostats/inc` directory,
   // add the additional line to the LinkDef.h file,
   // and recompile root.
   if (useProof)
   {
      ProofConfig pc(*w, nworkers, "", false);
      toymcsampler->SetProofConfig(&pc); // enable proof
   }

   if (mc->GetGlobalObservables())
   {
      cout << "will use global observables for unconditional ensemble" << endl;
      mc->GetGlobalObservables()->Print();
      toymcsampler->SetGlobalObservables(*mc->GetGlobalObservables());
   }

   // Now get the interval
   PointSetInterval *interval = fc.GetInterval();
   ConfidenceBelt *belt = fc.GetConfidenceBelt();

   // print out the interval on the first Parameter of Interest
   cout << "\n90% interval on " << firstPOI->GetName() << " is : [" << interval->LowerLimit(*firstPOI) << ", "
        << interval->UpperLimit(*firstPOI) << "] " << endl;

   // get observed UL and value of test statistic evaluated there
   RooArgSet tmpPOI(*firstPOI);
   double observedUL = interval->UpperLimit(*firstPOI);
   firstPOI->setVal(observedUL);
   double obsTSatObsUL = fc.GetTestStatSampler()->EvaluateTestStatistic(*data, tmpPOI);

   // Ask the calculator which points were scanned
   RooDataSet *parameterScan = (RooDataSet *)fc.GetPointsToScan();
   RooArgSet *tmpPoint;

   // make a histogram of parameter vs. threshold
   TH1F *histOfThresholds =
       new TH1F("histOfThresholds", "", parameterScan->numEntries(), firstPOI->getMin(), firstPOI->getMax());
   histOfThresholds->GetXaxis()->SetTitle(firstPOI->GetName());
   histOfThresholds->GetYaxis()->SetTitle("Threshold");

   // loop through the points that were tested and ask confidence belt
   // what the upper/lower thresholds were.
   // For FeldmanCousins, the lower cut off is always 0
   for (Int_t i = 0; i < parameterScan->numEntries(); ++i)
   {
      tmpPoint = (RooArgSet *)parameterScan->get(i)->clone("temp");
      // cout <<"get threshold"<<endl;
      double arMax = belt->GetAcceptanceRegionMax(*tmpPoint);
      double poiVal = tmpPoint->getRealValue(firstPOI->GetName());
      histOfThresholds->Fill(poiVal, arMax);
   }
   TCanvas *c1 = new TCanvas();
   c1->Divide(3);
   c1->cd(1);
   histOfThresholds->SetMinimum(0);
   histOfThresholds->Draw();
   c1->cd(2);

   // -------------------------------------------------------
   // Now we generate the expected bands and power-constraint

   // First: find parameter point for mu=0, with conditional MLEs for nuisance parameters
   RooAbsReal *nll = mc->GetPdf()->createNLL(*data);
   RooAbsReal *profile = nll->createProfile(*mc->GetParametersOfInterest());

   firstPOI->setVal(0.);
   profile->getVal(); // this will do fit and set nuisance parameters to profiled values
   RooArgSet *poiAndNuisance = new RooArgSet();
   if (mc->GetNuisanceParameters())
      poiAndNuisance->add(*mc->GetNuisanceParameters());
   poiAndNuisance->add(*mc->GetParametersOfInterest());
   w->saveSnapshot("paramsToGenerateData", *poiAndNuisance);
   RooArgSet *paramsToGenerateData = (RooArgSet *)poiAndNuisance->snapshot();
   cout << "\nWill use these parameter points to generate pseudo data for bkg only" << endl;
   paramsToGenerateData->Print("v");

   RooArgSet unconditionalObs;
   unconditionalObs.add(*mc->GetObservables());
   unconditionalObs.add(*mc->GetGlobalObservables()); // comment this out for the original conditional ensemble

   double CLb = 0;
   double CLbinclusive = 0;

   // Now we generate background only and find distribution of upper limits
   TH1F *histOfUL = new TH1F("histOfUL", "", 100, 0, firstPOI->getMax());
   TH1F *histOfTS = new TH1F("histOfTS", "", 100, 0, firstPOI->getMax());
   histOfTS->GetXaxis()->SetTitle("R(background only)");
   histOfTS->GetYaxis()->SetTitle("Entries");
   histOfUL->GetXaxis()->SetTitle("Upper Limit (background only)");
   histOfUL->GetYaxis()->SetTitle("Entries");
   for (int imc = 0; imc < nToyMC; ++imc)
   {

      // set parameters back to values for generating pseudo data
      //    cout << "\n get current nuis, set vals, print again" << endl;
      w->loadSnapshot("paramsToGenerateData");
      //    poiAndNuisance->Print("v");

      RooDataSet *toyData = 0;
      // now generate a toy dataset
      if (!mc->GetPdf()->canBeExtended())
      {
         if (data->numEntries() == 1)
            toyData = mc->GetPdf()->generate(*mc->GetObservables(), 1);
         else
            cout << "Not sure what to do about this model" << endl;
      }
      else
      {
         //      cout << "generating extended dataset"<<endl;
         toyData = mc->GetPdf()->generate(*mc->GetObservables(), Extended());
      }

      // generate global observables
      // need to be careful for simpdf
      //    RooDataSet* globalData = mc->GetPdf()->generate(*mc->GetGlobalObservables(),1);

      RooSimultaneous *simPdf = dynamic_cast<RooSimultaneous *>(mc->GetPdf());
      if (!simPdf)
      {
         RooDataSet *one = mc->GetPdf()->generate(*mc->GetGlobalObservables(), 1);
         const RooArgSet *values = one->get();
         RooArgSet *allVars = mc->GetPdf()->getVariables();
         *allVars = *values;
         // delete allVars;
         // delete values;
         // delete one;
      }
      else
      {

         // try fix for sim pdf
         TIterator *iter = simPdf->indexCat().typeIterator();
         RooCatType *tt = NULL;
         while ((tt = (RooCatType *)iter->Next()))
         {

            // Get pdf associated with state from simpdf
            RooAbsPdf *pdftmp = simPdf->getPdf(tt->GetName());

            // Generate only global variables defined by the pdf associated with this state
            RooArgSet *globtmp = pdftmp->getObservables(*mc->GetGlobalObservables());
            RooDataSet *tmp = pdftmp->generate(*globtmp, 1);

            // Transfer values to output placeholder
            *globtmp = *tmp->get(0);

            // Cleanup
            delete globtmp;
            delete tmp;
         }
      }

      //    globalData->Print("v");
      //    unconditionalObs = *globalData->get();
      //    mc->GetGlobalObservables()->Print("v");
      //    delete globalData;
      //    cout << "toy data = " << endl;
      //    toyData->get()->Print("v");

      // get test stat at observed UL in observed data
      firstPOI->setVal(observedUL);
      double toyTSatObsUL = fc.GetTestStatSampler()->EvaluateTestStatistic(*toyData, tmpPOI);
      // toyData->get()->Print("v");
      //  cout << "obsTSatObsUL " << obsTSatObsUL << "toyTS " << toyTSatObsUL << endl;
      if (obsTSatObsUL < toyTSatObsUL) // not sure about <= part yet
         CLb += (1.) / nToyMC;
      if (obsTSatObsUL <= toyTSatObsUL) // not sure about <= part yet
         CLbinclusive += (1.) / nToyMC;

      // loop over points in belt to find upper limit for this toy data
      double thisTS = 0;
      double thisUL = 0;
      for (Int_t i = 0; i < parameterScan->numEntries(); ++i)
      {
         tmpPoint = (RooArgSet *)parameterScan->get(i)->clone("temp");
         double arMax = belt->GetAcceptanceRegionMax(*tmpPoint);
         firstPOI->setVal(tmpPoint->getRealValue(firstPOI->GetName()));
         double thisTS_profile = profile->getVal();
         double tmpTS = fc.GetTestStatSampler()->EvaluateTestStatistic(*toyData, tmpPOI);

         // cout << "poi = " << firstPOI->getVal()
         //      << " max is " << arMax << " this profile = " << thisTS << endl;
         thisTS = tmpTS;
         histOfTS->Fill(firstPOI->getVal());
         if (tmpTS <= arMax)
         {
            thisUL = firstPOI->getVal();
         }
         else
         {
            break;
         }
      }

      /*
      // loop over points in belt to find upper limit for this toy data
      double thisUL = 0;
      for(Int_t i=0; i<histOfThresholds->GetNbinsX(); ++i){
         tmpPoint = (RooArgSet*) parameterScan->get(i)->clone("temp");
         cout <<"----------------  "<<i<<endl;
         tmpPoint->Print("v");
         cout << "from hist " << histOfThresholds->GetBinCenter(i+1) <<endl;
         double arMax = histOfThresholds->GetBinContent(i+1);
         // cout << " threhold from Hist = aMax " << arMax<<endl;
         // double arMax2 = belt->GetAcceptanceRegionMax(*tmpPoint);
         // cout << "from scan arMax2 = "<< arMax2 << endl; // not the same due to TH1F not TH1D
         // cout << "scan - hist" << arMax2-arMax << endl;
         firstPOI->setVal( histOfThresholds->GetBinCenter(i+1));
         //   double thisTS = profile->getVal();
         double thisTS = fc.GetTestStatSampler()->EvaluateTestStatistic(*toyData,tmpPOI);

         //   cout << "poi = " << firstPOI->getVal()
         // << " max is " << arMax << " this profile = " << thisTS << endl;
         //      cout << "thisTS = " << thisTS<<endl;

         // NOTE: need to add a small epsilon term for single precision vs. double precision
         if(thisTS<=arMax + 1e-7){
            thisUL = firstPOI->getVal();
         } else{
            break;
         }
      }
      */

      histOfUL->Fill(thisUL);

      // for few events, data is often the same, and UL is often the same
      //    cout << "thisUL = " << thisUL<<endl;

      // delete toyData;
   }
   histOfUL->Draw();
   c1->cd(3);
   histOfTS->Draw();
   std::cout << std::endl;
   std::cout << histOfTS->Integral(histOfTS->FindFixBin(0), histOfTS->FindFixBin(interval->UpperLimit(*firstPOI))) << std::endl;
   std::string outpdf = "plots/OneSidedFrequentisUpperLimit_bdm_" + filename.substr(21, 14);
   c1->SaveAs((outpdf + ".pdf").c_str());
   c1->SaveAs((outpdf + ".C").c_str());
   // if you want to see a plot of the sampling distribution for a particular scan point:
   /*
   SamplingDistPlot sampPlot;
   int indexInScan = 0;
   tmpPoint = (RooArgSet*) parameterScan->get(indexInScan)->clone("temp");
   firstPOI->setVal( tmpPoint->getRealValue(firstPOI->GetName()) );
   toymcsampler->SetParametersForTestStat(tmpPOI);
   SamplingDistribution* samp = toymcsampler->GetSamplingDistribution(*tmpPoint);
   sampPlot.AddSamplingDistribution(samp);
   sampPlot.Draw();
      */

   // Now find bands and power constraint
   Double_t *bins = histOfUL->GetIntegral();
   TH1F *cumulative = (TH1F *)histOfUL->Clone("cumulative");
   cumulative->SetContent(bins);
   double band2sigDown, band1sigDown, bandMedian, band1sigUp, band2sigUp;
   for (int i = 1; i <= cumulative->GetNbinsX(); ++i)
   {
      if (bins[i] < RooStats::SignificanceToPValue(2))
         band2sigDown = cumulative->GetBinCenter(i);
      if (bins[i] < RooStats::SignificanceToPValue(1))
         band1sigDown = cumulative->GetBinCenter(i);
      if (bins[i] < 0.5)
         bandMedian = cumulative->GetBinCenter(i);
      if (bins[i] < RooStats::SignificanceToPValue(-1))
         band1sigUp = cumulative->GetBinCenter(i);
      if (bins[i] < RooStats::SignificanceToPValue(-2))
         band2sigUp = cumulative->GetBinCenter(i);
   }
   cout << "-2 sigma  band " << band2sigDown << endl;
   cout << "-1 sigma  band " << band1sigDown << " [Power Constraint)]" << endl;
   cout << "median of band " << bandMedian << endl;
   cout << "+1 sigma  band " << band1sigUp << endl;
   cout << "+2 sigma  band " << band2sigUp << endl;

   // print out the interval on the first Parameter of Interest
   cout << "\nobserved 90% upper-limit " << interval->UpperLimit(*firstPOI) << endl;
   cout << "CLb strict [P(toy>obs|0)] for observed 90% upper-limit " << CLb << endl;
   cout << "CLb inclusive [P(toy>=obs|0)] for observed 90% upper-limit " << CLbinclusive << endl;

   delete profile;
   delete nll;
}

//Let's check the Bayesian upper limit
void GetBayesianInterval(std::string filename = "workspace_test.root",
                         std::string wsname = "myWS")
{
   // open file with workspace for reading
   TFile *pInFile = new TFile(filename.c_str(), "read");

   // load workspace
   RooWorkspace *pWs = (RooWorkspace *)pInFile->Get(wsname.c_str());
   if (!pWs)
   {
      std::cout << "workspace " << wsname << " not found" << std::endl;
      return;
   }

   // printout workspace content
   pWs->Print();

   // load and print data from workspace
   RooAbsData *data = pWs->data("data");
   data->Print();

   // load and print S+B Model Config
   RooStats::ModelConfig *pSbHypo = (RooStats::ModelConfig *)pWs->obj("SbHypo");
   pSbHypo->Print();
   RooAbsPdf *pdf = pSbHypo->GetPriorPdf();

   /* for (double i = 0.7; i < 0.75; i = i + 0.005)
    {*/
   double i = 0.9;
   // create RooStats Bayesian calculator and set parameters
   RooStats::BayesianCalculator bCalc(*data, *pSbHypo);
   bCalc.SetName("myBC");
   std::cout << "i = " << i << std::endl;
   bCalc.SetConfidenceLevel(i);
   bCalc.SetLeftSideTailFraction(0);
   // bCalc.SetTestSize(0.05);
   // bCalc.SetIntegrationType("ROOFIT");

   // estimate credible interval
   // NOTE: unfortunate notation: the UpperLimit() name refers
   //       to the upper boundary of an interval,
   //       NOT to the upper limit on the parameter of interest
   //       (it just happens to be the same for the one-sided
   //       interval starting at 0)
   RooStats::SimpleInterval *pSInt = bCalc.GetInterval();
   double upper_bound = pSInt->UpperLimit();
   double lower_bound = pSInt->LowerLimit();

   // make posterior PDF plot for POI
   TCanvas c1("posterior");
   bCalc.SetScanOfPosterior(200);
   RooPlot *pPlot = bCalc.GetPosteriorPlot();
   pPlot->Draw();

   std::string outpdf = "plots/bayesian_num_posterior_bdm_" + filename.substr(21, 14);

   c1.SaveAs((outpdf + ".pdf").c_str());
   c1.SaveAs((outpdf + ".C").c_str());

   std::cout << "one-sided " << i << " C.L. bayesian "
                                     "credible interval for gZ^8: ["
             << lower_bound << ", " << upper_bound
             << "]" << std::endl;

   // clean up a little
   delete pSInt;
   // }
}

//Take signal efficiency and background expected from the tables
std::vector<std::vector<double>> TakeEffandBkg(string Tabletxt)
{

   string line;
   // Creation of ifstream class object to read the file
   ifstream fin;
   // by default open mode = ios::in mode
   fin.open(Tabletxt);
   getline(fin, line);

   std::vector<double> Eff;
   Eff.clear();
   std::vector<double> Bkg;
   Bkg.clear();
   int p = 4;
   int j = 5;
   int i = 1;
   double tmp_var = 0;

   while (!fin.eof())
   {
     // std::cout << "i= " << i << std::endl;
      fin >> tmp_var;

      if (p == i)
      {
     //    std::cout << "tmp_var = " << tmp_var << std::endl;
         p = p + 8;
         Eff.push_back(tmp_var);
      }
      if (j == i)
      {
       //  std::cout << "tmp_var = " << tmp_var << std::endl;
         j = j + 8;
         Bkg.push_back(tmp_var);
      }
      i++;
   }
   std::vector<std::vector<double>> result;
   result.push_back(Eff);
   result.push_back(Bkg);

   return result;
}

void MakeAllWS(bool test = false)
{

   std::vector<std::string> tables{"Eff_Bkg_hA_BR.txt",
                                   "Eff_Bkg_hA_LFG.txt",
                                   "Eff_Bkg_hA_ESF.txt",
                                   "Eff_Bkg_hN_BR.txt",
                                   "Eff_Bkg_hN_LFG.txt",
                                   "Eff_Bkg_hN_ESF.txt"};

   std::vector<std::string> labelsamples{"b1p1_m05",
                                         "b1p1_m10",
                                         "b1p1_m20",
                                         "b1p1_m40",
                                         "b1p5_m05",
                                         "b1p5_m10",
                                         "b1p5_m20",
                                         "b1p5_m40",
                                         "b10_m05",
                                         "b10_m10",
                                         "b10_m20",
                                         "b10_m40"};

   // flux vector
   std::vector<double>
       flux_vec{634.1, 303.6, 117.7, 36.38, 468.3, 203.4, 72.48, 19.10, 28.12, 7.521, 2.455, 0.431};
   //  argon cross section flux
   std::vector<double> xsec_vec{9.057 * 1e-30, 1.063 * 1e-29, 1.220 * 1e-29, 1.278 * 1e-29, 4.978 * 1e-29, 5.609 * 1e-29, 5.965 * 1e-29, 6.152 * 1e-29, 1.270 * 1e-27, 1.377 * 1e-27, 1.437 * 1e-27, 1.470 * 1e-27};

   std::vector<std::vector<double>> EffandBkgNumber;
   for (size_t i = 0; i < tables.size(); i++)
   {
      EffandBkgNumber = TakeEffandBkg(tables[i]);
      for (size_t j = 0; j < flux_vec.size(); j++)
      {
         MakeWorkspace(EffandBkgNumber.at(0).at(j), EffandBkgNumber.at(1).at(j), flux_vec.at(j), xsec_vec.at(j), tables[i], labelsamples[j]);
      }
      if (test) //Just one nuclear model to test, and speed up
      {
         return;
      }
   }
}

void UpperLimitAllDefaultModels()
{

   std::vector<std::string> ws_hA_BR{
       "workspaces/workspace_hA_BR_b1p1_m05.root",
       "workspaces/workspace_hA_BR_b1p1_m10.root",
       "workspaces/workspace_hA_BR_b1p1_m20.root",
       "workspaces/workspace_hA_BR_b1p1_m40.root",
       "workspaces/workspace_hA_BR_b1p5_m05.root",
       "workspaces/workspace_hA_BR_b1p5_m10.root",
       "workspaces/workspace_hA_BR_b1p5_m20.root",
       "workspaces/workspace_hA_BR_b1p5_m40.root",
       "workspaces/workspace_hA_BR_b10_m05.root",
       "workspaces/workspace_hA_BR_b10_m10.root",
       "workspaces/workspace_hA_BR_b10_m20.root",
       "workspaces/workspace_hA_BR_b10_m40.root"};

   for (size_t i = 0; i < ws_hA_BR.size(); i++)
   {
      OneSidedFrequentistUpperLimitWithBands_bdm(ws_hA_BR[i]);
      GetBayesianInterval(ws_hA_BR[i]);
   }
}
