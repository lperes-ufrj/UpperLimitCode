# %%
import sys
print(sys.version)
import numpy as np
import ROOT
from array import *
import matplotlib.pyplot as plt
import math
from scipy.optimize import brentq

# %%
def resultsTOtxt(arr,  filename):
#arr is the concatenated and transposed array of all the arrays wished to be written
#arrDescription a string describing and is each collumn of the file
#writes out each array concatenated in arr as an collumn in the file
    file = open(filename, 'w')
    np.savetxt(filename, arr, delimiter=' ')
    file.close()

# %%
list_nuclearmodels = [['hA_BR','00a'],['hA_LFG','01a'],['hA_ESF','02a'],['hN_BR','00b'],['hN_LFG','01b'],['hN_ESF','02b']]
listsamples = ['m05_b1p1', 'm05_b1p5', 'm05_b10', 'm10_b1p1', 'm10_b1p5', 'm10_b10', 'm20_b1p1', 'm20_b1p5', 'm20_b10', 'm40_b1p1', 'm40_b1p5', 'm40_b10']
list_samples_latex = [r'$m_\chi = 5 \text{ GeV}, \; \gamma=1.1$', r'$m_\chi = 10 \text{ GeV}, \; \gamma=1.1$',r'$m_\chi = 20 \text{ GeV}, \; \gamma=1.1$', r'$m_\chi = 40 \text{ GeV}, \; \gamma=1.1$', r'$m_\chi = 5 \text{ GeV}, \; \gamma=1.5$', r'$m_\chi = 10 \text{ GeV}, \; \gamma=1.5$', r'$m_\chi = 20 \text{ GeV}, \; \gamma=1.5$', r'$m_\chi = 40 \text{ GeV}, \; \gamma=1.5$', r'$m_\chi = 5 \text{ GeV}, \; \gamma=10$', r'$m_\chi = 10 \text{ GeV}, \; \gamma=10$', r'$m_\chi = 20 \text{ GeV}, \; \gamma=10$', r'$m_\chi = 40 \text{ GeV}, \; \gamma=10$' ]


# %%
def ReadNuclearModelSamples(nu_model):
    if nu_model[1] != '00a':
        fatm = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/atm_'+nu_model[0]+'.root')
    else:
        fatm = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/atm_'+nu_model[0]+'_4ana.root')
    fbdm_m05_b1p1 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m05_b1p1_'+nu_model[1]+'.root') 
    fbdm_m10_b1p1 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m10_b1p1_'+nu_model[1]+'.root')
    fbdm_m20_b1p1 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m20_b1p1_'+nu_model[1]+'.root')  
    fbdm_m40_b1p1 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m40_b1p1_'+nu_model[1]+'.root')
    fbdm_m05_b1p5 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m05_b1p5_'+nu_model[1]+'.root')  
    fbdm_m10_b1p5 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m10_b1p5_'+nu_model[1]+'.root')
    fbdm_m20_b1p5 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m20_b1p5_'+nu_model[1]+'.root')
    fbdm_m40_b1p5 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m40_b1p5_'+nu_model[1]+'.root')
    fbdm_m05_b10 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m05_b10_'+nu_model[1]+'.root')     
    fbdm_m10_b10 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m10_b10_'+nu_model[1]+'.root')
    if nu_model[1] != '01a':
        fbdm_m20_b10 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m20_b10_'+nu_model[1]+'.root')
    fbdm_m40_b10 = ROOT.TFile.Open('/home/leoperes/ntuples_grid_newVertex/'+nu_model[1]+'_newVertex/bdm_m40_b10_'+nu_model[1]+'.root')

    if nu_model[1] != '01a':
        return [fatm, fbdm_m05_b1p1, fbdm_m10_b1p1, fbdm_m20_b1p1, fbdm_m40_b1p1, fbdm_m05_b1p5, fbdm_m10_b1p5, fbdm_m20_b1p5, fbdm_m40_b1p5, fbdm_m05_b10, fbdm_m10_b10, fbdm_m20_b10, fbdm_m40_b10]
    else:
        return [fatm, fbdm_m05_b1p1, fbdm_m10_b1p1, fbdm_m20_b1p1, fbdm_m40_b1p1, fbdm_m05_b1p5, fbdm_m10_b1p5, fbdm_m20_b1p5, fbdm_m40_b1p5, fbdm_m05_b10, fbdm_m10_b10, fbdm_m40_b10]


