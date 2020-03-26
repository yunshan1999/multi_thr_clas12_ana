#include "histogram.hpp"

Histogram::Histogram(const std::string& output_file) {
  RootOutputFile = std::make_shared<TFile>(output_file.c_str(), "RECREATE");
  def = std::make_shared<TCanvas>("def");
  
  ec_tot_energy = std::make_shared<TH1D>("ec_tot_energy","ec_tot_energy", bins, zero, q2_max);
  _21_ec_tot_energy = std::make_shared<TH1D>("_21_ec_tot_energy","_21_ec_tot_energy", bins, zero, q2_max);
  _n21_ec_tot_energy = std::make_shared<TH1D>("_n21_ec_tot_energy","_n21_ec_tot_energy", bins, zero, q2_max);
  trigger_vs_ec_tot_energy = std::make_shared<TH2D>("trigger_vs_ec_tot_energy","trigger_vs_ec_tot_energy", 32, zero, 31, bins, zero, q2_max);
  
  ec_pcal_energy = std::make_shared<TH1D>("ec_pcal_energy","ec_pcal_energy", bins, zero, q2_max);
  _21_ec_pcal_energy = std::make_shared<TH1D>("_21_ec_pcal_energy","_21_ec_pcal_energy", bins, zero, q2_max);
  _n21_ec_pcal_energy = std::make_shared<TH1D>("_n21_ec_pcal_energy","_n21_ec_pcal_energy", bins, zero, q2_max);
  trigger_vs_ec_pcal_energy = std::make_shared<TH2D>("trigger_vs_ec_pcal_energy","trigger_vs_ec_pcal_energy", 32, zero, 31, bins, zero, q2_max);
  
  ec_ecin_energy = std::make_shared<TH1D>("ec_ecin_energy","ec_ecin_energy", bins, zero, q2_max);
  _21_ec_ecin_energy = std::make_shared<TH1D>("_21_ec_ecin_energy","_21_ec_ecin_energy", bins, zero, q2_max);
  _n21_ec_ecin_energy = std::make_shared<TH1D>("_n21_ec_ecin_energy","_n21_ec_ecin_energy", bins, zero, q2_max);
  trigger_vs_ec_ecin_energy = std::make_shared<TH2D>("trigger_vs_ec_ecin_energy","trigger_vs_ec_ecin_energy", 32, zero, 31, bins, zero, q2_max);
  
  ec_ecout_energy = std::make_shared<TH1D>("ec_ecout_energy","ec_ecout_energy", bins, zero, q2_max);
  _21_ec_ecout_energy = std::make_shared<TH1D>("_21_ec_ecout_energy","_21_ec_ecout_energy", bins, zero, q2_max);
  _n21_ec_ecout_energy = std::make_shared<TH1D>("_n21_ec_ecout_energy","_n21_ec_ecout_energy", bins, zero, q2_max);
  trigger_vs_ec_ecout_energy = std::make_shared<TH2D>("trigger_vs_ec_ecout_energy","trigger_vs_ec_ecout_energy", 32, zero, 31, bins, zero, q2_max);
  
  sc_ftof_1a_energy = std::make_shared<TH1D>("sc_ftof_1a_energy","sc_ftof_1a_energy", bins, zero, q2_max);
  _21_sc_ftof_1a_energy = std::make_shared<TH1D>("_21_sc_ftof_1a_energy","_21_sc_ftof_1a_energy", bins, zero, q2_max);
  _n21_sc_ftof_1a_energy = std::make_shared<TH1D>("_n21_sc_ftof_1a_energy","_n21_sc_ftof_1a_energy", bins, zero, q2_max);
  trigger_vs_sc_ftof_1a_energy = std::make_shared<TH2D>("trigger_vs_sc_ftof_1a_energy","trigger_vs_sc_ftof_1a_energy", 32, zero, 31, bins, zero, q2_max);
  
  sc_ftof_1b_energy = std::make_shared<TH1D>("sc_ftof_1b_energy","sc_ftof_1b_energy", bins, zero, q2_max);
  _21_sc_ftof_1b_energy = std::make_shared<TH1D>("_21_sc_ftof_1b_energy","_21_sc_ftof_1b_energy", bins, zero, q2_max);
  _n21_sc_ftof_1b_energy = std::make_shared<TH1D>("_n21_sc_ftof_1b_energy","_n21_sc_ftof_1b_energy", bins, zero, q2_max);
  trigger_vs_sc_ftof_1b_energy = std::make_shared<TH2D>("trigger_vs_sc_ftof_1b_energy","trigger_vs_sc_ftof_1b_energy", 32, zero, 31, bins, zero, q2_max);
  
  sc_ftof_2_energy = std::make_shared<TH1D>("sc_ftof_2_energy","sc_ftof_2_energy", bins, zero, q2_max);
  _21_sc_ftof_2_energy = std::make_shared<TH1D>("_21_sc_ftof_2_energy","_21_sc_ftof_2_energy", bins, zero, q2_max);
  _n21_sc_ftof_2_energy = std::make_shared<TH1D>("_n21_sc_ftof_2_energy","_n21_sc_ftof_2_energy", bins, zero, q2_max);
  trigger_vs_sc_ftof_2_energy = std::make_shared<TH2D>("trigger_vs_sc_ftof_2_energy","trigger_vs_sc_ftof_2_energy", 32, zero, 31, bins, zero, q2_max);
  
  sc_ctof_energy = std::make_shared<TH1D>("sc_ctof_energy","sc_ctof_energy", bins, zero, q2_max);
  _21_sc_ctof_energy = std::make_shared<TH1D>("_21_sc_ctof_energy","_21_sc_ctof_energy", bins, zero, q2_max);
  _n21_sc_ctof_energy = std::make_shared<TH1D>("_n21_sc_ctof_energy","_n21_sc_ctof_energy", bins, zero, q2_max);
  trigger_vs_sc_ctof_energy = std::make_shared<TH2D>("trigger_vs_sc_ctof_energy","trigger_vs_sc_ctof_energy", 32, zero, 31, bins, zero, q2_max);
  
  sc_cnd_energy = std::make_shared<TH1D>("ft_cal_energy","ft_cal_energy", bins, zero, q2_max);
  _21_sc_cnd_energy = std::make_shared<TH1D>("_21_sc_cnd_energy","_21_sc_cnd_energy", bins, zero, q2_max);
  _n21_sc_cnd_energy = std::make_shared<TH1D>("_n21_sc_cnd_energy","_n21_sc_cnd_energy", bins, zero, q2_max);
  trigger_vs_sc_cnd_energy = std::make_shared<TH2D>("trigger_vs_sc_cnd_energy","trigger_vs_sc_cnd_energy", 32, zero, 31, bins, zero, q2_max);
  
  ft_cal_energy = std::make_shared<TH1D>("ft_cal_energy","ft_cal_energy", bins, zero, q2_max);
  _21_ft_cal_energy = std::make_shared<TH1D>("_21_ft_cal_energy","_21_ft_cal_energy", bins, zero, q2_max);
  _n21_ft_cal_energy = std::make_shared<TH1D>("_n21_ft_cal_energy","_n21_ft_cal_energy", bins, zero, q2_max);
  trigger_vs_ft_cal_energy = std::make_shared<TH2D>("trigger_vs_ft_cal_energy","trigger_vs_ft_cal_energy", 32, zero, 31, bins, zero, q2_max);
  
  ft_hodo_energy = std::make_shared<TH1D>("ft_hodo_energy","ft_hodo_energy", bins, zero, q2_max);
  _21_ft_hodo_energy = std::make_shared<TH1D>("_21_ft_hodo_energy","_21_ft_hodo_energy", bins, zero, q2_max);
  _n21_ft_hodo_energy = std::make_shared<TH1D>("_n21_ft_hodo_energy","_n21_ft_hodo_energy", bins, zero, q2_max);
  trigger_vs_ft_hodo_energy = std::make_shared<TH2D>("trigger_vs_ft_hodo_energy","trigger_vs_ft_hodo_energy", 32, zero, 31, bins, zero, q2_max);
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

void Histogram::Fill_trigger(const std::shared_ptr<Branches12>& _d,int i) {
  if(!std::isnan(_d->trigger())){ int T=int(_d->trigger());
  if(!std::isnan(_d->ec_tot_energy(i))){
  ec_tot_energy->Fill(_d->ec_tot_energy(i));
  if (T & (1<<21))_21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  else   _n21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ft_cal_energy->Fill(flag ,_d->ft_cal_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  if (T & (1<<21))_21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  else   _n21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ec_pcal_energy->Fill(flag ,_d->ec_pcal_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  if (T & (1<<21))_21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  else   _n21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ec_ecin_energy->Fill(flag ,_d->ec_ecin_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  if (T & (1<<21))_21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  else   _n21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ec_ecout_energy->Fill(flag ,_d->ec_ecout_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  if (T & (1<<21))_21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  else   _n21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_sc_ftof_1a_energy->Fill(flag ,_d->sc_ftof_1a_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  if (T & (1<<21))_21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  else   _n21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_sc_ftof_1b_energy->Fill(flag ,_d->sc_ftof_1b_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  if (T & (1<<21))_21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  else   _n21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_sc_ftof_2_energy->Fill(flag ,_d->sc_ftof_2_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  if (T & (1<<21))_21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  else   _n21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_sc_ctof_energy->Fill(flag ,_d->sc_ctof_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  int T=int(_d->trigger());
  sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  if (T & (1<<21))_21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  else   _n21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_sc_cnd_energy->Fill(flag ,_d->sc_cnd_energy(i));
 }
  
    if(!std::isnan(_d->trigger())&& !std::isnan(_d->ft_cal_energy(i))){
  int T=int(_d->trigger());
  ft_cal_energy->Fill(_d->ft_cal_energy(i));
  if (T & (1<<21))_21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  else   _n21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ft_cal_energy->Fill(flag ,_d->ft_cal_energy(i));
 }
  
    if(!std::isnan(_d->trigger())){
  ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  if (T & (1<<21))_21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  else   _n21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) trigger_vs_ft_hodo_energy->Fill(flag ,_d->ft_hodo_energy(i));
 }
}
}

void Histogram::Write_trigger(){
        ec_tot_energy->SetXTitle("ec_tot_energy(GeV)");
        ec_tot_energy->Write();
        _21_ec_tot_energy->SetXTitle("_21_ec_tot_energy(GeV)");
        _21_ec_tot_energy->Write();
        _n21_ec_tot_energy->SetXTitle("_n21_ec_tot_energy(GeV)");
        _n21_ec_tot_energy->Write();
        trigger_vs_ec_tot_energy->SetXTitle("trigger bit");
        trigger_vs_ec_tot_energy->SetYTitle("ec_tot_energy(GeV)");
        trigger_vs_ec_tot_energy->Write();
  
        ec_pcal_energy->SetXTitle("ec_pcal_energy(GeV)");
        ec_pcal_energy->Write();
        _21_ec_pcal_energy->SetXTitle("_21_ec_pcal_energy(GeV)");
        _21_ec_pcal_energy->Write();
        _n21_ec_pcal_energy->SetXTitle("_n21_ec_pcal_energy(GeV)");
        _n21_ec_pcal_energy->Write();
        trigger_vs_ec_pcal_energy->SetXTitle("trigger bit");
        trigger_vs_ec_pcal_energy->SetYTitle("ec_pcal_energy(GeV)");
        trigger_vs_ec_pcal_energy->Write();
  
        ec_ecin_energy->SetXTitle("ec_ecin_energy(GeV)");
        ec_ecin_energy->Write();
        _21_ec_ecin_energy->SetXTitle("_21_ec_ecin_energy(GeV)");
        _21_ec_ecin_energy->Write();
        _n21_ec_ecin_energy->SetXTitle("_n21_ec_ecin_energy(GeV)");
        _n21_ec_ecin_energy->Write();
        trigger_vs_ec_ecin_energy->SetXTitle("trigger bit");
        trigger_vs_ec_ecin_energy->SetYTitle("ec_ecin_energy(GeV)");
        trigger_vs_ec_ecin_energy->Write();
  
        ec_ecout_energy->SetXTitle("ec_ecout_energy(GeV)");
        ec_ecout_energy->Write();
        _21_ec_ecout_energy->SetXTitle("_21_ec_ecout_energy(GeV)");
        _21_ec_ecout_energy->Write();
        _n21_ec_ecout_energy->SetXTitle("_n21_ec_ecout_energy(GeV)");
        _n21_ec_ecout_energy->Write();
        trigger_vs_ec_ecout_energy->SetXTitle("trigger bit");
        trigger_vs_ec_ecout_energy->SetYTitle("ec_ecout_energy(GeV)");
        trigger_vs_ec_ecout_energy->Write();
  
        sc_ftof_1a_energy->SetXTitle("sc_ftof_1a_energy(GeV)");
        sc_ftof_1a_energy->Write();
        _21_sc_ftof_1a_energy->SetXTitle("_21_sc_ftof_1a_energy(GeV)");
        _21_sc_ftof_1a_energy->Write();
        _n21_sc_ftof_1a_energy->SetXTitle("_n21_sc_ftof_1a_energy(GeV)");
        _n21_sc_ftof_1a_energy->Write();
        trigger_vs_sc_ftof_1a_energy->SetXTitle("trigger bit");
        trigger_vs_sc_ftof_1a_energy->SetYTitle("sc_ftof_1a_energy(GeV)");
        trigger_vs_sc_ftof_1a_energy->Write();
  
        sc_ftof_1b_energy->SetXTitle("sc_ftof_1b_energy(GeV)");
        sc_ftof_1b_energy->Write();
        _21_sc_ftof_1b_energy->SetXTitle("_21_sc_ftof_1b_energy(GeV)");
        _21_sc_ftof_1b_energy->Write();
        _n21_sc_ftof_1b_energy->SetXTitle("_n21_sc_ftof_1b_energy(GeV)");
        _n21_sc_ftof_1b_energy->Write();
        trigger_vs_sc_ftof_1b_energy->SetXTitle("trigger bit");
        trigger_vs_sc_ftof_1b_energy->SetYTitle("sc_ftof_1b_energy(GeV)");
        trigger_vs_sc_ftof_1b_energy->Write();
  
        sc_ftof_2_energy->SetXTitle("sc_ftof_2_energy(GeV)");
        sc_ftof_2_energy->Write();
        _21_sc_ftof_2_energy->SetXTitle("_21_sc_ftof_2_energy(GeV)");
        _21_sc_ftof_2_energy->Write();
        _n21_sc_ftof_2_energy->SetXTitle("_n21_sc_ftof_2_energy(GeV)");
        _n21_sc_ftof_2_energy->Write();
        trigger_vs_sc_ftof_2_energy->SetXTitle("trigger bit");
        trigger_vs_sc_ftof_2_energy->SetYTitle("sc_ftof_2_energy(GeV)");
        trigger_vs_sc_ftof_2_energy->Write();
  
        sc_ctof_energy->SetXTitle("sc_ctof_energy(GeV)");
        sc_ctof_energy->Write();
        _21_sc_ctof_energy->SetXTitle("_21_sc_ctof_energy(GeV)");
        _21_sc_ctof_energy->Write();
        _n21_sc_ctof_energy->SetXTitle("_n21_sc_ctof_energy(GeV)");
        _n21_sc_ctof_energy>Write();
        trigger_vs_sc_ctof_energy->SetXTitle("trigger bit");
        trigger_vs_sc_ctof_energy->SetYTitle("sc_ctof_energy(GeV)");
        trigger_vs_sc_ctof_energy->Write();
  
        sc_cnd_energy->SetXTitle("sc_cnd_energy(GeV)");
        sc_cnd_energy->Write();
        _21_sc_cnd_energy->SetXTitle("_21_sc_cnd_energy(GeV)");
        _21_sc_cnd_energy->Write();
        _n21_sc_cnd_energy->SetXTitle("_n21_sc_cnd_energy(GeV)");
        _n21_sc_cnd_energy->Write();
        trigger_vs_sc_cnd_energy->SetXTitle("trigger bit");
        trigger_vs_sc_cnd_energy->SetYTitle("sc_cnd_energy(GeV)");
        trigger_vs_sc_cnd_energy->Write();
  
        ft_cal_energy->SetXTitle("ft_cal_energy(GeV)");
        ft_cal_energy->Write();
        _21_ft_cal_energy->SetXTitle("_21_ft_cal_energy(GeV)");
        _21_ft_cal_energy->Write();
        _n21_ft_cal_energy->SetXTitle("_n21_ft_cal_energy(GeV)");
        _n21_ft_cal_energy->Write();
        trigger_vs_ft_cal_energy->SetXTitle("trigger bit");
        trigger_vs_ft_cal_energy->SetYTitle("ft_cal_energy(GeV)");
        trigger_vs_ft_cal_energy->Write();
  
        ft_hodo_energy->SetXTitle("ft_hodo_energy(GeV)");
        ft_hodo_energy->Write();
        _21_ft_hodo_energy->SetXTitle("_21_ft_hodo_energy(GeV)");
        _21_ft_hodo_energy->Write();
        _n21_ft_hodo_energy->SetXTitle("_n21_ft_hodo_energy(GeV)");
        _n21_ft_hodo_energy->Write();
        trigger_vs_ft_hodo_energy->SetXTitle("trigger bit");
        trigger_vs_ft_hodo_energy->SetYTitle("ft_hodo_energy(GeV)");
        trigger_vs_ft_hodo_energy->Write();

}
