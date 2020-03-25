#include "histogram.hpp"

Histogram::Histogram(const std::string& output_file) {
  RootOutputFile = std::make_shared<TFile>(output_file.c_str(), "RECREATE");
  def = std::make_shared<TCanvas>("def");
  
  ft_cal_energy = std::make_shared<TH1D>("ft_cal_energy","ft_cal_energy", bins, zero, q2_max);
  _21_ft_cal_energy = std::make_shared<TH1D>("_21_ft_cal_energy","_21_ft_cal_energy", bins, zero, q2_max);
  _n21_ft_cal_energy = std::make_shared<TH1D>("_n21_ft_cal_energy","_n21_ft_cal_energy", bins, zero, q2_max);
  trigger_vs_ft_cal_energy = std::make_shared<TH2D>("trigger_vs_ft_cal_energy","trigger_vs_ft_cal_energy", bins, zero, q2_max, bins, zero, q2_max);
  
}

Histogram::~Histogram() { this->Write(); }

void Histogram::Write() {
  std::cout << GREEN << "Writting" << DEF << std::endl;
  
  std::cerr << BOLDBLUE << "Write_trigger()" << DEF << std::endl;
  TDirectory* trigger_folder = RootOutputFile->mkdir("trigger_folder");
  trigger_folder->cd();
  Write_trigger();
  
  
  std::cerr << BOLDBLUE << "Done Writing!!!" << DEF << std::endl;
}

void Histogram::Fill_trigger(const std::shared_ptr<Reaction>& _d) {

  if(!std::isnan(_d->trigger())&& !std::isnan(_d->ft_cal_energy())){

  ft_cal_energy->Fill(_d->ft_cal_energy());

  if (int(_d->trigger()) & (1<<21))_21_ft_cal_energy->Fill(_d->ft_cal_energy());
  else   _n21_ft_cal_energy->Fill(_d->ft_cal_energy());

  trigger_vs_ft_cal_energy->Fill(_d->trigger(),_d->ft_cal_energy());
 }
}

void Histogram::Write_trigger(){
        ft_cal_energy->SetXTitle("ft_cal_energy");
        ft_cal_energy->Write();

        _21_ft_cal_energy->SetXTitle("_21_ft_cal_energy");
        _21_ft_cal_energy->Write();

        _n21_ft_cal_energy->SetXTitle("_n21_ft_cal_energy");
        _n21_ft_cal_energy->Write();

        trigger_vs_ft_cal_energy->SetXTitle("trigger bit");
        trigger_vs_ft_cal_energy->SetYTitle("ft_cal_energy");
        trigger_vs_ft_cal_energy->Write();
}
