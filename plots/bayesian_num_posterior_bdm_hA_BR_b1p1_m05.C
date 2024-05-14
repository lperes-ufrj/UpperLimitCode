#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p1_m05()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 15:52:21 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-3.125e-12,-0.0002202572,2.8125e-11,0.001982315);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5daa80d2a0__4 = new TH1D("frame_5e5daa80d2a0__4","Posterior probability of parameter \"gZ8\"",100,0,2.5e-11);
   frame_5e5daa80d2a0__4->SetBinContent(1,0.001762058);
   frame_5e5daa80d2a0__4->SetMaximum(0.001762058);
   frame_5e5daa80d2a0__4->SetEntries(1);
   frame_5e5daa80d2a0__4->SetDirectory(nullptr);
   frame_5e5daa80d2a0__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5daa80d2a0__4->SetLineColor(ci);
   frame_5e5daa80d2a0__4->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5daa80d2a0__4->GetXaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__4->GetXaxis()->SetTitleOffset(1);
   frame_5e5daa80d2a0__4->GetXaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__4->GetYaxis()->SetTitle("posterior function");
   frame_5e5daa80d2a0__4->GetYaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__4->GetYaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__4->GetZaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__4->GetZaxis()->SetTitleOffset(1);
   frame_5e5daa80d2a0__4->GetZaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__4->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx1[104] = { -1.275253e-16, 0, 1.275253e-13, 2.550505e-13, 3.825758e-13, 5.10101e-13, 6.376263e-13, 7.651515e-13, 8.926768e-13, 1.020202e-12, 1.147727e-12, 1.275253e-12, 1.402778e-12, 1.530303e-12, 1.657828e-12, 1.785354e-12, 1.912879e-12,
   2.040404e-12, 2.167929e-12, 2.295455e-12, 2.42298e-12, 2.550505e-12, 2.67803e-12, 2.805556e-12, 2.933081e-12, 3.060606e-12, 3.188131e-12, 3.315657e-12, 3.443182e-12, 3.570707e-12, 3.698232e-12, 3.825758e-12, 3.953283e-12,
   4.080808e-12, 4.208333e-12, 4.335859e-12, 4.463384e-12, 4.590909e-12, 4.718434e-12, 4.84596e-12, 4.973485e-12, 5.10101e-12, 5.228535e-12, 5.356061e-12, 5.483586e-12, 5.611111e-12, 5.738636e-12, 5.866162e-12, 5.993687e-12,
   6.121212e-12, 6.248737e-12, 6.376263e-12, 6.503788e-12, 6.631313e-12, 6.758838e-12, 6.886364e-12, 7.013889e-12, 7.141414e-12, 7.268939e-12, 7.396465e-12, 7.52399e-12, 7.651515e-12, 7.77904e-12, 7.906566e-12, 8.034091e-12,
   8.161616e-12, 8.289141e-12, 8.416667e-12, 8.544192e-12, 8.671717e-12, 8.799242e-12, 8.926768e-12, 9.054293e-12, 9.181818e-12, 9.309343e-12, 9.436869e-12, 9.564394e-12, 9.691919e-12, 9.819444e-12, 9.94697e-12, 1.007449e-11,
   1.020202e-11, 1.032955e-11, 1.045707e-11, 1.05846e-11, 1.071212e-11, 1.083965e-11, 1.096717e-11, 1.10947e-11, 1.122222e-11, 1.134975e-11, 1.147727e-11, 1.16048e-11, 1.173232e-11, 1.185985e-11, 1.198737e-11, 1.21149e-11,
   1.224242e-11, 1.236995e-11, 1.249747e-11, 1.2625e-11, 1.275253e-11, 1.275253e-11, 1.275265e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy1[104] = { 0, 0.00167815, 0.00167813, 0.001678079, 0.001677259, 0.001676377, 0.001674761, 0.00167305, 0.001670643, 0.001668111, 0.001664919, 0.001661574, 0.001657608, 0.001653461, 0.001648733, 0.001643797, 0.00163832,
   0.001632611, 0.001626403, 0.00161994, 0.001613017, 0.00160582, 0.001598203, 0.001590294, 0.001582005, 0.001573409, 0.001564472, 0.001555215, 0.001545655, 0.001535763, 0.001525606, 0.001515112, 0.001504389,
   0.001493324, 0.00148206, 0.001470454, 0.001458681, 0.001446569, 0.001434319, 0.001421733, 0.001409037, 0.001396014, 0.001382905, 0.001369483, 0.001355997, 0.001342182, 0.001328318, 0.001314225, 0.001300109,
   0.001285701, 0.001271279, 0.001256611, 0.001241935, 0.001227057, 0.001212166, 0.001197109, 0.001182037, 0.001166836, 0.001151619, 0.001136306, 0.001120978, 0.001105587, 0.001090185, 0.001074741, 0.001059294,
   0.001043838, 0.001028382, 0.001012928, 0.000997488, 0.0009820755, 0.0009666885, 0.000951342, 0.0009360334, 0.000920776, 0.0009055726, 0.000890431, 0.0008753599, 0.0008603578, 0.0008454434, 0.0008306025, 0.0008158597,
   0.0008011868, 0.0007866511, 0.0007721981, 0.0007578894, 0.000743654, 0.0007295757, 0.0007155638, 0.0007017241, 0.0006879441, 0.0006743481, 0.0006608034, 0.0006474346, 0.0006341038, 0.0006209308, 0.0006077832, 0.0005947637,
   0.0005817582, 0.0005688473, 0.0005559423, 0.0005430794, 0.000530318, 0.000530318, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx1,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy1);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-1.275406e-12,1.402793e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetMaximum(0.001845965);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]1);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx2[106] = { -2.5025e-13, -2.5e-13, 0, 2.5e-13, 5e-13, 7.5e-13, 1e-12, 1.25e-12, 1.5e-12, 1.75e-12, 2e-12, 2.25e-12, 2.5e-12, 2.75e-12, 3e-12, 3.25e-12, 3.5e-12,
   3.75e-12, 4e-12, 4.25e-12, 4.5e-12, 4.75e-12, 5e-12, 5.25e-12, 5.5e-12, 5.75e-12, 6e-12, 6.25e-12, 6.5e-12, 6.75e-12, 7e-12, 7.25e-12, 7.5e-12,
   7.75e-12, 8e-12, 8.25e-12, 8.5e-12, 8.75e-12, 9e-12, 9.25e-12, 9.5e-12, 9.75e-12, 1e-11, 1.025e-11, 1.05e-11, 1.075e-11, 1.1e-11, 1.125e-11, 1.15e-11,
   1.175e-11, 1.2e-11, 1.225e-11, 1.25e-11, 1.275e-11, 1.3e-11, 1.325e-11, 1.35e-11, 1.375e-11, 1.4e-11, 1.425e-11, 1.45e-11, 1.475e-11, 1.5e-11, 1.525e-11, 1.55e-11,
   1.575e-11, 1.6e-11, 1.625e-11, 1.65e-11, 1.675e-11, 1.7e-11, 1.725e-11, 1.75e-11, 1.775e-11, 1.8e-11, 1.825e-11, 1.85e-11, 1.875e-11, 1.9e-11, 1.925e-11, 1.95e-11,
   1.975e-11, 2e-11, 2.025e-11, 2.05e-11, 2.075e-11, 2.1e-11, 2.125e-11, 2.15e-11, 2.175e-11, 2.2e-11, 2.225e-11, 2.25e-11, 2.275e-11, 2.3e-11, 2.325e-11, 2.35e-11,
   2.375e-11, 2.4e-11, 2.425e-11, 2.45e-11, 2.475e-11, 2.5e-11, 2.5e-11, 2.525e-11, 2.525025e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy2[106] = { 0, 0.00167815, 0.00167815, 0.001678111, 0.001676505, 0.001673336, 0.001668617, 0.00166236, 0.001654585, 0.001645315, 0.001634579, 0.001622407, 0.001608836, 0.001593904, 0.001577656, 0.001560136, 0.001541395,
   0.001521482, 0.001500461, 0.00147838, 0.001455301, 0.001431287, 0.001406398, 0.001380698, 0.001354261, 0.001327082, 0.00129941, 0.001271136, 0.001242377, 0.001213209, 0.001183692, 0.001153893, 0.001123873,
   0.001093702, 0.001063426, 0.001033126, 0.001002829, 0.0009726144, 0.0009425291, 0.0009126186, 0.0008829353, 0.0008535251, 0.000824431, 0.0007956663, 0.0007673327, 0.0007394257, 0.0007119567, 0.0006849425, 0.0006583895,
   0.000632256, 0.0006064815, 0.0005809856, 0.0005556868, 0.000530472, 0.0005052391, 0.0004799137, 0.0004544268, 0.0004287581, 0.0004029221, 0.0003769751, 0.0003510125, 0.0003251613, 0.0002995485, 0.0002744229, 0.0002499093,
   0.0002261906, 0.0002034366, 0.0001817968, 0.0001613998, 0.000142341, 0.0001246874, 0.0001084804, 9.372734e-05, 8.041257e-05, 6.849762e-05, 5.792492e-05, 4.862153e-05, 4.050359e-05, 3.34785e-05, 2.745038e-05, 2.232134e-05,
   1.799461e-05, 1.437655e-05, 1.137808e-05, 8.91583e-06, 6.912195e-06, 5.299658e-06, 4.01521e-06, 3.002544e-06, 2.213622e-06, 1.606889e-06, 1.146679e-06, 8.029582e-07, 5.505386e-07, 3.688461e-07, 2.408095e-07, 1.527937e-07,
   9.39566e-08, 5.583378e-08, 3.197189e-08, 1.759575e-08, 9.283341e-09, 4.702254e-09, 4.702254e-09, 4.702254e-09, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx2,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy2);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-2.8003e-12,2.78003e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetMaximum(0.001845965);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]2);
   
   graph->Draw("l");
   
   TH1D *frame_5e5daa80d2a0__5 = new TH1D("frame_5e5daa80d2a0__5","Posterior probability of parameter \"gZ8\"",100,0,2.5e-11);
   frame_5e5daa80d2a0__5->SetBinContent(1,0.001762058);
   frame_5e5daa80d2a0__5->SetMaximum(0.001762058);
   frame_5e5daa80d2a0__5->SetEntries(1);
   frame_5e5daa80d2a0__5->SetDirectory(nullptr);
   frame_5e5daa80d2a0__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5daa80d2a0__5->SetLineColor(ci);
   frame_5e5daa80d2a0__5->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5daa80d2a0__5->GetXaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__5->GetXaxis()->SetTitleOffset(1);
   frame_5e5daa80d2a0__5->GetXaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__5->GetYaxis()->SetTitle("posterior function");
   frame_5e5daa80d2a0__5->GetYaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__5->GetYaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__5->GetZaxis()->SetLabelFont(42);
   frame_5e5daa80d2a0__5->GetZaxis()->SetTitleOffset(1);
   frame_5e5daa80d2a0__5->GetZaxis()->SetTitleFont(42);
   frame_5e5daa80d2a0__5->Draw("AXISSAME");
   
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
