#include <iostream>
#include <vector>
#include <sys/time.h>
                                                                                      
#include <TH1D.h>
#include <THStack.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TFile.h>
#include <TApplication.h>
#include <TChain.h>
#include <TString.h>
#include <TRandom.h>
#include <TGraphErrors.h>


void MakeProjections()
{

  TString outname = "/Users/vmikola/Downloads/1Doutputs_ToyXP_SKT2K_AsimovA_CRPA_20230703.root";
  
  TString infile_name = "/Users/vmikola/Downloads/ToyXP_SKT2K_AsimovA_CRPA_20230703.root";
  
  TFile* infile = new TFile(infile_name, "open");

  TH2D* numu_2D = new TH2D();
  TH2D* numub_2D = new TH2D();

  numu_2D = (TH2D*)infile->Get("hnumu1R")->Clone();
  numub_2D = (TH2D*)infile->Get("hnumubar1R")->Clone();

  int nx = numub_2D->GetNbinsX();
  
  TH1D *numu = numu_2D->ProjectionX("hnumu",0,nx);
  TH1D *numub = numub_2D->ProjectionX("hnumub",0,nx);

  TFile* outfile = new TFile(outname, "recreate");

  numu->Write();
  numub->Write();

  outfile->Close();
  
  
}
