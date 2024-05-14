#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b1p1_m10()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 15:54:29 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-4.375e-12,-0.0002241855,3.9375e-11,0.002017669);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e5dab037bd0__9 = new TH1D("frame_5e5dab037bd0__9","Posterior probability of parameter \"gZ8\"",100,0,3.5e-11);
   frame_5e5dab037bd0__9->SetBinContent(1,0.001793484);
   frame_5e5dab037bd0__9->SetMaximum(0.001793484);
   frame_5e5dab037bd0__9->SetEntries(2);
   frame_5e5dab037bd0__9->SetDirectory(nullptr);
   frame_5e5dab037bd0__9->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e5dab037bd0__9->SetLineColor(ci);
   frame_5e5dab037bd0__9->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dab037bd0__9->GetXaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__9->GetXaxis()->SetTitleOffset(1);
   frame_5e5dab037bd0__9->GetXaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__9->GetYaxis()->SetTitle("posterior function");
   frame_5e5dab037bd0__9->GetYaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__9->GetYaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__9->GetZaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__9->GetZaxis()->SetTitleOffset(1);
   frame_5e5dab037bd0__9->GetZaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__9->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx3[104] = { -1.891414e-16, 0, 1.891414e-13, 3.782828e-13, 5.674242e-13, 7.565657e-13, 9.457071e-13, 1.134848e-12, 1.32399e-12, 1.513131e-12, 1.702273e-12, 1.891414e-12, 2.080556e-12, 2.269697e-12, 2.458838e-12, 2.64798e-12, 2.837121e-12,
   3.026263e-12, 3.215404e-12, 3.404545e-12, 3.593687e-12, 3.782828e-12, 3.97197e-12, 4.161111e-12, 4.350253e-12, 4.539394e-12, 4.728535e-12, 4.917677e-12, 5.106818e-12, 5.29596e-12, 5.485101e-12, 5.674242e-12, 5.863384e-12,
   6.052525e-12, 6.241667e-12, 6.430808e-12, 6.619949e-12, 6.809091e-12, 6.998232e-12, 7.187374e-12, 7.376515e-12, 7.565657e-12, 7.754798e-12, 7.943939e-12, 8.133081e-12, 8.322222e-12, 8.511364e-12, 8.700505e-12, 8.889646e-12,
   9.078788e-12, 9.267929e-12, 9.457071e-12, 9.646212e-12, 9.835354e-12, 1.002449e-11, 1.021364e-11, 1.040278e-11, 1.059192e-11, 1.078106e-11, 1.09702e-11, 1.115934e-11, 1.134848e-11, 1.153763e-11, 1.172677e-11, 1.191591e-11,
   1.210505e-11, 1.229419e-11, 1.248333e-11, 1.267247e-11, 1.286162e-11, 1.305076e-11, 1.32399e-11, 1.342904e-11, 1.361818e-11, 1.380732e-11, 1.399646e-11, 1.418561e-11, 1.437475e-11, 1.456389e-11, 1.475303e-11, 1.494217e-11,
   1.513131e-11, 1.532045e-11, 1.55096e-11, 1.569874e-11, 1.588788e-11, 1.607702e-11, 1.626616e-11, 1.64553e-11, 1.664444e-11, 1.683359e-11, 1.702273e-11, 1.721187e-11, 1.740101e-11, 1.759015e-11, 1.777929e-11, 1.796843e-11,
   1.815758e-11, 1.834672e-11, 1.853586e-11, 1.8725e-11, 1.891414e-11, 1.891414e-11, 1.891433e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy3[104] = { 0, 0.001708044, 0.001708063, 0.001707973, 0.00170726, 0.001706328, 0.001704883, 0.001703113, 0.001700942, 0.001698339, 0.001695446, 0.001692021, 0.001688416, 0.001684178, 0.001679836, 0.001674833, 0.001669696,
   0.001664013, 0.001658099, 0.001651749, 0.001645076, 0.001638076, 0.001630667, 0.001623034, 0.001614911, 0.001606662, 0.001597851, 0.001588954, 0.001579538, 0.001569987, 0.001560019, 0.001549844, 0.00153935,
   0.001528582, 0.001517582, 0.001506252, 0.001494774, 0.001482917, 0.001470988, 0.001458638, 0.001446228, 0.001433477, 0.001420619, 0.001407497, 0.001394224, 0.001380761, 0.001367113, 0.001353336, 0.001339349,
   0.001325287, 0.001310998, 0.001296672, 0.001282127, 0.001267544, 0.001252798, 0.001237995, 0.001223081, 0.001208096, 0.001193036, 0.001177896, 0.001162709, 0.001147472, 0.001132221, 0.001116904, 0.001101579,
   0.001086221, 0.00107086, 0.001055489, 0.001040123, 0.001024768, 0.001009433, 0.0009941143, 0.0009788373, 0.0009635796, 0.0009483897, 0.0009332135, 0.0009181384, 0.0009030814, 0.0008881319, 0.0008732214, 0.0008584113,
   0.0008436607, 0.0008289891, 0.0008144465, 0.0007999977, 0.0007856674, 0.0007713812, 0.0007572815, 0.0007432136, 0.0007293508, 0.0007155256, 0.0007018752, 0.0006882886, 0.0006748331, 0.0006614833, 0.0006482496, 0.0006351117,
   0.0006220309, 0.000609053, 0.0005961047, 0.0005832492, 0.0005704723, 0.0005704723, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx3,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy3);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-1.891641e-12,2.080578e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->SetMaximum(0.00187887);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]3);
   
   graph->Draw("f");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx4[106] = { -3.5035e-13, -3.5e-13, 0, 3.5e-13, 7e-13, 1.05e-12, 1.4e-12, 1.75e-12, 2.1e-12, 2.45e-12, 2.8e-12, 3.15e-12, 3.5e-12, 3.85e-12, 4.2e-12, 4.55e-12, 4.9e-12,
   5.25e-12, 5.6e-12, 5.95e-12, 6.3e-12, 6.65e-12, 7e-12, 7.35e-12, 7.7e-12, 8.05e-12, 8.4e-12, 8.75e-12, 9.1e-12, 9.45e-12, 9.8e-12, 1.015e-11, 1.05e-11,
   1.085e-11, 1.12e-11, 1.155e-11, 1.19e-11, 1.225e-11, 1.26e-11, 1.295e-11, 1.33e-11, 1.365e-11, 1.4e-11, 1.435e-11, 1.47e-11, 1.505e-11, 1.54e-11, 1.575e-11, 1.61e-11,
   1.645e-11, 1.68e-11, 1.715e-11, 1.75e-11, 1.785e-11, 1.82e-11, 1.855e-11, 1.89e-11, 1.925e-11, 1.96e-11, 1.995e-11, 2.03e-11, 2.065e-11, 2.1e-11, 2.135e-11, 2.17e-11,
   2.205e-11, 2.24e-11, 2.275e-11, 2.31e-11, 2.345e-11, 2.38e-11, 2.415e-11, 2.45e-11, 2.485e-11, 2.52e-11, 2.555e-11, 2.59e-11, 2.625e-11, 2.66e-11, 2.695e-11, 2.73e-11,
   2.765e-11, 2.8e-11, 2.835e-11, 2.87e-11, 2.905e-11, 2.94e-11, 2.975e-11, 3.01e-11, 3.045e-11, 3.08e-11, 3.115e-11, 3.15e-11, 3.185e-11, 3.22e-11, 3.255e-11, 3.29e-11,
   3.325e-11, 3.36e-11, 3.395e-11, 3.43e-11, 3.465e-11, 3.5e-11, 3.5e-11, 3.535e-11, 3.535035e-11 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy4[106] = { 0, 0.001708044, 0.001708044, 0.00170808, 0.00170676, 0.001704087, 0.001700069, 0.001694716, 0.001688045, 0.00168007, 0.001670812, 0.001660294, 0.001648544, 0.001635589, 0.001621464, 0.001606199, 0.001589834,
   0.001572409, 0.001553963, 0.001534544, 0.00151419, 0.00149295, 0.001470877, 0.001448015, 0.00142442, 0.001400138, 0.001375225, 0.001349731, 0.00132371, 0.001297216, 0.0012703, 0.001243013, 0.001215414,
   0.001187547, 0.001159445, 0.001131224, 0.00110287, 0.001074452, 0.001046007, 0.001017593, 0.0009892468, 0.0009610128, 0.0009329298, 0.0009050375, 0.0008773738, 0.0008499682, 0.0008228187, 0.0007960816, 0.0007696455,
   0.0007436023, 0.0007179496, 0.0006926899, 0.000667791, 0.0006433024, 0.0006190969, 0.0005951366, 0.0005713619, 0.0005476715, 0.0005239969, 0.0005002632, 0.0004764109, 0.0004524124, 0.0004282557, 0.0004039798, 0.0003796187,
   0.0003552653, 0.0003310159, 0.0003069767, 0.0002833548, 0.0002602387, 0.0002377761, 0.0002161032, 0.0001953455, 0.000175612, 0.0001569932, 0.000139554, 0.0001233456, 0.0001083856, 9.468201e-05, 8.22195e-05, 7.096652e-05,
   6.087827e-05, 5.189745e-05, 4.396083e-05, 3.699489e-05, 3.092462e-05, 2.567241e-05, 2.11608e-05, 1.731357e-05, 1.40573e-05, 1.132213e-05, 9.042489e-06, 7.156685e-06, 5.611759e-06, 4.357225e-06, 3.346735e-06, 2.540887e-06,
   1.904963e-06, 1.408806e-06, 1.026411e-06, 7.356489e-07, 5.178366e-07, 3.577576e-07, 3.577576e-07, 3.577576e-07, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx4,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy4);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-3.92042e-12,3.892042e-11);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->SetMaximum(0.001878888);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->SetDirectory(nullptr);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->SetLineColor(ci);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetXaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetXaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetXaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetYaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetYaxis()->SetTitleFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetZaxis()->SetLabelFont(42);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetZaxis()->SetTitleOffset(1);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]4);
   
   graph->Draw("l");
   
   TH1D *frame_5e5dab037bd0__10 = new TH1D("frame_5e5dab037bd0__10","Posterior probability of parameter \"gZ8\"",100,0,3.5e-11);
   frame_5e5dab037bd0__10->SetBinContent(1,0.001793484);
   frame_5e5dab037bd0__10->SetMaximum(0.001793484);
   frame_5e5dab037bd0__10->SetEntries(2);
   frame_5e5dab037bd0__10->SetDirectory(nullptr);
   frame_5e5dab037bd0__10->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e5dab037bd0__10->SetLineColor(ci);
   frame_5e5dab037bd0__10->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e5dab037bd0__10->GetXaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__10->GetXaxis()->SetTitleOffset(1);
   frame_5e5dab037bd0__10->GetXaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__10->GetYaxis()->SetTitle("posterior function");
   frame_5e5dab037bd0__10->GetYaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__10->GetYaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__10->GetZaxis()->SetLabelFont(42);
   frame_5e5dab037bd0__10->GetZaxis()->SetTitleOffset(1);
   frame_5e5dab037bd0__10->GetZaxis()->SetTitleFont(42);
   frame_5e5dab037bd0__10->Draw("AXISSAME");
   
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
