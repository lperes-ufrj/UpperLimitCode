#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p5_m05()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 16:02:19 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-6.25e-13,-9.895511e-05,5.625e-12,0.0008905959);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5dae1ccf50__24 = new TH1D("frame_5e5dae1ccf50__24","Posterior probability of parameter \"gZ8\"",100,0,5e-12);
   frame_5e5dae1ccf50__24->SetBinContent(1,0.0007916408);
   frame_5e5dae1ccf50__24->SetMaximum(0.0007916408);
   frame_5e5dae1ccf50__24->SetEntries(1);
   frame_5e5dae1ccf50__24->SetDirectory(nullptr);
   frame_5e5dae1ccf50__24->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5dae1ccf50__24->SetLineColor(ci);
   frame_5e5dae1ccf50__24->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dae1ccf50__24->GetXaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__24->GetXaxis()->SetTitleOffset(1);
   frame_5e5dae1ccf50__24->GetXaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__24->GetYaxis()->SetTitle("posterior function");
   frame_5e5dae1ccf50__24->GetYaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__24->GetYaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__24->GetZaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__24->GetZaxis()->SetTitleOffset(1);
   frame_5e5dae1ccf50__24->GetZaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__24->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx9[104] = { -1.641414e-17, 0, 1.641414e-14, 3.282828e-14, 4.924242e-14, 6.565657e-14, 8.207071e-14, 9.848485e-14, 1.14899e-13, 1.313131e-13, 1.477273e-13, 1.641414e-13, 1.805556e-13, 1.969697e-13, 2.133838e-13, 2.29798e-13, 2.462121e-13,
   2.626263e-13, 2.790404e-13, 2.954545e-13, 3.118687e-13, 3.282828e-13, 3.44697e-13, 3.611111e-13, 3.775253e-13, 3.939394e-13, 4.103535e-13, 4.267677e-13, 4.431818e-13, 4.59596e-13, 4.760101e-13, 4.924242e-13, 5.088384e-13,
   5.252525e-13, 5.416667e-13, 5.580808e-13, 5.744949e-13, 5.909091e-13, 6.073232e-13, 6.237374e-13, 6.401515e-13, 6.565657e-13, 6.729798e-13, 6.893939e-13, 7.058081e-13, 7.222222e-13, 7.386364e-13, 7.550505e-13, 7.714646e-13,
   7.878788e-13, 8.042929e-13, 8.207071e-13, 8.371212e-13, 8.535354e-13, 8.699495e-13, 8.863636e-13, 9.027778e-13, 9.191919e-13, 9.356061e-13, 9.520202e-13, 9.684343e-13, 9.848485e-13, 1.001263e-12, 1.017677e-12, 1.034091e-12,
   1.050505e-12, 1.066919e-12, 1.083333e-12, 1.099747e-12, 1.116162e-12, 1.132576e-12, 1.14899e-12, 1.165404e-12, 1.181818e-12, 1.198232e-12, 1.214646e-12, 1.231061e-12, 1.247475e-12, 1.263889e-12, 1.280303e-12, 1.296717e-12,
   1.313131e-12, 1.329545e-12, 1.34596e-12, 1.362374e-12, 1.378788e-12, 1.395202e-12, 1.411616e-12, 1.42803e-12, 1.444444e-12, 1.460859e-12, 1.477273e-12, 1.493687e-12, 1.510101e-12, 1.526515e-12, 1.542929e-12, 1.559343e-12,
   1.575758e-12, 1.592172e-12, 1.608586e-12, 1.625e-12, 1.641414e-12, 1.641414e-12, 1.641431e-12 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy9[104] = { 0, 0.0007539436, 0.000753859, 0.0007537743, 0.0007536897, 0.0007023831, 0.000648598, 0.000594813, 0.0005754979, 0.0005596882, 0.0005438784, 0.000521243, 0.0004975105, 0.000473778, 0.0004485435, 0.000422969, 0.0003973944,
   0.000373821, 0.000350848, 0.000327875, 0.0003081513, 0.0002896721, 0.0002711928, 0.0003228547, 0.000407993, 0.0004931313, 0.0005066652, 0.0004782842, 0.0004499033, 0.0004309597, 0.0004187216, 0.0004064836, 0.0003940511,
   0.0003814521, 0.0003688531, 0.0004105646, 0.0005082839, 0.0006060031, 0.0006578705, 0.0006528183, 0.0006477661, 0.0006425994, 0.000637261, 0.0006319226, 0.0006264895, 0.0006208833, 0.0006152771, 0.0006096177, 0.0006038384,
   0.0005980592, 0.0005922315, 0.0005862671, 0.0005803027, 0.0005742975, 0.0005681441, 0.0005619906, 0.0005558224, 0.0005495821, 0.0005433419, 0.0005370868, 0.0005307265, 0.0005243661, 0.0005179994, 0.0005115558, 0.0005051122,
   0.0004986682, 0.0004922118, 0.0004857554, 0.000479299, 0.0004727561, 0.0004662119, 0.0004596676, 0.0004532611, 0.0004468637, 0.0004404662, 0.0004340161, 0.0004275596, 0.0004211031, 0.0004147397, 0.0004083933, 0.0004020468,
   0.0003954761, 0.0003888495, 0.0003822228, 0.0003761812, 0.0003703307, 0.0003644801, 0.0003582348, 0.0003518264, 0.0003454181, 0.0003395347, 0.0003339199, 0.0003283051, 0.0003225696, 0.0003167587, 0.0003109478, 0.0003052056,
   0.0002995156, 0.0002938255, 0.0002882491, 0.0002827765, 0.0002776372, 0.0002776372, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx9,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy9);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-1.641611e-13,1.805575e-12);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->SetMaximum(0.000829338);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]9);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx10[106] = { -5.005e-14, -5e-14, 0, 5e-14, 1e-13, 1.5e-13, 2e-13, 2.5e-13, 3e-13, 3.5e-13, 4e-13, 4.5e-13, 5e-13, 5.5e-13, 6e-13, 6.5e-13, 7e-13,
   7.5e-13, 8e-13, 8.5e-13, 9e-13, 9.5e-13, 1e-12, 1.05e-12, 1.1e-12, 1.15e-12, 1.2e-12, 1.25e-12, 1.3e-12, 1.35e-12, 1.4e-12, 1.45e-12, 1.5e-12,
   1.55e-12, 1.6e-12, 1.65e-12, 1.7e-12, 1.75e-12, 1.8e-12, 1.85e-12, 1.9e-12, 1.95e-12, 2e-12, 2.05e-12, 2.1e-12, 2.15e-12, 2.2e-12, 2.25e-12, 2.3e-12,
   2.35e-12, 2.4e-12, 2.45e-12, 2.5e-12, 2.55e-12, 2.6e-12, 2.65e-12, 2.7e-12, 2.75e-12, 2.8e-12, 2.85e-12, 2.9e-12, 2.95e-12, 3e-12, 3.05e-12, 3.1e-12,
   3.15e-12, 3.2e-12, 3.25e-12, 3.3e-12, 3.35e-12, 3.4e-12, 3.45e-12, 3.5e-12, 3.55e-12, 3.6e-12, 3.65e-12, 3.7e-12, 3.75e-12, 3.8e-12, 3.85e-12, 3.9e-12,
   3.95e-12, 4e-12, 4.05e-12, 4.1e-12, 4.15e-12, 4.2e-12, 4.25e-12, 4.3e-12, 4.35e-12, 4.4e-12, 4.45e-12, 4.5e-12, 4.55e-12, 4.6e-12, 4.65e-12, 4.7e-12,
   4.75e-12, 4.8e-12, 4.85e-12, 4.9e-12, 4.95e-12, 5e-12, 5e-12, 5.05e-12, 5.05005e-12 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy10[106] = { 0, 0.0007539436, 0.0007539436, 0.0007536858, 0.0005898482, 0.0005416894, 0.0004693966, 0.0003914926, 0.0003215132, 0.0002652226, 0.000524567, 0.0004381143, 0.0004008352, 0.0003624567, 0.0006601246, 0.0006447348, 0.0006284732,
   0.0006113959, 0.0005937914, 0.0005756229, 0.0005568785, 0.0005378696, 0.0005184951, 0.0004988669, 0.0004791997, 0.0004592649, 0.0004397772, 0.0004201098, 0.0004007775, 0.0003805917, 0.0003627699, 0.0003432491, 0.0003261455,
   0.0003084446, 0.0002911117, 0.0002744412, 0.0002580971, 0.0002408155, 0.0002253009, 0.000209278, 0.0001928925, 0.0001761765, 0.0001592715, 0.0001423582, 0.0001255515, 0.0001094829, 9.407075e-05, 7.966789e-05, 6.647156e-05,
   5.464109e-05, 4.421755e-05, 3.520989e-05, 2.742064e-05, 2.118352e-05, 1.591682e-05, 1.190408e-05, 8.682561e-06, 6.186564e-06, 4.304715e-06, 2.916017e-06, 1.920934e-06, 1.222224e-06, 7.46586e-07, 4.332383e-07, 2.356722e-07,
   1.170672e-07, 5.100993e-08, 1.826998e-08, 4.901787e-09, 8.851461e-10, 9.722612e-11, 3.413669e-22, 1.01358e-25, 1.400143e-29, 9.126275e-34, 2.845772e-38, 4.302526e-43, 0, 2.648202e-30, 3.766874e-34, 7.841885e-36,
   1.748624e-48, 1.177255e-53, 2.618405e-141, 0, 0, 9.233162e-65, 1.592387e-70, 1.517489e-76, 5.223094e-85, 1.1301e-91, 1.390947e-98, 0, 1.600122e-134, 1.322228e-127, 1.357335e-128, 1.651167e-133,
   0, 0, 0, 0, 0, 0, 0, 0, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx10,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy10);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-5.6006e-13,5.56006e-12);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->SetMaximum(0.000829338);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]10);
   
   graph->Draw("l");
   
   TH1D *frame_5e5dae1ccf50__25 = new TH1D("frame_5e5dae1ccf50__25","Posterior probability of parameter \"gZ8\"",100,0,5e-12);
   frame_5e5dae1ccf50__25->SetBinContent(1,0.0007916408);
   frame_5e5dae1ccf50__25->SetMaximum(0.0007916408);
   frame_5e5dae1ccf50__25->SetEntries(1);
   frame_5e5dae1ccf50__25->SetDirectory(nullptr);
   frame_5e5dae1ccf50__25->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5dae1ccf50__25->SetLineColor(ci);
   frame_5e5dae1ccf50__25->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dae1ccf50__25->GetXaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__25->GetXaxis()->SetTitleOffset(1);
   frame_5e5dae1ccf50__25->GetXaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__25->GetYaxis()->SetTitle("posterior function");
   frame_5e5dae1ccf50__25->GetYaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__25->GetYaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__25->GetZaxis()->SetLabelFont(42);
   frame_5e5dae1ccf50__25->GetZaxis()->SetTitleOffset(1);
   frame_5e5dae1ccf50__25->GetZaxis()->SetTitleFont(42);
   frame_5e5dae1ccf50__25->Draw("AXISSAME");
   
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
