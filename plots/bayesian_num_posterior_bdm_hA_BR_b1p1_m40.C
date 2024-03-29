#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p1_m40()
{
//=========Macro generated from canvas: posterior/
//=========  (Wed Feb 21 16:30:10 2024) by ROOT version 6.26/10
   TCanvas *posterior = new TCanvas("posterior", "",10,47,700,500);
   posterior->Range(-3.124888e-11,-0.1820718,2.812499e-10,1.638646);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5647f3688550__19 = new TH1D("frame_5647f3688550__19","Posterior probability of parameter \"gZ8\"",100,1e-15,2.5e-10);
   frame_5647f3688550__19->SetBinContent(1,1.456574);
   frame_5647f3688550__19->SetMaximum(1.456574);
   frame_5647f3688550__19->SetEntries(1);
   frame_5647f3688550__19->SetDirectory(0);
   frame_5647f3688550__19->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5647f3688550__19->SetLineColor(ci);
   frame_5647f3688550__19->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5647f3688550__19->GetXaxis()->SetLabelFont(42);
   frame_5647f3688550__19->GetXaxis()->SetTitleOffset(1);
   frame_5647f3688550__19->GetXaxis()->SetTitleFont(42);
   frame_5647f3688550__19->GetYaxis()->SetTitle("posterior function");
   frame_5647f3688550__19->GetYaxis()->SetLabelFont(42);
   frame_5647f3688550__19->GetYaxis()->SetTitleFont(42);
   frame_5647f3688550__19->GetZaxis()->SetLabelFont(42);
   frame_5647f3688550__19->GetZaxis()->SetTitleOffset(1);
   frame_5647f3688550__19->GetZaxis()->SetTitleFont(42);
   frame_5647f3688550__19->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx7[104] = {
   1.540438e-16,
   1e-15,
   8.469562e-13,
   1.692912e-12,
   2.538869e-12,
   3.384825e-12,
   4.230781e-12,
   5.076737e-12,
   5.922693e-12,
   6.76865e-12,
   7.614606e-12,
   8.460562e-12,
   9.306518e-12,
   1.015247e-11,
   1.099843e-11,
   1.184439e-11,
   1.269034e-11,
   1.35363e-11,
   1.438226e-11,
   1.522821e-11,
   1.607417e-11,
   1.692012e-11,
   1.776608e-11,
   1.861204e-11,
   1.945799e-11,
   2.030395e-11,
   2.114991e-11,
   2.199586e-11,
   2.284182e-11,
   2.368777e-11,
   2.453373e-11,
   2.537969e-11,
   2.622564e-11,
   2.70716e-11,
   2.791755e-11,
   2.876351e-11,
   2.960947e-11,
   3.045542e-11,
   3.130138e-11,
   3.214734e-11,
   3.299329e-11,
   3.383925e-11,
   3.46852e-11,
   3.553116e-11,
   3.637712e-11,
   3.722307e-11,
   3.806903e-11,
   3.891499e-11,
   3.976094e-11,
   4.06069e-11,
   4.145285e-11,
   4.229881e-11,
   4.314477e-11,
   4.399072e-11,
   4.483668e-11,
   4.568264e-11,
   4.652859e-11,
   4.737455e-11,
   4.82205e-11,
   4.906646e-11,
   4.991242e-11,
   5.075837e-11,
   5.160433e-11,
   5.245029e-11,
   5.329624e-11,
   5.41422e-11,
   5.498815e-11,
   5.583411e-11,
   5.668007e-11,
   5.752602e-11,
   5.837198e-11,
   5.921793e-11,
   6.006389e-11,
   6.090985e-11,
   6.17558e-11,
   6.260176e-11,
   6.344772e-11,
   6.429367e-11,
   6.513963e-11,
   6.598558e-11,
   6.683154e-11,
   6.76775e-11,
   6.852345e-11,
   6.936941e-11,
   7.021537e-11,
   7.106132e-11,
   7.190728e-11,
   7.275323e-11,
   7.359919e-11,
   7.444515e-11,
   7.52911e-11,
   7.613706e-11,
   7.698302e-11,
   7.782897e-11,
   7.867493e-11,
   7.952088e-11,
   8.036684e-11,
   8.12128e-11,
   8.205875e-11,
   8.290471e-11,
   8.375066e-11,
   8.459662e-11,
   8.459662e-11,
   8.459747e-11};
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy7[104] = {
   0,
   1.341301,
   1.345116,
   1.348815,
   1.352396,
   1.355758,
   1.358985,
   1.362089,
   1.364973,
   1.367705,
   1.370307,
   1.372689,
   1.374901,
   1.376977,
   1.378836,
   1.380506,
   1.382034,
   1.383348,
   1.384453,
   1.385409,
   1.386155,
   1.386677,
   1.387048,
   1.387214,
   1.38713,
   1.386889,
   1.386455,
   1.38575,
   1.384885,
   1.383835,
   1.382495,
   1.38099,
   1.379312,
   1.377323,
   1.375167,
   1.372844,
   1.370202,
   1.367385,
   1.364399,
   1.361105,
   1.35762,
   1.353964,
   1.350016,
   1.34586,
   1.341531,
   1.336923,
   1.332094,
   1.327094,
   1.321829,
   1.158115,
   0.9847816,
   0.9807086,
   0.9764604,
   0.9111536,
   0.6917322,
   0.6445445,
   0.6396493,
   0.6364495,
   0.4547897,
   0.3206971,
   0.3191163,
   0.317475,
   0.3157988,
   0.3140838,
   0.3123066,
   0.3104953,
   0.3086489,
   0.3067391,
   0.3047962,
   0.3080867,
   0.4824762,
   0.7745509,
   1.132357,
   1.122024,
   1.111545,
   1.100941,
   1.090132,
   1.079175,
   1.068101,
   1.056847,
   1.045452,
   1.033952,
   1.022297,
   1.010506,
   0.9986204,
   0.9866038,
   0.974463,
   0.9622409,
   0.9499116,
   0.9374677,
   0.9249547,
   0.9123575,
   0.8996616,
   0.8869103,
   0.8740958,
   0.8611991,
   0.8482612,
   0.8352799,
   0.8222362,
   0.8091661,
   0.7960703,
   0.7829526,
   0.7829526,
   0};
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx7,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy7);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,0,9.30572e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetMaximum(1.525935);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB7->SetDirectory(0);
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
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx8[111] = {
   -2.50149e-12,
   -2.49899e-12,
   1e-15,
   2.50099e-12,
   5.00098e-12,
   7.50097e-12,
   1.000096e-11,
   1.250095e-11,
   1.500094e-11,
   1.750093e-11,
   2.000092e-11,
   2.250091e-11,
   2.50009e-11,
   2.750089e-11,
   3.000088e-11,
   3.250087e-11,
   3.500086e-11,
   3.750085e-11,
   4.000084e-11,
   4.125084e-11,
   4.250083e-11,
   4.375083e-11,
   4.500082e-11,
   4.625082e-11,
   4.750081e-11,
   4.875081e-11,
   5.00008e-11,
   5.250079e-11,
   5.500078e-11,
   5.750077e-11,
   5.875076e-11,
   6.000076e-11,
   6.250075e-11,
   6.500074e-11,
   6.750073e-11,
   7.000072e-11,
   7.250071e-11,
   7.50007e-11,
   7.750069e-11,
   8.000068e-11,
   8.250067e-11,
   8.500066e-11,
   8.750065e-11,
   9.000064e-11,
   9.250063e-11,
   9.500062e-11,
   9.750061e-11,
   1.000006e-10,
   1.025006e-10,
   1.050006e-10,
   1.075006e-10,
   1.100006e-10,
   1.125006e-10,
   1.150005e-10,
   1.175005e-10,
   1.200005e-10,
   1.225005e-10,
   1.250005e-10,
   1.275005e-10,
   1.300005e-10,
   1.325005e-10,
   1.350005e-10,
   1.375005e-10,
   1.400004e-10,
   1.425004e-10,
   1.450004e-10,
   1.475004e-10,
   1.500004e-10,
   1.525004e-10,
   1.550004e-10,
   1.575004e-10,
   1.600004e-10,
   1.625004e-10,
   1.650003e-10,
   1.675003e-10,
   1.700003e-10,
   1.725003e-10,
   1.750003e-10,
   1.775003e-10,
   1.800003e-10,
   1.825003e-10,
   1.850003e-10,
   1.875003e-10,
   1.900002e-10,
   1.925002e-10,
   1.950002e-10,
   1.975002e-10,
   2.000002e-10,
   2.025002e-10,
   2.050002e-10,
   2.075002e-10,
   2.100002e-10,
   2.125002e-10,
   2.150001e-10,
   2.175001e-10,
   2.200001e-10,
   2.225001e-10,
   2.250001e-10,
   2.275001e-10,
   2.300001e-10,
   2.325001e-10,
   2.350001e-10,
   2.375001e-10,
   2.4e-10,
   2.425e-10,
   2.45e-10,
   2.475e-10,
   2.5e-10,
   2.5e-10,
   2.525e-10,
   2.525025e-10};
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy8[111] = {
   0,
   1.341301,
   1.341301,
   1.352245,
   1.361831,
   1.369987,
   1.376645,
   1.381739,
   1.385209,
   1.386996,
   1.387045,
   1.385308,
   1.381742,
   1.376309,
   1.368979,
   1.359729,
   1.348542,
   1.33541,
   1.320336,
   0.9857543,
   0.979736,
   0.9733776,
   0.6491579,
   0.6407,
   0.6359719,
   0.3212869,
   0.3189511,
   0.3139814,
   0.3086213,
   0.302881,
   0.5605611,
   1.133128,
   1.102232,
   1.069948,
   1.036387,
   1.001669,
   0.9659212,
   0.9292791,
   0.8918831,
   0.85388,
   0.8154208,
   0.7766644,
   0.7377626,
   0.6988758,
   0.6601566,
   0.621768,
   0.5838528,
   0.5465557,
   0.5100281,
   0.4743901,
   0.4397691,
   0.406275,
   0.3740126,
   0.3430687,
   0.313519,
   0.2854269,
   0.2588423,
   0.2337954,
   0.2103166,
   0.1884037,
   0.1680555,
   0.149252,
   0.1319622,
   0.116146,
   0.1017526,
   0.08872299,
   0.0769901,
   0.06645873,
   0.05712429,
   0.04883604,
   0.04153683,
   0.03514497,
   0.02958084,
   0.02476539,
   0.02062226,
   0.01707897,
   0.01406687,
   0.01152197,
   0.009384813,
   0.00760112,
   0.006121573,
   0.004901913,
   0.003902736,
   0.003089255,
   0.002431356,
   0.001901883,
   0.001478929,
   0.001143269,
   0.0008783357,
   0.000670605,
   0.0005087224,
   0.0003834953,
   0.0002871444,
   0.0002135746,
   0.0001577456,
   0.0001156838,
   8.421436e-05,
   6.085923e-05,
   4.364685e-05,
   3.105851e-05,
   2.192658e-05,
   1.535578e-05,
   1.066681e-05,
   7.348947e-06,
   5.021284e-06,
   3.402433e-06,
   2.286335e-06,
   1.523881e-06,
   1.523881e-06,
   1.523881e-06,
   0};
   graph = new TGraph(111,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx8,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy8);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",111,-2.800189e-11,2.780029e-10);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetMaximum(1.52575);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB8->SetDirectory(0);
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
   
   TH1D *frame_5647f3688550__20 = new TH1D("frame_5647f3688550__20","Posterior probability of parameter \"gZ8\"",100,1e-15,2.5e-10);
   frame_5647f3688550__20->SetBinContent(1,1.456574);
   frame_5647f3688550__20->SetMaximum(1.456574);
   frame_5647f3688550__20->SetEntries(1);
   frame_5647f3688550__20->SetDirectory(0);
   frame_5647f3688550__20->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5647f3688550__20->SetLineColor(ci);
   frame_5647f3688550__20->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5647f3688550__20->GetXaxis()->SetLabelFont(42);
   frame_5647f3688550__20->GetXaxis()->SetTitleOffset(1);
   frame_5647f3688550__20->GetXaxis()->SetTitleFont(42);
   frame_5647f3688550__20->GetYaxis()->SetTitle("posterior function");
   frame_5647f3688550__20->GetYaxis()->SetLabelFont(42);
   frame_5647f3688550__20->GetYaxis()->SetTitleFont(42);
   frame_5647f3688550__20->GetZaxis()->SetLabelFont(42);
   frame_5647f3688550__20->GetZaxis()->SetTitleOffset(1);
   frame_5647f3688550__20->GetZaxis()->SetTitleFont(42);
   frame_5647f3688550__20->Draw("AXISSAME");
   
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