# %%

def GetNpArraysFromTrees(tree, branch_name):
    estimate = 3e6 #amount of numbers getting from branch
    tree.SetEstimate(int(estimate))
    result_hist = tree.Draw(branch_name, "", "goff")
    result = np.asarray(np.frombuffer(tree.GetV1(), dtype=np.float64, count=result_hist))
    result = result.copy()
    return result

def GetNpArraysFromTrees2(tree, branch_name):
    estimate = 3e8 #amount of numbers getting from branch
    tree.SetEstimate(int(estimate))
    result_hist = tree.Draw(branch_name, "", "goff")
    result = np.asarray(np.frombuffer(tree.GetV1(), count=result_hist))
    result = result.copy()
    return result


def GetBDTResponse(tree):
    
    bdtOutput = []
    # in order to start TMVA
    ROOT.TMVA.Tools.Instance()
    reader = ROOT.TMVA.Reader("!Color:!Silent")
    
    LongestTrack= array('f',[0])
    HighestTrackSummedADC= array('f',[0])
    PIDALongestTrack= array('f',[0])
    nTracks= array('f',[0])
    nShowers= array('f',[0])
    TotalMomentumP= array('f',[0])
    nSpacePoints= array('f',[0])
    #NPrimaryDaughters= array('f',[0])
    HighestShowerSummedADC= array('f',[0])
    #PrimaryPDGReco= array('f',[0])
    LargeShowerOpenAngle= array('f',[0])
    LongestShower= array('f',[0])
    CosThetaDetTotalMom= array('f',[0])
    CosPhiDetTotalMom= array('f',[0])
    FracTotalChargeLongTrack= array('f',[0])
    AvarageTrackLength= array('f',[0])
    CVN_NCScore= array('f',[0])
    EventRecoEnergy_Charge = array('f',[0])
    EventRecoEnergy_numu = array('f',[0])
    EventRecoEnergy_nue = array('f',[0])
    #event = array('f',[0])
    
    
    reader.AddVariable("LongestTrack", LongestTrack)
    reader.AddVariable("log(HighestTrackSummedADC)", HighestTrackSummedADC)
    reader.AddVariable("PIDALongestTrack", PIDALongestTrack)
    reader.AddVariable("nTracks", nTracks)
    reader.AddVariable("nShowers", nShowers)
    reader.AddVariable("TotalMomentumP", TotalMomentumP)
    reader.AddVariable("nSpacePoints", nSpacePoints)
    #reader.AddVariable("NPrimaryDaughters", NPrimaryDaughters)
    reader.AddVariable("log(HighestShowerSummedADC)", HighestShowerSummedADC)
    #reader.AddVariable("PrimaryPDGReco", PrimaryPDGReco)
    reader.AddVariable("LargeShowerOpenAngle", LargeShowerOpenAngle)
    reader.AddVariable("LongestShower", LongestShower)
    reader.AddVariable("CosThetaDetTotalMom", CosThetaDetTotalMom)
    reader.AddVariable("CosPhiDetTotalMom", CosPhiDetTotalMom)
    reader.AddVariable("FracTotalChargeLongTrack", FracTotalChargeLongTrack)
    reader.AddVariable("AvarageTrackLength", AvarageTrackLength)
    reader.AddVariable("CVN_NCScore", CVN_NCScore)
    reader.AddVariable("EventRecoEnergy_Charge", EventRecoEnergy_Charge)
    reader.AddVariable("EventRecoEnergy_numu", EventRecoEnergy_numu)
    reader.AddVariable("EventRecoEnergy_nue", EventRecoEnergy_nue)
    #reader.AddSpectator("event", event)
    
    reader.BookMVA("TMVAClassification","/home/leoperes/Dropbox/BoostedDM/Final_Analysis/dataset_v02/weights/TMVAClassification_BDTAtmCCNC.weights.xml")
    
    nentry = tree.GetEntries()
    
    for i in range(nentry):
        tree.GetEntry(i)
        #print(tree.NPrimaryDaughters)
        if (float(tree.CVN_NCScore) == -1):
                    
            LongestTrack[0] = float(tree.LongestTrack)
            HighestTrackSummedADC[0] = float(tree.HighestTrackSummedADC)
            PIDALongestTrack[0] = float(tree.PIDALongestTrack)
            nTracks[0] = float(tree.nTracks)
            nShowers[0] = float(tree.nShowers)
            TotalMomentumP[0] = float(tree.TotalMomentumP)
            nSpacePoints[0] = float(tree.nSpacePoints)
            #NPrimaryDaughters[0] = float(tree.NPrimaryDaughters[0])
            HighestShowerSummedADC[0] = float(tree.HighestShowerSummedADC)
            #PrimaryPDGReco[0] = float(tree.PrimaryPDGReco[0])
            LargeShowerOpenAngle[0] = float(tree.LargeShowerOpenAngle)
            LongestShower[0] = float(tree.LongestShower)
            CosThetaDetTotalMom[0] = float(tree.CosThetaDetTotalMom)
            CosPhiDetTotalMom[0] = float(tree.CosPhiDetTotalMom)
            FracTotalChargeLongTrack[0] = float(tree.FracTotalChargeLongTrack)
            AvarageTrackLength[0] = float(tree.AvarageTrackLength)
            CVN_NCScore[0] = float(tree.CVN_NCScore)
            EventRecoEnergy_Charge[0] = float(tree.EventRecoEnergy_Charge)
            EventRecoEnergy_numu[0] = float(tree.EventRecoEnergy_numu)
            EventRecoEnergy_nue[0] = float(tree.EventRecoEnergy_nue)
            #event[0] = float(tree.event)

            bdt = reader.EvaluateMVA("TMVAClassification")
            bdtOutput.append(bdt)
            
    return np.array(bdtOutput)

