#include "TH1D.h"
#include "TList.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TLegend.h"
#include "THStack.h"

#include <iostream>
#include <vector>

//void getSampleHists(TFile *fFHC, TFile *fRHC, std::vector<TH1D*> &hist_vec){
void getSampleHists(TFile *fFHC, std::vector<TH1D*> &hist_vec){
  
  TH1D* numu = new TH1D();
  TH1D* numub = new TH1D();
  //TH1D* nue = new TH1D();
  //TH1D* nueb = new TH1D();
  //TH1D* nue1pi = new TH1D();
  
  numu = (TH1D*)fFHC->Get("numu_asimov")->Clone();
  //nue = (TH1D*)fFHC->Get("nue_nominal_hist")->Clone();
  //numub = (TH1D*)fRHC->Get("numu_nominal_hist")->Clone("numub");
  numub = (TH1D*)fFHC->Get("numubar_asimov")->Clone();
  //nueb = (TH1D*)fRHC->Get("nue_nominal_hist")->Clone("nueb");
  //nueb = (TH1D*)fFHC->Get("nue_nominal_hist")->Clone("nueb");
  //nue1pi = (TH1D*)fFHC->Get("nue1pi_nominal_hist")->Clone();

  numu->SetDirectory(0);
  numub->SetDirectory(0);
  //nue->SetDirectory(0);
  //nueb->SetDirectory(0);
  //nue1pi->SetDirectory(0);

  //Now pushing back vector
  std::cout << "Now pushing back vector with histos" << std::endl;
  hist_vec.push_back(numu);
  hist_vec.push_back(numub);
  //hist_vec.push_back(nue);
  //hist_vec.push_back(nueb);
  //hist_vec.push_back(nue1pi); 
  
   bool found_all = true;
  //Now a quick check to make sure we've got all the FDS histograms
  for(int sample_i = 0 ; sample_i < 2 ; sample_i++){
    std::cout << sample_i << std::endl;
    if(!hist_vec[sample_i]){
  	  std::cout << "Couldn't find sample " << sample_i << std::endl;
  	  found_all = false;
  	}
  	else{std::cout << "Successfully found sample " << sample_i << std::endl;}
   }
  

   if(!found_all){std::cout << "Didn't find all the SK FDS sample histograms so I'm out of here!" << std::endl; exit(1);}
   
  return;
}

//void getSampleStacks(TFile *fFHC, TFile *fRHC, std::vector<THStack*> &hist_vec){

// THStack* numu = new THStack();
// THStack* numub = new THStack();
// THStack* nue = new THStack();
// THStack* nueb = new THStack();
// THStack* nue1pi = new THStack();
  
// numu = (THStack*)fFHC->Get("modes_numu")->Clone();
// nue = (THStack*)fFHC->Get("modes_nue")->Clone();
//  numub = (THStack*)fRHC->Get("modes_numu")->Clone("modes_numub");
// nueb = (THStack*)fRHC->Get("modes_nue")->Clone("modes_nueb");
// nue1pi = (THStack*)fFHC->Get("modes_nue1pi")->Clone();

/*  numu->SetDirectory(0)
  numub->SetDirectory(0);
  nue->SetDirectory(0);
  nueb->SetDirectory(0);
  nue1pi->SetDirectory(0);
  */


  //Now pushing back vector
// std::cout << "Now pushing back vector with histos" << std::endl;
// hist_vec.push_back(numu);
// hist_vec.push_back(numub);
// hist_vec.push_back(nue);
// hist_vec.push_back(nueb);
//hist_vec.push_back(nue1pi); 

//bool found_all = true;
  //Now a quick check to make sure we've got all the FDS histograms
  //for(int sample_i = 0 ; sample_i < hist_vec.size() ; sample_i++){
//if(!hist_vec[sample_i]){
//	  std::cout << "Couldn't find sample " << sample_i << std::endl;
//	  found_all = false;
//	}
//	else{std::cout << "Successfully found sample " << sample_i << std::endl;}
//}

