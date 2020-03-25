#ifndef HIST_H_GUARD
#define HIST_H_GUARD
#include <mutex>
#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TH1.h"
#include "TH2.h"
#include "THnSparse.h"
#include "TLegend.h"
#include "TLorentzVector.h"
#include "TPaveStats.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TThread.h"

using namespace std;

using TH2D_ptr = std::shared_ptr<TH2D>;
using TH1D_ptr = std::shared_ptr<TH1D>;

class Histogram {
 protected:
  std::shared_ptr<TFile> RootOutputFile;
  std::shared_ptr<TCanvas> def;
 
  int bins = 500;
  double q2_max = 12.0;
  double zero = 0.0;
  
  //trigger
  TH1D_ptr ft_cal_energy; 
  TH1D_ptr _21_ft_cal_energy; 
  TH1D_ptr _n21_ft_cal_energy; 
  TH2D_ptr trigger_vs_ft_cal_energy;
  
 public:
  Histogram(const std::string& output_file);
  ~Histogram();
  void Fill_trigger(const std::shared_ptr<Branches12>& _d);
  void Write_trigger();
  
  void Write();
};
#endif