# %%
def CVNCut(CVN_CutProb,CVN_SignalReco,CVN_Bg,CosSun_SignalValidCVN,AtmNuCosSun):
    nSignalEvents = 0 
    nBGEvents = 0
    EventsSignalCut = CVN_SignalReco[CVN_SignalReco > CVN_CutProb]
    EventsBgCut = CVN_Bg[CVN_Bg > CVN_CutProb] 
    CosSunSignal_CVNCut = CosSun_SignalValidCVN[CVN_SignalReco > CVN_CutProb]
    CosSunBgCVNCut = AtmNuCosSun[CVN_Bg > CVN_CutProb]
    

    return CosSunSignal_CVNCut, CosSunBgCVNCut, EventsSignalCut, EventsBgCut

# %%

def BDTCut(BDT_Cut, BDT_Signal,BDT_Atm, CosSunSig_NoCVN, CosSunAtmNoCVN):
    BDT_SignalCut = BDT_Signal[BDT_Signal>BDT_Cut]
    BDT_AtmCut = BDT_Atm[BDT_Atm>BDT_Cut]
    CosSunSignal_BDTCut =  CosSunSig_NoCVN[BDT_Signal > BDT_Cut]
    CosSunAtm_BDTCut = CosSunAtmNoCVN[BDT_Atm > BDT_Cut]

    return CosSunSignal_BDTCut, CosSunAtm_BDTCut, BDT_SignalCut, BDT_AtmCut

# %%