//if(!found_all){std::cout << "Didn't find all the SK FDS sample histograms so I'm out of here!" << std::endl; exit(1);}

//return;
//}


//void SK_FDS_comp_pos_pred_overlay(TString SK_FDS_FHC_name, TString SK_FDS_RHC_name, TString FDS_label, TString SK_nom_FHC_name,  TString SK_nom_RHC_name, TString posPredFile_name, TString comp_label, TString outname, TString pos_pred_title, bool do_ratio_to_nom=false){
void SK_FDS_comp_pos_pred_overlay(TString SK_FDS_FHC_name, TString FDS_label, TString posPredFile_name, TString comp_label, TString outname, TString pos_pred_title, bool do_ratio_to_nom=false){

  std::cout << "OUTNAME IS " << outname << std::endl;

  if(do_ratio_to_nom){std::cout << "MKAING RATIO PLOTS TO NOMINAL FILES!!!" << std::endl;}
  else{std::cout << "NOT MAKING RATIO PLOTS LIKE A GOOD BOY!!" << std::endl;}

  gStyle->SetOptStat("0");
  gStyle->SetNumberContours(255);
  gStyle->SetPalette(55);
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetPadRightMargin(0.16);
  gStyle->SetPadBottomMargin(0.12);

  //FDS files
  TFile *fSK_FDS_FHC = new TFile(SK_FDS_FHC_name, "READ");
  //TFile *fSK_FDS_RHC = new TFile(SK_FDS_RHC_name, "READ");
  
  //nominal files
  //TFile *fSK_nom_FHC = new TFile(SK_nom_FHC_name, "READ");
  //TFile *fSK_nom_RHC = new TFile(SK_nom_RHC_name, "READ");

  //Pos Pred file
  TFile *fPosPred = new TFile(posPredFile_name, "READ");

  int nSamples = 5;

  // TString SKSampleNames[] = {
  //	"numu",
  //	"numub",
  //	"nue",
  //	"nueb",
  //	"nue1pi"};
  
TString SKSampleNames[] = {
	"numu",
	"numub"};
  
//  TString SKSampleTitles[] = {
//	"FHC 1R#mu",
//	"RHC 1R#mu",
//	"FHC 1Re",
//	"RHC 1Re",
//	"FHC 1Re1de"};

    
  TString SKSampleTitles[] = {
	"FHC 1R#mu",
	"RHC 1R#mu"};

  //double SKXaxisRange[] = {
  //	3.,
  //	3.,
  //	1.25,
  //	1.25,
  //	1.25};

   double SKXaxisRange[] = {
	3.,
	3.};

  std::cout << "Now trying to get histograms from FDS file" << std::endl;


  /*
   *
  // Now get the histograms from the files
  // 
  */

  
  std::vector<TH1D*> FDS_hists;
  getSampleHists(fSK_FDS_FHC, FDS_hists);

  //std::vector<TH1D*> nom_hists;
  //getSampleHists(fSK_nom_FHC, nom_hists);

  //Get the posterior predictive spectra from file

  //TString sample[] = {"numu", "numubar", "nue", "nuebar", "nue1pi"};

  TString sample[] = {"numu", "numubar"};

  //Make a nice TLegend for the plots
  FDS_hists[0]->SetLineColor(kRed);
  //nom_hists[0]->SetLineColor(kBlack);
  TLegend* leg = new TLegend(0.63, 0.60, 0.78, 0.88);
  leg->AddEntry(FDS_hists[0], FDS_label, "l");
  //leg->AddEntry(nom_hists[0], comp_label, "l");
  leg->SetTextSize(0.035);
  leg->SetBorderSize(0);
  
  TCanvas *c1 = new TCanvas("c1", "c1", 800,600);
  c1->cd();

  TPad* pad1;
  TPad* pad2;

//pad1 = new TPad("pad1", "pad1", 0, 0.35, 1.0, 1.0);
  pad1 = new TPad("pad1", "pad1", 0, 0.1, 1.0, 1.0);
  //pad1->SetBottomMargin(0.035);;
  pad1->SetBottomMargin(0.1);;

  pad1->SetGridx(0);
  pad1->SetGridy(0);
  pad1->SetTicks(1,1);

//  pad1->SetPadTickY(1);

  pad1->Draw();
  c1->cd();

  pad2 = new TPad("pad2", "pad2", 0, 0, 0, 0);
  //pad2 = new TPad("pad2", "pad2", 0, 0.1, 1.0, 1.0);
  pad2->SetGridx(1);
  pad2->SetGridy(1);
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.15);
  pad2->SetTopMargin(0.03);
  //pad2->Draw();
  c1->cd();
  
  //xc1->Print(outname+".pdf[");
  
  //for(int sample_i = 0 ; sample_i < FDS_hists.size(); sample_i++){
 for(int sample_i = 0 ; sample_i < 1; sample_i++){
  
   std::cout << "I got here to sample " <<  sample_i <<  std::endl;

   std::cout << "sk_"+sample[sample_i]+sample_i << std::endl;

        TH1* hist = 0;
        //TGraphErrors* hist = 0;
	//fPosPred->GetObject("sk_"+sample[sample_i]+sample_i, hist);
	fPosPred->GetObject("sk_"+sample[sample_i], hist);
	
	if(hist){
	  std::cout << "Successfully found pos pred sk_"+sample[sample_i] << std::endl;
	}

	//Make TGraph look pretty
	hist->SetFillColor(kBlue);
	hist->SetFillColorAlpha(kBlue, 0.8);
	hist->SetFillStyle(3001);

	FDS_hists[sample_i]->SetLineColor(kRed);
        FDS_hists[sample_i]->SetMarkerStyle(20);
        FDS_hists[sample_i]->SetMarkerColor(kRed+2);
	//nom_hists[sample_i]->SetLineColor(kBlack);

	//	double y_max = 0;
	//if(FDS_hists[sample_i]->GetMaximum() > nom_hists[sample_i]->GetMaximum()){y_max = FDS_hists[sample_i]->GetMaximum()*1.1;}
	//else{y_max = nom_hists[sample_i]->GetMaximum()*1.1;}

        //double y_max = FDS_hists[sample_i]->GetMaximum()*1.1;
	double y_max = 30;
	 
	pad1->cd();
	FDS_hists[sample_i]->SetTitle(SKSampleTitles[sample_i]);
	FDS_hists[sample_i]->GetXaxis()->SetRangeUser(0, SKXaxisRange[sample_i]);
	FDS_hists[sample_i]->GetYaxis()->SetRangeUser(0, y_max);
	FDS_hists[sample_i]->GetXaxis()->SetTitle("Reconstructed Neutrino Energy [GeV]");
	FDS_hists[sample_i]->GetYaxis()->SetTitle("Events");
	//FDS_hists[sample_i]->Draw("P");
	FDS_hists[sample_i]->Draw();
	
	//If you aren't doing the ratio then don't bother drawing the nominal which you'd be taking the ratio relative to
	//if(do_ratio_to_nom){
	//nom_hists[sample_i]->Draw("HIST SAMES");
	//}
	 hist->Draw("E2 SAMES");
	 
	if(sample_i==0){
	  leg->AddEntry(hist, pos_pred_title, "f");
	}
	leg->Draw();



	if(do_ratio_to_nom){
	  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	  std::cout << "Making ratio plots to nominal just for you" << std::endl;
	  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}
	else{
	  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	  std::cout << "Making ratio plots to SK FDS just for you" << std::endl;
	  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	}

	//Make ratios
	//TGraphErrors *ratio_graph = (TGraphErrors*)hist->Clone();
	TH1D* ratio_graph = (TH1D*)hist->Clone();
	TH1D* ratio = (TH1D*)FDS_hists[sample_i]->Clone();
	ratio->Reset("ICES");
	//ratio_graph->Reset("ICES");

	// max value to use to set y-axis range later
	double ratio_max = 1;
	double ratio_min = 1;

	//	for(int bin_i = 0 ; bin_i < ratio_graph->GetN() ; ++bin_i){
	for(int bin_i = 0 ; bin_i < ratio_graph->GetNbinsX(); ++bin_i){

	  int hist_bin = bin_i + 1;
	  double bin_centre, nom, bin_width;
	  // if(do_ratio_to_nom){
	  //	bin_centre = nom_hists[sample_i]->GetBinCenter(hist_bin);
	  //		nom = nom_hists[sample_i]->GetBinContent(hist_bin);
		//	    bin_width = nom_hists[sample_i]->GetBinWidth(hist_bin);
	  //}
	  //else{
	  bin_centre = FDS_hists[sample_i]->GetBinCenter(hist_bin);
	  nom = FDS_hists[sample_i]->GetBinContent(hist_bin);
	  //bin_width = nom_hists[sample_i]->GetBinWidth(hist_bin);
	  bin_width = FDS_hists[sample_i]->GetBinWidth(hist_bin);
	  // }

	  double FDS_val = FDS_hists[sample_i]->GetBinContent(hist_bin);

	  //double pos_pred_val = hist->GetPointY(bin_i);
	  double  pos_pred_val = hist->GetBinContent(hist_bin);

	  
	  std::cout << "~~~~~~~" << std::endl;
	  std::cout << "BIN center for histogram is " << bin_centre << std::endl;
	  std::cout << "POINT x-val for graph is " << hist->GetBinContent(hist_bin) << std::endl;
	  std::cout << "FDS_val = " << FDS_val << std::endl;
	  std::cout << "pos_pred_val = " << pos_pred_val << std::endl;
	  std::cout << "nom = " << nom << std::endl;
	  

	  double ratio_to_nom = 1.;
	  double ratio_val = 1.;
	  double error = 0;

	  //  if(nom > 0.01 && FDS_hists[sample_i]->GetBinContent(hist_bin) > 0.01){
	  //	ratio_to_nom = FDS_hists[sample_i]->GetBinContent(hist_bin) / nom; 
		//double error = (nom/pos_pred_val)*sqrt(pow(sqrt(nom)/nom,2) + pow(hist->GetErrorY(bin_i)/pos_pred_val,2));
	  //	error = (nom/pos_pred_val)*sqrt(pow(hist->GetErrorY(bin_i)/pos_pred_val,2));


	  //	ratio_val = hist->GetPointY(bin_i) / nom;
	  //	ratio->SetBinContent(hist_bin, ratio_to_nom);
	  //	std::cout << "Histogram has value " << ratio_to_nom << std::endl;  
	  //	std::cout << "Graph has value " << ratio_val << std::endl;
	  //	ratio_graph->SetPoint(bin_i, bin_centre, ratio_val);
	  //	ratio_graph->SetPointError(bin_i, bin_width/2, error);
	  //	std::cout << "Error is " << error << std::endl; 
	  // }
	  // else{
		ratio->SetBinContent(hist_bin, 1.0);
		//ratio_graph->SetPoint(bin_i, bin_centre, 1.);
		ratio_graph->SetBinContent(bin_i, bin_centre, 1.);
		//ratio_graph->SetPointError(bin_i, bin_width/2, 0);
		ratio_graph->SetBinError(bin_i, bin_width/2);
		//  }

	//Update the maximum value
	  if(bin_centre < SKXaxisRange[sample_i]){
		if(ratio_val + error > ratio_max){ratio_max = ratio_val + error;}
		if(ratio_val - error < ratio_min){ratio_min = ratio_val - error;}
	  }

	}


	pad2->cd();
	if(sample_i == 0 || sample_i == 1){ratio->GetXaxis()->SetRangeUser(0,SKXaxisRange[sample_i]);}
	ratio->SetLabelSize(0.08, "xy");
	ratio->SetTitleSize(0.08, "xy");
	ratio->SetTitleOffset(0.7, "xy");

	double range_to_use;
	if(ratio_max - 1 > abs(1 - ratio_min)){range_to_use = ratio_max - 1;}
	else{range_to_use = abs(1 - ratio_min);}
	
	std::cout << "Setting range to " << 1 - range_to_use*1.1 << " to " << 1 + range_to_use*1.1 << std::endl;
	ratio->GetYaxis()->SetRangeUser(1 - range_to_use*1.1, 1 + range_to_use*1.1);
	ratio->SetTitle("");

	if(do_ratio_to_nom){
	  ratio->GetYaxis()->SetTitle("Ratio to post-BANFF");
	}
	else{
	  ratio->GetYaxis()->SetTitle("Ratio to SK FDS");
	}

	ratio->GetXaxis()->SetTitle("Reconstructed Neutrino energy [GeV]");
	ratio->Draw("HIST");
	ratio_graph->SetTitle("");
	ratio_graph->SetLineColor(kBlue+1);
	ratio_graph->SetMarkerColor(kBlue+1);
	ratio_graph->Draw("E SAMES");

	c1->Print(outname+".pdf");

  }
  c1->Print(outname+".pdf]");

  /*
  /////////////////////////
  // Now get the plots broken-down by mode 
  //
  /////////////////////////

  TString ModeNames[] = {
	"",
	"_CCQE",
	"_2p2h",
	"_CC1pi",
	"_CCcoh",
	"_CCMpi",
	"_CCDIS",
	"_CCMisc",
	"_NC1pi0",
	"_NC1pipm",
	"_NCcoh",
	"_NCoth",
	"_NC1gam"};

  TString NDModeTitles[] = {
	"Total",
	"CCQE",
	"2p2h",
	"CC 1#pi^{#pm,0}",
	"CC coherent",
	"CC multi-#pi",
	"CC DIS",
	"CC Misc.",
	"NC 1#pi^{0}",
	"NC 1#pi^{#pm}",
	"NC coherent",
        "NC other",
	"NC 1#gamma"};

  int nModes = 13;

  std::vector<THStack*> FDS_stacks;
  std::vector<THStack*> nom_stacks;

  getSampleStacks(fSK_FDS_FHC, fSK_FDS_RHC, FDS_stacks);
  getSampleStacks(fSK_nom_FHC, fSK_nom_RHC, nom_stacks);


  std::cout << "Found " << FDS_stacks[0]->GetNhists() << " modes" << std::endl;

  c1->Draw("test_sample_modes.pdf[");
  for(int sample_i = 0 ; sample_i < FDS_stacks.size() ; sample_i++){

	  TList * list = FDS_stacks[sample_i]->GetHists();
	for(int mode_i = 0 ; mode_i < FDS_stacks[sample_i]->GetNhists() ; mode_i++){

	  std::cout << "Name of mode_i is " << list->At(mode_i)->GetName() << std::endl;
	  //std::cout << "Draw mode " << mode_i << std::endl;
	  FDS_stacks[sample_i]->Draw();
	  nom_stacks[sample_i]->Draw();
	  TH1D* FDS_mode = (TH1D*)FDS_stacks[sample_i]->GetHistogram()->Clone();
	  TH1D* nom_mode = (TH1D*)nom_stacks[sample_i]->GetHistogram()->Clone();

	  FDS_mode->Draw("HIST");
	  nom_mode->Draw("HIST SAMES");

	  std::cout << "Integral for FDS is " << FDS_mode->Integral() << std::endl;
	  std::cout << "Integral for nom is " << nom_mode->Integral() << std::endl;
	  c1->Print("test_sample_modes.pdf");

	}
  }
	c1->Draw("test_sample_modes.pdf]");
	*/

  return;
 }


