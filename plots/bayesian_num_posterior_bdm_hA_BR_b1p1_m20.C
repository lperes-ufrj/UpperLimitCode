#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p1_m20()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 15:56:41 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-8.750001e-12,-0.0002151633,7.875e-11,0.00193647);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5dabe20690__14 = new TH1D("frame_5e5dabe20690__14","Posterior probability of parameter \"gZ8\"",100,0,7e-11);
   frame_5e5dabe20690__14->SetBinContent(1,0.001721307);
   frame_5e5dabe20690__14->SetMaximum(0.001721307);
   frame_5e5dabe20690__14->SetEntries(2);
   frame_5e5dabe20690__14->SetDirectory(nullptr);
   frame_5e5dabe20690__14->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5dabe20690__14->SetLineColor(ci);
   frame_5e5dabe20690__14->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dabe20690__14->GetXaxis()->SetLabelFont(42);
   frame_5e5dabe20690__14->GetXaxis()->SetTitleOffset(1);
   frame_5e5dabe20690__14->GetXaxis()->SetTitleFont(42);
   frame_5e5dabe20690__14->GetYaxis()->SetTitle("posterior function");
   frame_5e5dabe20690__14->GetYaxis()->SetLabelFont(42);
   frame_5e5dabe20690__14->GetYaxis()->SetTitleFont(42);
   frame_5e5dabe20690__14->GetZaxis()->SetLabelFont(42);
   frame_5e5dabe20690__14->GetZaxis()->SetTitleOffset(1);
   frame_5e5dabe20690__14->GetZaxis()->SetTitleFont(42);
   frame_5e5dabe20690__14->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx5[104] = { -4.348485e-16, 0, 4.348485e-13, 8.69697e-13, 1.304545e-12, 1.739394e-12, 2.174242e-12, 2.609091e-12, 3.043939e-12, 3.478788e-12, 3.913636e-12, 4.348485e-12, 4.783333e-12, 5.218182e-12, 5.65303e-12, 6.087879e-12, 6.522727e-12,
   6.957576e-12, 7.392424e-12, 7.827273e-12, 8.262121e-12, 8.69697e-12, 9.131818e-12, 9.566667e-12, 1.000152e-11, 1.043636e-11, 1.087121e-11, 1.130606e-11, 1.174091e-11, 1.217576e-11, 1.261061e-11, 1.304545e-11, 1.34803e-11,
   1.391515e-11, 1.435e-11, 1.478485e-11, 1.52197e-11, 1.565455e-11, 1.608939e-11, 1.652424e-11, 1.695909e-11, 1.739394e-11, 1.782879e-11, 1.826364e-11, 1.869848e-11, 1.913333e-11, 1.956818e-11, 2.000303e-11, 2.043788e-11,
   2.087273e-11, 2.130758e-11, 2.174242e-11, 2.217727e-11, 2.261212e-11, 2.304697e-11, 2.348182e-11, 2.391667e-11, 2.435152e-11, 2.478636e-11, 2.522121e-11, 2.565606e-11, 2.609091e-11, 2.652576e-11, 2.696061e-11, 2.739545e-11,
   2.78303e-11, 2.826515e-11, 2.87e-11, 2.913485e-11, 2.95697e-11, 3.000455e-11, 3.043939e-11, 3.087424e-11, 3.130909e-11, 3.174394e-11, 3.217879e-11, 3.261364e-11, 3.304848e-11, 3.348333e-11, 3.391818e-11, 3.435303e-11,
   3.478788e-11, 3.522273e-11, 3.565758e-11, 3.609242e-11, 3.652727e-11, 3.696212e-11, 3.739697e-11, 3.783182e-11, 3.826667e-11, 3.870152e-11, 3.913636e-11, 3.957121e-11, 4.000606e-11, 4.044091e-11, 4.087576e-11, 4.131061e-11,
   4.174545e-11, 4.21803e-11, 4.261515e-11, 4.305e-11, 4.348485e-11, 4.348485e-11, 4.348528e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy5[104] = { 0, 0.001639255, 0.001639308, 0.001639123, 0.001638567, 0.001637538, 0.001636272, 0.001634506, 0.001632402, 0.001630035, 0.001627101, 0.001623936, 0.001620382, 0.001616402, 0.001612195, 0.001607483, 0.001602481,
   0.001597202, 0.001591421, 0.001585426, 0.001579045, 0.0015723, 0.001565347, 0.001557912, 0.001550242, 0.001542299, 0.001533935, 0.001525383, 0.00151647, 0.001507264, 0.001497878, 0.001488058, 0.001478061,
   0.001467813, 0.001457235, 0.001446502, 0.001435452, 0.001424185, 0.001412764, 0.001400996, 0.001389099, 0.001376989, 0.001364642, 0.001352174, 0.001339452, 0.00132659, 0.001313605, 0.001300379, 0.001287062,
   0.001273586, 0.001259961, 0.001246254, 0.001232377, 0.001218415, 0.001204364, 0.001190181, 0.001175946, 0.001161614, 0.001147208, 0.001132757, 0.001118219, 0.00110366, 0.001089072, 0.001074431, 0.001059771,
   0.001045084, 0.001030388, 0.001015686, 0.001000987, 0.000986296, 0.0009716181, 0.0009569664, 0.0009423315, 0.0009277433, 0.0009131954, 0.0008986791, 0.0008842389, 0.0008698349, 0.0008554934, 0.0008412391, 0.0008270318,
   0.0008129323, 0.0007988942, 0.0007849144, 0.0007710918, 0.0007573318, 0.000743682, 0.0007301482, 0.000716681, 0.0007033743, 0.0006901534, 0.0006770318, 0.00066405, 0.0006511359, 0.0006383572, 0.0006256789, 0.0006130617,
   0.0006005765, 0.0005881428, 0.0005757817, 0.0005634703, 0.0005512115, 0.0005512115, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx5,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy5);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-4.349007e-12,4.783386e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->SetMaximum(0.001803238);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]5);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx6[106] = { -7.007e-13, -7e-13, 0, 7e-13, 1.4e-12, 2.1e-12, 2.8e-12, 3.5e-12, 4.2e-12, 4.9e-12, 5.6e-12, 6.3e-12, 7e-12, 7.7e-12, 8.4e-12, 9.1e-12, 9.8e-12,
   1.05e-11, 1.12e-11, 1.19e-11, 1.26e-11, 1.33e-11, 1.4e-11, 1.47e-11, 1.54e-11, 1.61e-11, 1.68e-11, 1.75e-11, 1.82e-11, 1.89e-11, 1.96e-11, 2.03e-11, 2.1e-11,
   2.17e-11, 2.24e-11, 2.31e-11, 2.38e-11, 2.45e-11, 2.52e-11, 2.59e-11, 2.66e-11, 2.73e-11, 2.8e-11, 2.87e-11, 2.94e-11, 3.01e-11, 3.08e-11, 3.15e-11, 3.22e-11,
   3.29e-11, 3.36e-11, 3.43e-11, 3.5e-11, 3.57e-11, 3.64e-11, 3.71e-11, 3.78e-11, 3.85e-11, 3.92e-11, 3.99e-11, 4.06e-11, 4.13e-11, 4.2e-11, 4.27e-11, 4.34e-11,
   4.41e-11, 4.48e-11, 4.55e-11, 4.62e-11, 4.69e-11, 4.76e-11, 4.83e-11, 4.9e-11, 4.97e-11, 5.04e-11, 5.11e-11, 5.18e-11, 5.25e-11, 5.32e-11, 5.39e-11, 5.46e-11,
   5.53e-11, 5.6e-11, 5.67e-11, 5.74e-11, 5.81e-11, 5.88e-11, 5.95e-11, 6.02e-11, 6.09e-11, 6.16e-11, 6.23e-11, 6.3e-11, 6.37e-11, 6.44e-11, 6.51e-11, 6.58e-11,
   6.65e-11, 6.72e-11, 6.79e-11, 6.86e-11, 6.93e-11, 7e-11, 7e-11, 7.07e-11, 7.07007e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy6[106] = { 0, 0.001639255, 0.001639255, 0.00163934, 0.001638445, 0.001636574, 0.00163373, 0.001629919, 0.001625149, 0.001619429, 0.00161277, 0.001605184, 0.001596687, 0.001587294, 0.001577022, 0.001565891, 0.001553923,
   0.001541137, 0.001527557, 0.001513209, 0.001498117, 0.00148231, 0.001465813, 0.001448657, 0.001430871, 0.001412485, 0.001393529, 0.001374036, 0.001354036, 0.001333557, 0.001312655, 0.001291334, 0.001269642,
   0.001247608, 0.00122527, 0.00120265, 0.001179791, 0.001156721, 0.001133466, 0.001110064, 0.001086581, 0.001062996, 0.001039352, 0.001015686, 0.000992024, 0.0009683961, 0.0009448222, 0.0009213387, 0.000897971,
   0.000874732, 0.0008516457, 0.0008287512, 0.0008060546, 0.0007835505, 0.0007613269, 0.000739354, 0.0007176547, 0.0006962341, 0.0006751115, 0.0006542526, 0.0006336821, 0.0006133662, 0.0005932682, 0.0005733697, 0.0005535709,
   0.000533874, 0.0005142083, 0.0004945201, 0.000474774, 0.0004549347, 0.0004349822, 0.0004149061, 0.0003947363, 0.0003744835, 0.0003542066, 0.000333952, 0.0003137525, 0.000293801, 0.000274105, 0.0002547611, 0.000235865,
   0.0002175023, 0.0001997563, 0.000182702, 0.0001664084, 0.0001509237, 0.0001362979, 0.0001225536, 0.0001097143, 9.778526e-05, 8.676246e-05, 7.663333e-05, 6.737571e-05, 5.896057e-05, 5.135188e-05, 4.450961e-05, 3.838928e-05,
   3.294406e-05, 2.812558e-05, 2.388487e-05, 2.017305e-05, 1.694223e-05, 1.414996e-05, 1.414996e-05, 1.414996e-05, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx6,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy6);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-7.84084e-12,7.784084e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->SetMaximum(0.001803274);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]6);
   
   graph->Draw("l");
   
   TH1D *frame_5e5dabe20690__15 = new TH1D("frame_5e5dabe20690__15","Posterior probability of parameter \"gZ8\"",100,0,7e-11);
   frame_5e5dabe20690__15->SetBinContent(1,0.001721307);
   frame_5e5dabe20690__15->SetMaximum(0.001721307);
   frame_5e5dabe20690__15->SetEntries(2);
   frame_5e5dabe20690__15->SetDirectory(nullptr);
   frame_5e5dabe20690__15->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5dabe20690__15->SetLineColor(ci);
   frame_5e5dabe20690__15->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dabe20690__15->GetXaxis()->SetLabelFont(42);
   frame_5e5dabe20690__15->GetXaxis()->SetTitleOffset(1);
   frame_5e5dabe20690__15->GetXaxis()->SetTitleFont(42);
   frame_5e5dabe20690__15->GetYaxis()->SetTitle("posterior function");
   frame_5e5dabe20690__15->GetYaxis()->SetLabelFont(42);
   frame_5e5dabe20690__15->GetYaxis()->SetTitleFont(42);
   frame_5e5dabe20690__15->GetZaxis()->SetLabelFont(42);
   frame_5e5dabe20690__15->GetZaxis()->SetTitleOffset(1);
   frame_5e5dabe20690__15->GetZaxis()->SetTitleFont(42);
   frame_5e5dabe20690__15->Draw("AXISSAME");
   
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
