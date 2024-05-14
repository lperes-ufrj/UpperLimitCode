#ifdef __CLING__
#pragma cling optimize(0)
#endif
void bayesian_num_posterior_bdm_hA_BR_b10_m10.()
{
//=========Macro generated from canvas: posterior/
//=========  (Thu Mar 21 15:47:44 2024) by ROOT version 6.28/04
   TCanvas *posterior = new TCanvas("posterior", "",70,64,700,500);
   posterior->Range(-5e-13,-0.0001619422,4.5e-12,0.00145748);
   posterior->SetFillColor(0);
   posterior->SetBorderMode(0);
   posterior->SetBorderSize(2);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   posterior->SetFrameFillStyle(0);
   posterior->SetFrameBorderMode(0);
   
   TH1D *frame_5e3e14700d50__4 = new TH1D("frame_5e3e14700d50__4","Posterior probability of parameter \"gZ8\"",100,0,4e-12);
   frame_5e3e14700d50__4->SetBinContent(1,0.001295538);
   frame_5e3e14700d50__4->SetMaximum(0.001295538);
   frame_5e3e14700d50__4->SetEntries(1);
   frame_5e3e14700d50__4->SetDirectory(nullptr);
   frame_5e3e14700d50__4->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame_5e3e14700d50__4->SetLineColor(ci);
   frame_5e3e14700d50__4->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e3e14700d50__4->GetXaxis()->SetLabelFont(42);
   frame_5e3e14700d50__4->GetXaxis()->SetTitleOffset(1);
   frame_5e3e14700d50__4->GetXaxis()->SetTitleFont(42);
   frame_5e3e14700d50__4->GetYaxis()->SetTitle("posterior function");
   frame_5e3e14700d50__4->GetYaxis()->SetLabelFont(42);
   frame_5e3e14700d50__4->GetYaxis()->SetTitleFont(42);
   frame_5e3e14700d50__4->GetZaxis()->SetLabelFont(42);
   frame_5e3e14700d50__4->GetZaxis()->SetTitleOffset(1);
   frame_5e3e14700d50__4->GetZaxis()->SetTitleFont(42);
   frame_5e3e14700d50__4->Draw("FUNC");
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx1[104] = { -1.151515e-17, 0, 1.151515e-14, 2.30303e-14, 3.454545e-14, 4.606061e-14, 5.757576e-14, 6.909091e-14, 8.060606e-14, 9.212121e-14, 1.036364e-13, 1.151515e-13, 1.266667e-13, 1.381818e-13, 1.49697e-13, 1.612121e-13, 1.727273e-13,
   1.842424e-13, 1.957576e-13, 2.072727e-13, 2.187879e-13, 2.30303e-13, 2.418182e-13, 2.533333e-13, 2.648485e-13, 2.763636e-13, 2.878788e-13, 2.993939e-13, 3.109091e-13, 3.224242e-13, 3.339394e-13, 3.454545e-13, 3.569697e-13,
   3.684848e-13, 3.8e-13, 3.915152e-13, 4.030303e-13, 4.145455e-13, 4.260606e-13, 4.375758e-13, 4.490909e-13, 4.606061e-13, 4.721212e-13, 4.836364e-13, 4.951515e-13, 5.066667e-13, 5.181818e-13, 5.29697e-13, 5.412121e-13,
   5.527273e-13, 5.642424e-13, 5.757576e-13, 5.872727e-13, 5.987879e-13, 6.10303e-13, 6.218182e-13, 6.333333e-13, 6.448485e-13, 6.563636e-13, 6.678788e-13, 6.793939e-13, 6.909091e-13, 7.024242e-13, 7.139394e-13, 7.254545e-13,
   7.369697e-13, 7.484848e-13, 7.6e-13, 7.715152e-13, 7.830303e-13, 7.945455e-13, 8.060606e-13, 8.175758e-13, 8.290909e-13, 8.406061e-13, 8.521212e-13, 8.636364e-13, 8.751515e-13, 8.866667e-13, 8.981818e-13, 9.09697e-13,
   9.212121e-13, 9.327273e-13, 9.442424e-13, 9.557576e-13, 9.672727e-13, 9.787879e-13, 9.90303e-13, 1.001818e-12, 1.013333e-12, 1.024848e-12, 1.036364e-12, 1.047879e-12, 1.059394e-12, 1.070909e-12, 1.082424e-12, 1.093939e-12,
   1.105455e-12, 1.11697e-12, 1.128485e-12, 1.14e-12, 1.151515e-12, 1.151515e-12, 1.151527e-12 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy1[104] = { 0, 0.001233845, 0.001233835, 0.001233825, 0.001233815, 0.001233616, 0.001233246, 0.001232877, 0.001232488, 0.00123176, 0.001231032, 0.001230303, 0.001229369, 0.001228285, 0.001227201, 0.00122608, 0.001224644,
   0.001223207, 0.001221771, 0.001220115, 0.001218331, 0.001216547, 0.001214709, 0.001212584, 0.001210458, 0.001208333, 0.001205978, 0.001203518, 0.001201057, 0.001198528, 0.00119574, 0.001192953, 0.001190165,
   0.001187143, 0.001184037, 0.001180932, 0.001177745, 0.001174331, 0.001170917, 0.001167503, 0.001163854, 0.001160142, 0.00115643, 0.001152628, 0.001148629, 0.00114463, 0.001140632, 0.001136402, 0.00113213,
   0.001127858, 0.001123489, 0.001118954, 0.00111442, 0.001109885, 0.001105123, 0.001100335, 0.001095547, 0.001090647, 0.001085595, 0.001080543, 0.001075491, 0.001070131, 0.001064754, 0.001059378, 0.001053774,
   0.001047918, 0.001042062, 0.001036207, 0.001029626, 0.001023046, 0.001016465, 0.001009342, 0.001001731, 0.0009941194, 0.0009864384, 0.0009775071, 0.0009685758, 0.0009596445, 0.0009498115, 0.0009393226, 0.0009288337,
   0.0009181667, 0.000905986, 0.0008938053, 0.0008816245, 0.0008683616, 0.0008544674, 0.0008405732, 0.000826426, 0.000810929, 0.000795432, 0.000779935, 0.000763491, 0.0007466101, 0.0007297291, 0.0007126255, 0.0006946865,
   0.0006767475, 0.0006588085, 0.0006403867, 0.0006217924, 0.0006048129, 0.0006048129, 0 };
   TGraph *graph = new TGraph(104,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx1,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy1);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");

   ci = TColor::GetColor("#cccccc");
   graph->SetFillColor(ci);
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",104,-1.151653e-13,1.26668e-12);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB1->SetMaximum(0.00135723);
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
   
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx2[106] = { -4.004e-14, -4e-14, 0, 4e-14, 8e-14, 1.2e-13, 1.6e-13, 2e-13, 2.4e-13, 2.8e-13, 3.2e-13, 3.6e-13, 4e-13, 4.4e-13, 4.8e-13, 5.2e-13, 5.6e-13,
   6e-13, 6.4e-13, 6.8e-13, 7.2e-13, 7.6e-13, 8e-13, 8.4e-13, 8.8e-13, 9.2e-13, 9.6e-13, 1e-12, 1.04e-12, 1.08e-12, 1.12e-12, 1.16e-12, 1.2e-12,
   1.24e-12, 1.28e-12, 1.32e-12, 1.36e-12, 1.4e-12, 1.44e-12, 1.48e-12, 1.52e-12, 1.56e-12, 1.6e-12, 1.64e-12, 1.68e-12, 1.72e-12, 1.76e-12, 1.8e-12, 1.84e-12,
   1.88e-12, 1.92e-12, 1.96e-12, 2e-12, 2.04e-12, 2.08e-12, 2.12e-12, 2.16e-12, 2.2e-12, 2.24e-12, 2.28e-12, 2.32e-12, 2.36e-12, 2.4e-12, 2.44e-12, 2.48e-12,
   2.52e-12, 2.56e-12, 2.6e-12, 2.64e-12, 2.68e-12, 2.72e-12, 2.76e-12, 2.8e-12, 2.84e-12, 2.88e-12, 2.92e-12, 2.96e-12, 3e-12, 3.04e-12, 3.08e-12, 3.12e-12,
   3.16e-12, 3.2e-12, 3.24e-12, 3.28e-12, 3.32e-12, 3.36e-12, 3.4e-12, 3.44e-12, 3.48e-12, 3.52e-12, 3.56e-12, 3.6e-12, 3.64e-12, 3.68e-12, 3.72e-12, 3.76e-12,
   3.8e-12, 3.84e-12, 3.88e-12, 3.92e-12, 3.96e-12, 4e-12, 4e-12, 4.04e-12, 4.04004e-12 };
   Double_t posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy2[106] = { 0, 0.001233845, 0.001233845, 0.001233811, 0.001232526, 0.001229997, 0.001226231, 0.001221242, 0.001215045, 0.001207661, 0.001199115, 0.001189432, 0.001178643, 0.001166784, 0.00115389, 0.00114, 0.001125159,
   0.001109408, 0.001092775, 0.001075225, 0.001056548, 0.001036207, 0.001013348, 0.0009869085, 0.000955884, 0.0009194489, 0.0008771369, 0.0008288729, 0.0007750412, 0.0007164021, 0.0006540878, 0.0005894971, 0.0005241613,
   0.0004596197, 0.000397304, 0.0003384448, 0.0002840028, 0.0002346957, 0.0001909023, 0.0001527866, 0.0001202569, 9.306426e-05, 7.076389e-05, 5.283863e-05, 3.871727e-05, 2.781645e-05, 1.956901e-05, 1.346977e-05, 9.047403e-06,
   5.916428e-06, 3.752412e-06, 2.299707e-06, 1.353449e-06, 7.598528e-07, 4.038925e-07, 2.015609e-07, 9.363076e-08, 4.014787e-08, 1.576573e-08, 5.631316e-09, 1.818312e-09, 5.278989e-10, 1.374025e-10, 3.176183e-11, 6.592406e-12,
   1.213137e-12, 1.9825e-13, 2.862342e-14, 3.697102e-15, 4.216321e-16, 4.264152e-17, 3.828672e-18, 3.046926e-19, 2.154566e-20, 1.23791e-21, 6.744318e-23, 3.258054e-24, 1.396757e-25, 6.423884e-27, 2.250132e-28, 7.033572e-30,
   1.96387e-31, 4.90276e-33, 1.095439e-34, 2.324366e-36, 4.212175e-38, 6.857481e-40, 1.003959e-41, 1.323117e-43, 1.571263e-45, 1.68308e-47, 1.627804e-49, 1.422897e-51, 1.125285e-53, 8.059147e-56, 5.232166e-58, 3.082227e-60,
   1.64915e-62, 8.022069e-65, 3.551061e-67, 1.431813e-69, 5.263539e-72, 1.488048e-73, 1.488048e-73, 1.488048e-73, 0 };
   graph = new TGraph(106,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fx2,posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]_fy2);
   graph->SetName("posteriorfunction_from_nll_model_data_with_constr_approx_Norm[gZ8]");
   graph->SetTitle("Projection of posteriorfunction_from_nll_model_data_with_constr_approx");
   graph->SetFillStyle(1000);

   ci = TColor::GetColor("#0000ff");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2 = new TH1F("Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2","Projection of posteriorfunction_from_nll_model_data_with_constr_approx",106,-4.48048e-13,4.448048e-12);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetMinimum(0);
   Graph_posteriorfunction_from_nll_model_data_with_constr_approx_NormoBgZ8cB2->SetMaximum(0.00135723);
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
   
   TH1D *frame_5e3e14700d50__5 = new TH1D("frame_5e3e14700d50__5","Posterior probability of parameter \"gZ8\"",100,0,4e-12);
   frame_5e3e14700d50__5->SetBinContent(1,0.001295538);
   frame_5e3e14700d50__5->SetMaximum(0.001295538);
   frame_5e3e14700d50__5->SetEntries(1);
   frame_5e3e14700d50__5->SetDirectory(nullptr);
   frame_5e3e14700d50__5->SetStats(0);

   ci = TColor::GetColor("#000099");
   frame_5e3e14700d50__5->SetLineColor(ci);
   frame_5e3e14700d50__5->GetXaxis()->SetTitle("#g_{Z'}^{8}");
   frame_5e3e14700d50__5->GetXaxis()->SetLabelFont(42);
   frame_5e3e14700d50__5->GetXaxis()->SetTitleOffset(1);
   frame_5e3e14700d50__5->GetXaxis()->SetTitleFont(42);
   frame_5e3e14700d50__5->GetYaxis()->SetTitle("posterior function");
   frame_5e3e14700d50__5->GetYaxis()->SetLabelFont(42);
   frame_5e3e14700d50__5->GetYaxis()->SetTitleFont(42);
   frame_5e3e14700d50__5->GetZaxis()->SetLabelFont(42);
   frame_5e3e14700d50__5->GetZaxis()->SetTitleOffset(1);
   frame_5e3e14700d50__5->GetZaxis()->SetTitleFont(42);
   frame_5e3e14700d50__5->Draw("AXISSAME");
   
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
