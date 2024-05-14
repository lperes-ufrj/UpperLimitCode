#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p5_m10()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 16:05:46 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-1.25e-12,-9.895511e-05,1.125e-11,0.0008905959);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5daf734090__29 = new TH1D("frame_5e5daf734090__29","Posterior probability of parameter \"gZ8\"",100,0,1e-11);
   frame_5e5daf734090__29->SetBinContent(1,0.0007916408);
   frame_5e5daf734090__29->SetMaximum(0.0007916408);
   frame_5e5daf734090__29->SetEntries(1);
   frame_5e5daf734090__29->SetDirectory(nullptr);
   frame_5e5daf734090__29->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5daf734090__29->SetLineColor(ci);
   frame_5e5daf734090__29->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5daf734090__29->GetXaxis()->SetLabelFont(42);
   frame_5e5daf734090__29->GetXaxis()->SetTitleOffset(1);
   frame_5e5daf734090__29->GetXaxis()->SetTitleFont(42);
   frame_5e5daf734090__29->GetYaxis()->SetTitle("posterior function");
   frame_5e5daf734090__29->GetYaxis()->SetLabelFont(42);
   frame_5e5daf734090__29->GetYaxis()->SetTitleFont(42);
   frame_5e5daf734090__29->GetZaxis()->SetLabelFont(42);
   frame_5e5daf734090__29->GetZaxis()->SetTitleOffset(1);
   frame_5e5daf734090__29->GetZaxis()->SetTitleFont(42);
   frame_5e5daf734090__29->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx11[104] = { -3.282828e-17, 0, 3.282828e-14, 6.565657e-14, 9.848485e-14, 1.313131e-13, 1.641414e-13, 1.969697e-13, 2.29798e-13, 2.626263e-13, 2.954545e-13, 3.282828e-13, 3.611111e-13, 3.939394e-13, 4.267677e-13, 4.59596e-13, 4.924242e-13,
   5.252525e-13, 5.580808e-13, 5.909091e-13, 6.237374e-13, 6.565657e-13, 6.893939e-13, 7.222222e-13, 7.550505e-13, 7.878788e-13, 8.207071e-13, 8.535354e-13, 8.863636e-13, 9.191919e-13, 9.520202e-13, 9.848485e-13, 1.017677e-12,
   1.050505e-12, 1.083333e-12, 1.116162e-12, 1.14899e-12, 1.181818e-12, 1.214646e-12, 1.247475e-12, 1.280303e-12, 1.313131e-12, 1.34596e-12, 1.378788e-12, 1.411616e-12, 1.444444e-12, 1.477273e-12, 1.510101e-12, 1.542929e-12,
   1.575758e-12, 1.608586e-12, 1.641414e-12, 1.674242e-12, 1.707071e-12, 1.739899e-12, 1.772727e-12, 1.805556e-12, 1.838384e-12, 1.871212e-12, 1.90404e-12, 1.936869e-12, 1.969697e-12, 2.002525e-12, 2.035354e-12, 2.068182e-12,
   2.10101e-12, 2.133838e-12, 2.166667e-12, 2.199495e-12, 2.232323e-12, 2.265152e-12, 2.29798e-12, 2.330808e-12, 2.363636e-12, 2.396465e-12, 2.429293e-12, 2.462121e-12, 2.494949e-12, 2.527778e-12, 2.560606e-12, 2.593434e-12,
   2.626263e-12, 2.659091e-12, 2.691919e-12, 2.724747e-12, 2.757576e-12, 2.790404e-12, 2.823232e-12, 2.856061e-12, 2.888889e-12, 2.921717e-12, 2.954545e-12, 2.987374e-12, 3.020202e-12, 3.05303e-12, 3.085859e-12, 3.118687e-12,
   3.151515e-12, 3.184343e-12, 3.217172e-12, 3.25e-12, 3.282828e-12, 3.282828e-12, 3.282861e-12 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy11[104] = { 0, 0.0007539436, 0.0007538529, 0.0007537622, 0.0007536714, 0.0007023682, 0.000648587, 0.0005948058, 0.0005754882, 0.0005596753, 0.0005438625, 0.000521224, 0.0004974886, 0.0004737532, 0.000448516, 0.0004229389, 0.0003973618,
   0.0003737862, 0.0003508112, 0.0003278361, 0.0003081105, 0.0002896294, 0.0002711483, 0.0003227604, 0.0004078261, 0.0004928918, 0.0005063918, 0.0004779997, 0.0004496075, 0.0004306512, 0.0004183993, 0.0004061474, 0.0003937,
   0.0003810852, 0.0003684704, 0.0004101173, 0.0005077215, 0.0006053258, 0.000657113, 0.0006520237, 0.0006469344, 0.0006417284, 0.0006363474, 0.0006309663, 0.0006254984, 0.000619872, 0.0006142455, 0.0006085638, 0.0006027574,
   0.0005969511, 0.0005910894, 0.0005850712, 0.000579053, 0.0005730047, 0.0005668467, 0.0005606887, 0.0005545059, 0.0005482016, 0.0005418973, 0.000535581, 0.0005291794, 0.0005227777, 0.0005163713, 0.0005099077, 0.0005034442,
   0.00049698, 0.0004904965, 0.000484013, 0.0004775295, 0.0004707997, 0.0004640661, 0.0004573325, 0.0004510453, 0.0004447874, 0.0004385294, 0.000432083, 0.0004256138, 0.0004191447, 0.0004127522, 0.0004063736, 0.000399995,
   0.0003934638, 0.0003868945, 0.0003803252, 0.0003742456, 0.0003683259, 0.0003624062, 0.0003563443, 0.0003502237, 0.0003441031, 0.0003380857, 0.0003321212, 0.0003261567, 0.0003202996, 0.0003145096, 0.0003087197, 0.0003029925,
   0.0002973127, 0.000291633, 0.0002860653, 0.0002805997, 0.0002753007, 0.0002753007, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx11,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy11);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-3.283222e-13,3.611151e-12);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->SetMaximum(0.000829338);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]11);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx12[106] = { -1.001e-13, -1e-13, 0, 1e-13, 2e-13, 3e-13, 4e-13, 5e-13, 6e-13, 7e-13, 8e-13, 9e-13, 1e-12, 1.1e-12, 1.2e-12, 1.3e-12, 1.4e-12,
   1.5e-12, 1.6e-12, 1.7e-12, 1.8e-12, 1.9e-12, 2e-12, 2.1e-12, 2.2e-12, 2.3e-12, 2.4e-12, 2.5e-12, 2.6e-12, 2.7e-12, 2.8e-12, 2.9e-12, 3e-12,
   3.1e-12, 3.2e-12, 3.3e-12, 3.4e-12, 3.5e-12, 3.6e-12, 3.7e-12, 3.8e-12, 3.9e-12, 4e-12, 4.1e-12, 4.2e-12, 4.3e-12, 4.4e-12, 4.5e-12, 4.6e-12,
   4.7e-12, 4.8e-12, 4.9e-12, 5e-12, 5.1e-12, 5.2e-12, 5.3e-12, 5.4e-12, 5.5e-12, 5.6e-12, 5.7e-12, 5.8e-12, 5.9e-12, 6e-12, 6.1e-12, 6.2e-12,
   6.3e-12, 6.4e-12, 6.5e-12, 6.6e-12, 6.7e-12, 6.8e-12, 6.9e-12, 7e-12, 7.1e-12, 7.2e-12, 7.3e-12, 7.4e-12, 7.5e-12, 7.6e-12, 7.7e-12, 7.8e-12,
   7.9e-12, 8e-12, 8.1e-12, 8.2e-12, 8.3e-12, 8.4e-12, 8.5e-12, 8.6e-12, 8.7e-12, 8.8e-12, 8.9e-12, 9e-12, 9.1e-12, 9.2e-12, 9.3e-12, 9.4e-12,
   9.5e-12, 9.6e-12, 9.7e-12, 9.8e-12, 9.9e-12, 1e-11, 1e-11, 1.01e-11, 1.01001e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy12[106] = { 0, 0.0007539436, 0.0007539436, 0.0007536672, 0.0005898413, 0.000541673, 0.0004693712, 0.0003914594, 0.0003214738, 0.0002651775, 0.0005243006, 0.0004378139, 0.0004004926, 0.000362066, 0.0006593835, 0.0006438809, 0.0006274893,
   0.0006103503, 0.0005926633, 0.000574331, 0.0005555728, 0.0005363689, 0.0005168685, 0.0004971795, 0.0004774297, 0.0004569182, 0.0004378555, 0.0004181494, 0.0003987193, 0.0003787082, 0.0003606758, 0.0003420315, 0.0003238627,
   0.0003062256, 0.0002889242, 0.0002722753, 0.0002536178, 0.0002386072, 0.000222959, 0.0002068307, 0.0001902814, 0.0001734892, 0.0001564578, 0.0001392912, 0.0001227396, 0.0001065969, 9.138673e-05, 7.71356e-05, 6.413695e-05,
   5.251857e-05, 4.232646e-05, 3.356147e-05, 2.604254e-05, 2.002063e-05, 1.499291e-05, 1.113552e-05, 8.068037e-06, 5.71139e-06, 3.933652e-06, 2.651853e-06, 1.730198e-06, 1.088786e-06, 6.562068e-07, 3.744896e-07, 1.991037e-07,
   9.574732e-08, 3.980736e-08, 1.327771e-08, 3.217242e-09, 5.080674e-10, 4.743184e-11, 3.681689e-23, 8.474729e-27, 9.056021e-31, 4.556616e-35, 1.094585e-39, 0, 8.090606e-28, 1.786814e-31, 1.3903e-33, 3.992926e-37,
   3.913938e-50, 2.030625e-55, 1.902347e-144, 0, 4.14903e-61, 1.007049e-66, 1.335476e-72, 7.806475e-81, 2.295288e-87, 3.798275e-94, 3.570937e-101, 7.473458e-115, 1.17538e-137, 1.183552e-130, 1.172284e-131, 1.222011e-136,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx12,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy12);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-1.12012e-12,1.112012e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->SetMaximum(0.000829338);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]12);
   
   graph->Draw("l");
   
   TH1D *frame_5e5daf734090__30 = new TH1D("frame_5e5daf734090__30","Posterior probability of parameter \"gZ8\"",100,0,1e-11);
   frame_5e5daf734090__30->SetBinContent(1,0.0007916408);
   frame_5e5daf734090__30->SetMaximum(0.0007916408);
   frame_5e5daf734090__30->SetEntries(1);
   frame_5e5daf734090__30->SetDirectory(nullptr);
   frame_5e5daf734090__30->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5daf734090__30->SetLineColor(ci);
   frame_5e5daf734090__30->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5daf734090__30->GetXaxis()->SetLabelFont(42);
   frame_5e5daf734090__30->GetXaxis()->SetTitleOffset(1);
   frame_5e5daf734090__30->GetXaxis()->SetTitleFont(42);
   frame_5e5daf734090__30->GetYaxis()->SetTitle("posterior function");
   frame_5e5daf734090__30->GetYaxis()->SetLabelFont(42);
   frame_5e5daf734090__30->GetYaxis()->SetTitleFont(42);
   frame_5e5daf734090__30->GetZaxis()->SetLabelFont(42);
   frame_5e5daf734090__30->GetZaxis()->SetTitleOffset(1);
   frame_5e5daf734090__30->GetZaxis()->SetTitleFont(42);
   frame_5e5daf734090__30->Draw("AXISSAME");
   
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
