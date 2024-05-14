#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p1_m40()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 15:58:49 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-3.125e-11,-0.0002085326,2.8125e-10,0.001876794);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5dacbbfde0__19 = new TH1D("frame_5e5dacbbfde0__19","Posterior probability of parameter \"gZ8\"",100,0,2.5e-10);
   frame_5e5dacbbfde0__19->SetBinContent(1,0.001668261);
   frame_5e5dacbbfde0__19->SetMaximum(0.001668261);
   frame_5e5dacbbfde0__19->SetEntries(2);
   frame_5e5dacbbfde0__19->SetDirectory(nullptr);
   frame_5e5dacbbfde0__19->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5dacbbfde0__19->SetLineColor(ci);
   frame_5e5dacbbfde0__19->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dacbbfde0__19->GetXaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__19->GetXaxis()->SetTitleOffset(1);
   frame_5e5dacbbfde0__19->GetXaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__19->GetYaxis()->SetTitle("posterior function");
   frame_5e5dacbbfde0__19->GetYaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__19->GetYaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__19->GetZaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__19->GetZaxis()->SetTitleOffset(1);
   frame_5e5dacbbfde0__19->GetZaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__19->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx7[104] = { -1.325758e-15, 0, 1.325758e-12, 2.651515e-12, 3.977273e-12, 5.30303e-12, 6.628788e-12, 7.954545e-12, 9.280303e-12, 1.060606e-11, 1.193182e-11, 1.325758e-11, 1.458333e-11, 1.590909e-11, 1.723485e-11, 1.856061e-11, 1.988636e-11,
   2.121212e-11, 2.253788e-11, 2.386364e-11, 2.518939e-11, 2.651515e-11, 2.784091e-11, 2.916667e-11, 3.049242e-11, 3.181818e-11, 3.314394e-11, 3.44697e-11, 3.579545e-11, 3.712121e-11, 3.844697e-11, 3.977273e-11, 4.109848e-11,
   4.242424e-11, 4.375e-11, 4.507576e-11, 4.640152e-11, 4.772727e-11, 4.905303e-11, 5.037879e-11, 5.170455e-11, 5.30303e-11, 5.435606e-11, 5.568182e-11, 5.700758e-11, 5.833333e-11, 5.965909e-11, 6.098485e-11, 6.231061e-11,
   6.363636e-11, 6.496212e-11, 6.628788e-11, 6.761364e-11, 6.893939e-11, 7.026515e-11, 7.159091e-11, 7.291667e-11, 7.424242e-11, 7.556818e-11, 7.689394e-11, 7.82197e-11, 7.954545e-11, 8.087121e-11, 8.219697e-11, 8.352273e-11,
   8.484848e-11, 8.617424e-11, 8.75e-11, 8.882576e-11, 9.015152e-11, 9.147727e-11, 9.280303e-11, 9.412879e-11, 9.545455e-11, 9.67803e-11, 9.810606e-11, 9.943182e-11, 1.007576e-10, 1.020833e-10, 1.034091e-10, 1.047348e-10,
   1.060606e-10, 1.073864e-10, 1.087121e-10, 1.100379e-10, 1.113636e-10, 1.126894e-10, 1.140152e-10, 1.153409e-10, 1.166667e-10, 1.179924e-10, 1.193182e-10, 1.206439e-10, 1.219697e-10, 1.232955e-10, 1.246212e-10, 1.25947e-10,
   1.272727e-10, 1.285985e-10, 1.299242e-10, 1.3125e-10, 1.325758e-10, 1.325758e-10, 1.325771e-10 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy7[104] = { 0, 0.001588761, 0.001588792, 0.001588744, 0.001588081, 0.00158726, 0.001585905, 0.001584313, 0.00158227, 0.001579915, 0.001577189, 0.001574077, 0.001570675, 0.001566817, 0.00156275, 0.001558158, 0.001553434,
   0.001548124, 0.00154274, 0.001536745, 0.001530662, 0.001524053, 0.00151729, 0.001510085, 0.001502664, 0.001494879, 0.001486823, 0.00147848, 0.001469814, 0.001460932, 0.001451681, 0.001442283, 0.001432475,
   0.001422582, 0.001412246, 0.001401859, 0.001391053, 0.001380176, 0.001368949, 0.00135761, 0.001345988, 0.00133422, 0.001322232, 0.00131007, 0.001297742, 0.001285218, 0.001272577, 0.001259723, 0.001246796,
   0.001233641, 0.001220449, 0.001207048, 0.001193622, 0.001180005, 0.001166353, 0.001152559, 0.001138718, 0.001124771, 0.001110775, 0.001096713, 0.001082601, 0.001068448, 0.001054247, 0.001040021, 0.00102576,
   0.00101149, 0.0009972022, 0.0009829123, 0.0009686261, 0.0009543429, 0.000940082, 0.0009258338, 0.0009116283, 0.0008974469, 0.0008833119, 0.0008692156, 0.0008551651, 0.0008411834, 0.0008272531, 0.0008134109, 0.0007996092,
   0.0007859089, 0.0007722341, 0.0007587317, 0.0007452506, 0.0007319447, 0.0007186646, 0.0007055396, 0.0006924684, 0.0006795527, 0.0006667109, 0.0006539942, 0.0006413723, 0.0006288509, 0.0006164528, 0.0006041367, 0.0005919332,
   0.0005797747, 0.0005677295, 0.0005557076, 0.000543775, 0.0005318596, 0.0005318596, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx7,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy7);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-1.325917e-11,1.458349e-10);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetMaximum(0.001747672);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]7);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx8[106] = { -2.5025e-12, -2.5e-12, 0, 2.5e-12, 5e-12, 7.5e-12, 1e-11, 1.25e-11, 1.5e-11, 1.75e-11, 2e-11, 2.25e-11, 2.5e-11, 2.75e-11, 3e-11, 3.25e-11, 3.5e-11,
   3.75e-11, 4e-11, 4.25e-11, 4.5e-11, 4.75e-11, 5e-11, 5.25e-11, 5.5e-11, 5.75e-11, 6e-11, 6.25e-11, 6.5e-11, 6.75e-11, 7e-11, 7.25e-11, 7.5e-11,
   7.75e-11, 8e-11, 8.25e-11, 8.5e-11, 8.75e-11, 9e-11, 9.25e-11, 9.5e-11, 9.75e-11, 1e-10, 1.025e-10, 1.05e-10, 1.075e-10, 1.1e-10, 1.125e-10, 1.15e-10,
   1.175e-10, 1.2e-10, 1.225e-10, 1.25e-10, 1.275e-10, 1.3e-10, 1.325e-10, 1.35e-10, 1.375e-10, 1.4e-10, 1.425e-10, 1.45e-10, 1.475e-10, 1.5e-10, 1.525e-10, 1.55e-10,
   1.575e-10, 1.6e-10, 1.625e-10, 1.65e-10, 1.675e-10, 1.7e-10, 1.725e-10, 1.75e-10, 1.775e-10, 1.8e-10, 1.825e-10, 1.85e-10, 1.875e-10, 1.9e-10, 1.925e-10, 1.95e-10,
   1.975e-10, 2e-10, 2.025e-10, 2.05e-10, 2.075e-10, 2.1e-10, 2.125e-10, 2.15e-10, 2.175e-10, 2.2e-10, 2.225e-10, 2.25e-10, 2.275e-10, 2.3e-10, 2.325e-10, 2.35e-10,
   2.375e-10, 2.4e-10, 2.425e-10, 2.45e-10, 2.475e-10, 2.5e-10, 2.5e-10, 2.525e-10, 2.525025e-10 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy8[106] = { 0, 0.001588761, 0.001588761, 0.00158882, 0.00158757, 0.001585014, 0.001581161, 0.00157602, 0.001569606, 0.001561936, 0.00155303, 0.001542911, 0.001531606, 0.001519143, 0.001505555, 0.001490876, 0.001475143,
   0.001458394, 0.001440672, 0.001422017, 0.001402476, 0.0013821, 0.00136093, 0.001339015, 0.00131641, 0.001293164, 0.001269326, 0.001244949, 0.001220072, 0.001194789, 0.001169111, 0.001143101, 0.001116802,
   0.001090285, 0.001063596, 0.001036769, 0.001009859, 0.0009829123, 0.0009559727, 0.0009290808, 0.0009022932, 0.0008756386, 0.0008491435, 0.000822875, 0.0007968488, 0.0007710619, 0.0007456308, 0.0007205396, 0.0006957895,
   0.0006714343, 0.0006474541, 0.0006238424, 0.0006006178, 0.0005776904, 0.0005550207, 0.0005325293, 0.0005101337, 0.0004877554, 0.0004653196, 0.0004427654, 0.0004200602, 0.0003971943, 0.0003741959, 0.0003511112, 0.0003279503,
   0.0003050166, 0.000282294, 0.0002599304, 0.0002380752, 0.0002168724, 0.0001964576, 0.000176952, 0.0001584592, 0.0001410725, 0.0001248413, 0.0001098131, 9.600307e-05, 8.340884e-05, 7.201214e-05, 6.177488e-05, 5.26481e-05,
   4.457201e-05, 3.747838e-05, 3.129391e-05, 2.594243e-05, 2.134655e-05, 1.74298e-05, 1.411775e-05, 1.133929e-05, 9.027455e-06, 7.117667e-06, 5.55962e-06, 4.296415e-06, 3.282396e-06, 2.476836e-06, 1.84399e-06, 1.352697e-06,
   9.762454e-07, 6.918607e-07, 4.806453e-07, 3.26516e-07, 2.163612e-07, 1.395142e-07, 1.395142e-07, 1.395142e-07, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx8,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy8);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-2.8003e-11,2.78003e-10);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetMaximum(0.001747702);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]8);
   
   graph->Draw("l");
   
   TH1D *frame_5e5dacbbfde0__20 = new TH1D("frame_5e5dacbbfde0__20","Posterior probability of parameter \"gZ8\"",100,0,2.5e-10);
   frame_5e5dacbbfde0__20->SetBinContent(1,0.001668261);
   frame_5e5dacbbfde0__20->SetMaximum(0.001668261);
   frame_5e5dacbbfde0__20->SetEntries(2);
   frame_5e5dacbbfde0__20->SetDirectory(nullptr);
   frame_5e5dacbbfde0__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5dacbbfde0__20->SetLineColor(ci);
   frame_5e5dacbbfde0__20->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dacbbfde0__20->GetXaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__20->GetXaxis()->SetTitleOffset(1);
   frame_5e5dacbbfde0__20->GetXaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__20->GetYaxis()->SetTitle("posterior function");
   frame_5e5dacbbfde0__20->GetYaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__20->GetYaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__20->GetZaxis()->SetLabelFont(42);
   frame_5e5dacbbfde0__20->GetZaxis()->SetTitleOffset(1);
   frame_5e5dacbbfde0__20->GetZaxis()->SetTitleFont(42);
   frame_5e5dacbbfde0__20->Draw("AXISSAME");
   
   TPaveText *pt = new TPaveText(0.1619198,0.9344958,0.8380802,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Posterior probability of parameter \"gZ8\"");
   pt->Draw();
   posterior->Modified();
   posterior->cd();
   posterior->SetSelected(posterior);
}