def AngularCutBothSides(CVNScore_NC,BDTScore,CosCutLeft,CosCutRight, nSignalSimulatedEvts,ExpectedNumber10kty): 
    
    results = []
    SprimeMin = 999999999
    bestCutRight = 9999
    bestCutLeft = 9999
    bestEff = 9999
    bestBkg = 9999
    bestBkgErr = 999
    Sprime = 999
    CosSunSignal = []
    CosSunAtm = []
    
    CosSunSignalBDTCut, CosSunAtmBDTCut, BDTSignalCut, BDTAtmCut = BDTCut(BDTScore, BDTResponseSignal,BDTResponseAtm, CosSun_Signal_NoCVN, CosSun_Atm_NoCVN)
    CosSunSignalCVNCut, CosSunBgCVNCut, SignalEvts, BgEvts = CVNCut(CVNScore_NC, CVN_Signal_Valid, CVN_Atm_Valid, CosSun_Signal_wCVN, CosSun_Atm_wCVN)
    
    BackgroundScale = 4 * 10 * RatioRecoAtm *ExpectedNumber10kty /nSimulatedEvtsAll_atm
    # = 40kt * 10 years * reco/simulated ratio * # atm nu expected for 10kt y * inside/out cvn cut ratio / #simulated atm nu events 

    
    CosSunEvts = np.concatenate((CosSunSignalBDTCut,CosSunSignalCVNCut), axis=0)
    CosSunAtmEvts = np.concatenate((CosSunAtmBDTCut, CosSunBgCVNCut), axis=0)

    nReco = 0.0001
    nBG = 0.00001
    nRecoToTheRight = np.sum(CosCutRight < CosSunEvts)
    nRecoToTheLeft = np.sum(CosCutLeft > CosSunEvts)
    nReco = nRecoToTheRight + nRecoToTheLeft
            
    nBGToTheRight = np.sum(CosCutRight < CosSunAtmEvts)
    nBGToTheLeft = np.sum(CosCutLeft > CosSunAtmEvts)
    nBG = nBGToTheRight + nBGToTheLeft
    
    rReco = nReco/nSignalSimulatedEvts  
    bEvents = nBG*BackgroundScale
    
    #print(rReco,nReco,nSignalSimulatedEvts)
    Sprime = 25./ (2.*rReco) + math.sqrt( 25.*bEvents/ (rReco*rReco) + 625./(4.*rReco*rReco) )
    
    if Sprime < SprimeMin:
        SprimeMin = Sprime
        bestCutRight = CosCutRight
        bestCutLeft = CosCutLeft
        bestEff = rReco
        bestBkg = bEvents
        bestBkgErr = math.sqrt( nBG *BackgroundScale)
        BestCVNCut = CVNScore_NC
        BestBDTCut = BDTScore
        CosSunSignal = CosSunEvts
        CosSunAtm = CosSunAtmEvts
    results = [SprimeMin, bestCutLeft, bestCutRight, bestEff, bestBkg, bestBkgErr, CVNScore_NC, BDTScore, CosSunEvts, CosSunAtmEvts]
    return results


RatioRecoAtm = -1

Eff_Bkg_default = np.loadtxt('../BDT_CVN_Ang_MaxCVN/Eff_Bkg_index_00a.txt', delimiter=' ', usecols=[1,2,6,7], skiprows=1)

#%% 

for nc_id, nuclearmodel in enumerate(list_nuclearmodels):
    infiles_list = ReadNuclearModelSamples(nuclearmodel)
    for SAMPLE_INDEX in range(0,len(infiles_list)):
        intrees_reco = [lambda arg=infile: arg.Get("ana/Atm") for infile in infiles_list]
        intrees_simu = [lambda arg=infile: arg.Get("ana/AllEvents") for infile in infiles_list]
        reco_entries = [intree().GetEntries() for intree in intrees_reco]
        simu_entries = [intree().GetEntries() for intree in intrees_simu]
    ### Atmospheric neutrinos Angular Reconstruction w.r.t Sun
    TotalMomRecoRangeUnitVect_Reco = GetNpArraysFromTrees2(intrees_reco[0]()," TotalMomRecoRangeUnitVect")
    nSimulatedEvtsReco_atm = reco_entries[0]
    Reco_mom_Nu = np.reshape(TotalMomRecoRangeUnitVect_Reco, (nSimulatedEvtsReco_atm,3))
    Sun_Positions = np.loadtxt('../../background_sun_pos.dat', delimiter='\t', usecols=(0,1,2))


    hist_cos_reco = []
    for index, atmevt in enumerate(Reco_mom_Nu):
        indices = np.random.randint(0, len(Sun_Positions), size=1)
        # Use the sampled indices to select elements from the array
        sample_sunpos = Sun_Positions[indices]
        for sunpos in sample_sunpos:
            hist_cos_reco.append(np.sum(atmevt*sunpos))

    plt.figure(dpi=100)
    plt.hist(hist_cos_reco, bins = 20,histtype = 'step')
    #plt.title(f'index number evt: {index}')
    plt.ylabel('Number of Events')
    plt.xlabel(r'$cos(\theta_{Sun, Reco})$',fontsize = 17)
    plt.savefig(nuclearmodel[0]+'/AngDist_Atmospheric_wrt_'+nuclearmodel[0]+'.pdf', format='pdf', dpi=300)

    ExpectedNumber10kty = [2495.98, 2586.47, 2401.88]

    ExpectedBkg = 0
    if nc_id % 3 == 0:
        ExpectedBkg = ExpectedNumber10kty[0]
    if nc_id % 3 == 1:
        ExpectedBkg = ExpectedNumber10kty[1]
    if nc_id % 3 == 2:
        ExpectedBkg = ExpectedNumber10kty[2]


    nSimulatedEvtsAll_atm = simu_entries[0]
    RatioRecoAtm = nSimulatedEvtsReco_atm/nSimulatedEvtsAll_atm

    CVN_Atm = GetNpArraysFromTrees(intrees_reco[0](),"CVN_NCScore")
    BDTResponseAtm = GetBDTResponse(intrees_reco[0]())
    CosSun_Atm = np.array(hist_cos_reco)

    CVN_Atm_Valid = CVN_Atm[CVN_Atm>-1]
    CosSun_Atm_wCVN = CosSun_Atm[CVN_Atm > -1]
    CosSun_Atm_NoCVN = CosSun_Atm[CVN_Atm == -1]

    print(CosSun_Atm_NoCVN.size)
    print(BDTResponseAtm.size)

    Sensitivity_Info = open(nuclearmodel[0]+'/Sensitivity_Info_'+nuclearmodel[1]+'.txt', "a")
    Sensitivity_results = open(nuclearmodel[0]+'/Sensitivity_results_'+nuclearmodel[1]+'.txt',"a")
    Eff_Bkg_index =open(nuclearmodel[0]+'/Eff_Bkg_index_'+nuclearmodel[1]+'.txt',"a")
    CVN_Cuts = np.linspace(0.2,1.00,70)
    BDT_Cuts = np.linspace(-0.2,0.7,25)

    Sensitivity_Info.write("################# SAMPLE INFO #######################"+"\n")
    Sensitivity_Info.write("\n")
    Sensitivity_Info.write("Number of Atmospheric Neutrinos Events Simulated: " +str(nSimulatedEvtsAll_atm)+"\n")
    Sensitivity_Info.write("Number of Atmospheric Neutrinos Events Reconstructed: " +str(nSimulatedEvtsReco_atm)+"\n")
    Sensitivity_Info.write("Ratio of Atmospheric Neutrinos Events Reconstructed: " +str(RatioRecoAtm)+"\n")
    Sensitivity_Info.write("\n")

    resultsTOtxt(CVN_Atm, nuclearmodel[0]+'/CVN_Atm_'+nuclearmodel[1]+'.txt')
    resultsTOtxt(BDTResponseAtm, nuclearmodel[0]+'/BDT_Atm_'+nuclearmodel[1]+'.txt')
    resultsTOtxt(CosSun_Atm, nuclearmodel[0]+'/CosSun_Atm_'+nuclearmodel[1]+'.txt')

    Eff_Bkg_index.write("SigStrength\tNegCosCut\tPosCosCut\tbestEff\tBkgExpect\tBkgError\tCVNCut\tBDTCut\n")

    for index, sig_tree in enumerate(intrees_reco[1:]):

        CVN_Signal = GetNpArraysFromTrees(sig_tree(),"CVN_NCScore")
        CosSun_Signal = GetNpArraysFromTrees(sig_tree(),"DiffCosAngleTotalMom")
        BDTResponseSignal = GetBDTResponse(sig_tree())

        CVN_Signal_Valid = CVN_Signal[CVN_Signal>-1]
        CosSun_Signal_wCVN = CosSun_Signal[CVN_Signal> -1]
        CosSun_Signal_NoCVN = CosSun_Signal[CVN_Signal == -1]


        bestResultsTwoAngCuts = []
        SpMinTwoAngCuts = 99999999.9
        bestCVNCutTwoCut = -3
        
        CVNScore = Eff_Bkg_default[index,2]
        BDT_Score = Eff_Bkg_default[index,3]
        CosCutLeft = Eff_Bkg_default[index,0]
        CosCutRight = Eff_Bkg_default[index,1]
        nSignalSimulatedEvts = simu_entries[index+1]

        Sensitivity_Info.write("Sample: "+str(sig_tree().GetCurrentFile().GetName()[28:-5])+"\n")
        Sensitivity_Info.write("Number of Boosted DM Events Simulated: " +str(simu_entries[index+1])+"\n")
        Sensitivity_Info.write("Number of Boosted DM Events Reconstructed: " + str(reco_entries[index+1])+"\n")
        Sensitivity_Info.write("Ratio of Boosted DM Events Reconstructed: " +str(float(reco_entries[index+1])/simu_entries[index+1])+"\n")
        Sensitivity_Info.write("\n")

        Sensitivity_results.write("Sample: "+str(sig_tree().GetCurrentFile().GetName()[28:-5])+"\n")
        Sensitivity_results.write("SigStrength\tNegCosCut\tPosCosCut\tbestEff\tBkgExpect\tBkgError\tCVNCut\tBDTCut\n")
        resultsTwoAngCuts = AngularCutBothSides(CVNScore, BDT_Score, CosCutLeft, CosCutRight, nSignalSimulatedEvts,ExpectedBkg)
        
        if resultsTwoAngCuts[0] < SpMinTwoAngCuts:
            bestResultsTwoAngCuts = resultsTwoAngCuts
            bestCVNCutTwoCut = CVNScore
            SpMinTwoAngCuts = resultsTwoAngCuts[0]
            Sensitivity_results.write(str(bestResultsTwoAngCuts[0])+"\t"+str(bestResultsTwoAngCuts[1])+"\t"+str(bestResultsTwoAngCuts[2])+"\t"+str(bestResultsTwoAngCuts[3])+"\t"+str(bestResultsTwoAngCuts[4])+"\t"+str(bestResultsTwoAngCuts[5])+"\t"+str(bestResultsTwoAngCuts[6])+"\t"+str(bestResultsTwoAngCuts[7])+"\n")


        Sensitivity_results.write(str(" ======= BEST CUTS ========")+"\n")
        Sensitivity_results.write(str(bestResultsTwoAngCuts[0])+"\t"+str(bestResultsTwoAngCuts[1])+"\t"+str(bestResultsTwoAngCuts[2])+"\t"+str(bestResultsTwoAngCuts[3])+"\t"+str(bestResultsTwoAngCuts[4])+"\t"+str(bestResultsTwoAngCuts[5])+"\t"+str(bestResultsTwoAngCuts[6])+"\t"+str(bestResultsTwoAngCuts[7])+"\n")   
        np.savetxt(Eff_Bkg_index, np.array(bestResultsTwoAngCuts[0:8]).flatten(), fmt="%.3f", newline = " ",delimiter=', ')
        Eff_Bkg_index.write("\n")
        Sensitivity_results.write("\n")
        print('\n')
        print(index)
        print("################# BEST ANGULAR AND CVN CUTS INFO #######################")
        print("Optimal Signal Strength: " + '{:.0f}'.format(bestResultsTwoAngCuts[0]))
        print("Optimal CVN Cut: " +'{:.3f}'.format(bestResultsTwoAngCuts[6]))
        print("Optimal BDT Cut: " +'{:.3f}'.format(bestResultsTwoAngCuts[7]))
        print("Optimal Positive Cossine Angular Cut: "  + '{:.3f}'.format(bestResultsTwoAngCuts[2]))
        print("Optimal Negative Cossine Angular Cut: " +  '{:.3f}'.format(bestResultsTwoAngCuts[1]))
        print("Signal Efficiency: " + '{:.3f}'.format(bestResultsTwoAngCuts[3]))
        print("")
        print("Number of expected Atm Nu events: " + '{:.1f}'.format(bestResultsTwoAngCuts[4]) + ", statistical uncertainty: " + '{:.1f}'.format(bestResultsTwoAngCuts[5]))
        print('\n')
        #h.write('{:.3f}'.format(bestResultsTwoAngCuts[3]),'{:.3f}'.format(bestResultsTwoAngCuts[4]),'{:.1d}'.format(index))
    
        resultsTOtxt(bestResultsTwoAngCuts[8], nuclearmodel[0]+'/CosSunSignalAfterCuts_'+listsamples[index]+'.txt')
        resultsTOtxt(bestResultsTwoAngCuts[9], nuclearmodel[0]+'/CosSunAtmAfterCuts_'+listsamples[index]+'.txt')
        resultsTOtxt(CVN_Signal, nuclearmodel[0]+'/CVN_'+listsamples[index]+'.txt')
        resultsTOtxt(BDTResponseSignal, nuclearmodel[0]+'/BDT_'+listsamples[index]+'.txt')
        resultsTOtxt(CosSun_Signal, nuclearmodel[0]+'/CosSun_'+listsamples[index]+'.txt')

    Sensitivity_Info.close()
    Sensitivity_results.close()
    Eff_Bkg_index.close()

# %%



