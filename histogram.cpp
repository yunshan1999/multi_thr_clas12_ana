#include "histogram.hpp"

Histogram::Histogram(const std::string& output_file) {
  RootOutputFile = std::make_shared<TFile>(output_file.c_str(), "RECREATE");
  def = std::make_shared<TCanvas>("def");
  
  Pho_angle = std::make_shared<TH1D>("Pho_angle","Pho_angle",bins,zero,90);
  Elec_angle = std::make_shared<TH1D>("Elec_angle","Elec_angle",bins,zero,90);
  //Pho_angle_vs_ft_cal_energy = std::make_shared<TH2D>("Pho_angle_vs_ft_cal_energy","Pho_angle_vs_ft_cal_energy",bins,zero,90,bins,zero,q2_max);
  Pho_21_angle = std::make_shared<TH1D>("Pho_21_angle","Pho_21_angle",bins,zero,90);
  Pho_n_21_angle = std::make_shared<TH1D>("Pho_n_21_angle","Pho_21_angle",bins,zero,90);
  Elec_21_angle = std::make_shared<TH1D>("Elec_21_angle","Elec_21_anle",bins,zero,90);
  Elec_n_21_angle = std::make_shared<TH1D>("Elec_n_21_angle","Elec_n_21_anle",bins,zero,90);
  
  Pho_ec_tot_energy = std::make_shared<TH1D>("Pho_ec_tot_energy","Pho_ec_tot_energy", bins, zero, q2_max);
  Pho_21_ec_tot_energy = std::make_shared<TH1D>("Pho_21_ec_tot_energy","Pho_21_ec_tot_energy", bins, zero, q2_max);
  Pho_n21_ec_tot_energy = std::make_shared<TH1D>("Pho_n21_ec_tot_energy","Pho_n21_ec_tot_energy", bins, zero, q2_max);
  Pho_trigger_vs_ec_tot_energy = std::make_shared<TH2D>("Pho_trigger_vs_ec_tot_energy","Pho_trigger_vs_ec_tot_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ec_pcal_energy = std::make_shared<TH1D>("Pho_ec_pcal_energy","Pho_ec_pcal_energy", bins, zero, q2_max);
  Pho_21_ec_pcal_energy = std::make_shared<TH1D>("Pho_21_ec_pcal_energy","Pho_21_ec_pcal_energy", bins, zero, q2_max);
  Pho_n21_ec_pcal_energy = std::make_shared<TH1D>("Pho_n21_ec_pcal_energy","Pho_n21_ec_pcal_energy", bins, zero, q2_max);
  Pho_trigger_vs_ec_pcal_energy = std::make_shared<TH2D>("Pho_trigger_vs_ec_pcal_energy","Pho_trigger_vs_ec_pcal_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ec_ecin_energy = std::make_shared<TH1D>("Pho_ec_ecin_energy","Pho_ec_ecin_energy", bins, zero, q2_max);
  Pho_21_ec_ecin_energy = std::make_shared<TH1D>("Pho_21_ec_ecin_energy","Pho_21_ec_ecin_energy", bins, zero, q2_max);
  Pho_n21_ec_ecin_energy = std::make_shared<TH1D>("Pho_n21_ec_ecin_energy","Pho_n21_ec_ecin_energy", bins, zero, q2_max);
  Pho_trigger_vs_ec_ecin_energy = std::make_shared<TH2D>("Pho_trigger_vs_ec_ecin_energy","Pho_trigger_vs_ec_ecin_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ec_ecout_energy = std::make_shared<TH1D>("Pho_ec_ecout_energy","Pho_ec_ecout_energy", bins, zero, q2_max);
  Pho_21_ec_ecout_energy = std::make_shared<TH1D>("Pho_21_ec_ecout_energy","Pho_21_ec_ecout_energy", bins, zero, q2_max);
  Pho_n21_ec_ecout_energy = std::make_shared<TH1D>("Pho_n21_ec_ecout_energy","Pho_n21_ec_ecout_energy", bins, zero, q2_max);
  Pho_trigger_vs_ec_ecout_energy = std::make_shared<TH2D>("Pho_trigger_vs_ec_ecout_energy","Pho_trigger_vs_ec_ecout_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_sc_ftof_1a_energy = std::make_shared<TH1D>("Pho_sc_ftof_1a_energy","Pho_sc_ftof_1a_energy", bins, zero, q2_max);
  Pho_21_sc_ftof_1a_energy = std::make_shared<TH1D>("Pho_21_sc_ftof_1a_energy","Pho_21_sc_ftof_1a_energy", bins, zero, q2_max);
  Pho_n21_sc_ftof_1a_energy = std::make_shared<TH1D>("Pho_n21_sc_ftof_1a_energy","Pho_n21_sc_ftof_1a_energy", bins, zero, q2_max);
  Pho_trigger_vs_sc_ftof_1a_energy = std::make_shared<TH2D>("Pho_trigger_vs_sc_ftof_1a_energy","Pho_trigger_vs_sc_ftof_1a_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_sc_ftof_1b_energy = std::make_shared<TH1D>("Pho_sc_ftof_1b_energy","Pho_sc_ftof_1b_energy", bins, zero, q2_max);
  Pho_21_sc_ftof_1b_energy = std::make_shared<TH1D>("Pho_21_sc_ftof_1b_energy","Pho_21_sc_ftof_1b_energy", bins, zero, q2_max);
  Pho_n21_sc_ftof_1b_energy = std::make_shared<TH1D>("Pho_n21_sc_ftof_1b_energy","Pho_n21_sc_ftof_1b_energy", bins, zero, q2_max);
  Pho_trigger_vs_sc_ftof_1b_energy = std::make_shared<TH2D>("Pho_trigger_vs_sc_ftof_1b_energy","Pho_trigger_vs_sc_ftof_1b_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_sc_ftof_2_energy = std::make_shared<TH1D>("Pho_sc_ftof_2_energy","Pho_sc_ftof_2_energy", bins, zero, q2_max);
  Pho_21_sc_ftof_2_energy = std::make_shared<TH1D>("Pho_21_sc_ftof_2_energy","Pho_21_sc_ftof_2_energy", bins, zero, q2_max);
  Pho_n21_sc_ftof_2_energy = std::make_shared<TH1D>("Pho_n21_sc_ftof_2_energy","Pho_n21_sc_ftof_2_energy", bins, zero, q2_max);
  Pho_trigger_vs_sc_ftof_2_energy = std::make_shared<TH2D>("Pho_trigger_vs_sc_ftof_2_energy","Pho_trigger_vs_sc_ftof_2_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_sc_ctof_energy = std::make_shared<TH1D>("Pho_sc_ctof_energy","Pho_sc_ctof_energy", bins, zero, q2_max);
  Pho_21_sc_ctof_energy = std::make_shared<TH1D>("Pho_21_sc_ctof_energy","Pho_21_sc_ctof_energy", bins, zero, q2_max);
  Pho_n21_sc_ctof_energy = std::make_shared<TH1D>("Pho_n21_sc_ctof_energy","Pho_n21_sc_ctof_energy", bins, zero, q2_max);
  Pho_trigger_vs_sc_ctof_energy = std::make_shared<TH2D>("Pho_trigger_vs_sc_ctof_energy","Pho_trigger_vs_sc_ctof_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_sc_cnd_energy = std::make_shared<TH1D>("Pho_sc_cnd_energy","Pho_sc_cnd_energy", bins, zero, q2_max);
  Pho_21_sc_cnd_energy = std::make_shared<TH1D>("Pho_21_sc_cnd_energy","Pho_21_sc_cnd_energy", bins, zero, q2_max);
  Pho_n21_sc_cnd_energy = std::make_shared<TH1D>("Pho_n21_sc_cnd_energy","Pho_n21_sc_cnd_energy", bins, zero, q2_max);
  Pho_trigger_vs_sc_cnd_energy = std::make_shared<TH2D>("Pho_trigger_vs_sc_cnd_energy","Pho_trigger_vs_sc_cnd_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ft_cal_energy = std::make_shared<TH1D>("Pho_ft_cal_energy","Pho_ft_cal_energy", bins, zero, q2_max);
  Pho_21_ft_cal_energy = std::make_shared<TH1D>("Pho_21_ft_cal_energy","Pho_21_ft_cal_energy", bins, zero, q2_max);
  Pho_n21_ft_cal_energy = std::make_shared<TH1D>("Pho_n21_ft_cal_energy","Pho_n21_ft_cal_energy", bins, zero, q2_max);
  Pho_trigger_vs_ft_cal_energy = std::make_shared<TH2D>("Pho_trigger_vs_ft_cal_energy","Pho_trigger_vs_ft_cal_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ft_hodo_energy = std::make_shared<TH1D>("Pho_ft_hodo_energy","Pho_ft_hodo_energy", bins, zero, q2_max);
  Pho_21_ft_hodo_energy = std::make_shared<TH1D>("Pho_21_ft_hodo_energy","Pho_21_ft_hodo_energy", bins, zero, q2_max);
  Pho_n21_ft_hodo_energy = std::make_shared<TH1D>("Pho_n21_ft_hodo_energy","Pho_n21_ft_hodo_energy", bins, zero, q2_max);
  Pho_trigger_vs_ft_hodo_energy = std::make_shared<TH2D>("Pho_trigger_vs_ft_hodo_energy","Pho_trigger_vs_ft_hodo_energy", 32, zero, 31, bins, zero, q2_max);

  Elec_ec_tot_energy = std::make_shared<TH1D>("Elec_ec_tot_energy","Elec_ec_tot_energy", bins, zero, q2_max);
  Elec_21_ec_tot_energy = std::make_shared<TH1D>("Elec_21_ec_tot_energy","Elec_21_ec_tot_energy", bins, zero, q2_max);
  Elec_n21_ec_tot_energy = std::make_shared<TH1D>("Elec_n21_ec_tot_energy","ElecPho_n21_ec_tot_energy", bins, zero, q2_max);
  Elec_trigger_vs_ec_tot_energy = std::make_shared<TH2D>("Elec_trigger_vs_ec_tot_energy","Elec_trigger_vs_ec_tot_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ec_pcal_energy = std::make_shared<TH1D>("Elec_ec_pcal_energy","Elec_ec_pcal_energy", bins, zero, q2_max);
  Elec_21_ec_pcal_energy = std::make_shared<TH1D>("Elec_21_ec_pcal_energy","Elec_21_ec_pcal_energy", bins, zero, q2_max);
  Elec_n21_ec_pcal_energy = std::make_shared<TH1D>("Elec_n21_ec_pcal_energy","Elec_n21_ec_pcal_energy", bins, zero, q2_max);
  Elec_trigger_vs_ec_pcal_energy = std::make_shared<TH2D>("Elec_trigger_vs_ec_pcal_energy","Elec_trigger_vs_ec_pcal_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ec_ecin_energy = std::make_shared<TH1D>("Elec_ec_ecin_energy","Elec_ec_ecin_energy", bins, zero, q2_max);
  Elec_21_ec_ecin_energy = std::make_shared<TH1D>("Elec_21_ec_ecin_energy","Elec_21_ec_ecin_energy", bins, zero, q2_max);
  Elec_n21_ec_ecin_energy = std::make_shared<TH1D>("Elec_n21_ec_ecin_energy","Elec_n21_ec_ecin_energy", bins, zero, q2_max);
  Elec_trigger_vs_ec_ecin_energy = std::make_shared<TH2D>("Elec_trigger_vs_ec_ecin_energy","Elec_trigger_vs_ec_ecin_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ec_ecout_energy = std::make_shared<TH1D>("Elec_ec_ecout_energy","Elec_ec_ecout_energy", bins, zero, q2_max);
  Elec_21_ec_ecout_energy = std::make_shared<TH1D>("Elec_21_ec_ecout_energy","Elec_21_ec_ecout_energy", bins, zero, q2_max);
  Elec_n21_ec_ecout_energy = std::make_shared<TH1D>("Elec_n21_ec_ecout_energy","Elec_n21_ec_ecout_energy", bins, zero, q2_max);
  Elec_trigger_vs_ec_ecout_energy = std::make_shared<TH2D>("Elec_trigger_vs_ec_ecout_energy","Elec_trigger_vs_ec_ecout_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_sc_ftof_1a_energy = std::make_shared<TH1D>("Elec_sc_ftof_1a_energy","Elec_sc_ftof_1a_energy", bins, zero, q2_max);
  Elec_21_sc_ftof_1a_energy = std::make_shared<TH1D>("Elec_21_sc_ftof_1a_energy","Elec_21_sc_ftof_1a_energy", bins, zero, q2_max);
  Elec_n21_sc_ftof_1a_energy = std::make_shared<TH1D>("Elec_n21_sc_ftof_1a_energy","Elec_n21_sc_ftof_1a_energy", bins, zero, q2_max);
  Elec_trigger_vs_sc_ftof_1a_energy = std::make_shared<TH2D>("Elec_trigger_vs_sc_ftof_1a_energy","Elec_trigger_vs_sc_ftof_1a_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_sc_ftof_1b_energy = std::make_shared<TH1D>("Elec_sc_ftof_1b_energy","Elec_sc_ftof_1b_energy", bins, zero, q2_max);
  Elec_21_sc_ftof_1b_energy = std::make_shared<TH1D>("Elec_21_sc_ftof_1b_energy","Elec_21_sc_ftof_1b_energy", bins, zero, q2_max);
  Elec_n21_sc_ftof_1b_energy = std::make_shared<TH1D>("Elec_n21_sc_ftof_1b_energy","Elec_n21_sc_ftof_1b_energy", bins, zero, q2_max);
  Elec_trigger_vs_sc_ftof_1b_energy = std::make_shared<TH2D>("Elec_trigger_vs_sc_ftof_1b_energy","Elec_trigger_vs_sc_ftof_1b_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_sc_ftof_2_energy = std::make_shared<TH1D>("Elec_sc_ftof_2_energy","Elec_sc_ftof_2_energy", bins, zero, q2_max);
  Elec_21_sc_ftof_2_energy = std::make_shared<TH1D>("Elec_21_sc_ftof_2_energy","Elec_21_sc_ftof_2_energy", bins, zero, q2_max);
  Elec_n21_sc_ftof_2_energy = std::make_shared<TH1D>("Elec_n21_sc_ftof_2_energy","Elec_n21_sc_ftof_2_energy", bins, zero, q2_max);
  Elec_trigger_vs_sc_ftof_2_energy = std::make_shared<TH2D>("Elec_trigger_vs_sc_ftof_2_energy","Elec_trigger_vs_sc_ftof_2_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_sc_ctof_energy = std::make_shared<TH1D>("Elec_sc_ctof_energy","Elec_sc_ctof_energy", bins, zero, q2_max);
  Elec_21_sc_ctof_energy = std::make_shared<TH1D>("Elec_21_sc_ctof_energy","Elec_21_sc_ctof_energy", bins, zero, q2_max);
  Elec_n21_sc_ctof_energy = std::make_shared<TH1D>("Elec_n21_sc_ctof_energy","Elec_n21_sc_ctof_energy", bins, zero, q2_max);
  Elec_trigger_vs_sc_ctof_energy = std::make_shared<TH2D>("Elec_trigger_vs_sc_ctof_energy","Elec_trigger_vs_sc_ctof_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_sc_cnd_energy = std::make_shared<TH1D>("Elec_sc_cnd_energy","Elec_sc_cnd_energy", bins, zero, q2_max);
  Elec_21_sc_cnd_energy = std::make_shared<TH1D>("Elec_21_sc_cnd_energy","Elec_21_sc_cnd_energy", bins, zero, q2_max);
  Elec_n21_sc_cnd_energy = std::make_shared<TH1D>("Elec_n21_sc_cnd_energy","Elec_n21_sc_cnd_energy", bins, zero, q2_max);
  Elec_trigger_vs_sc_cnd_energy = std::make_shared<TH2D>("Elec_trigger_vs_sc_cnd_energy","Elec_trigger_vs_sc_cnd_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ft_cal_energy = std::make_shared<TH1D>("Elec_ft_cal_energy","Elec_ft_cal_energy", bins, zero, q2_max);
  Elec_21_ft_cal_energy = std::make_shared<TH1D>("Elec_21_ft_cal_energy","Elec_21_ft_cal_energy", bins, zero, q2_max);
  Elec_n21_ft_cal_energy = std::make_shared<TH1D>("Elec_n21_ft_cal_energy","Elec_n21_ft_cal_energy", bins, zero, q2_max);
  Elec_trigger_vs_ft_cal_energy = std::make_shared<TH2D>("Elec_trigger_vs_ft_cal_energy","Elec_trigger_vs_ft_cal_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ft_hodo_energy = std::make_shared<TH1D>("Elec_ft_hodo_energy","Elec_ft_hodo_energy", bins, zero, q2_max);
  Elec_21_ft_hodo_energy = std::make_shared<TH1D>("Elec_21_ft_hodo_energy","Elec_21_ft_hodo_energy", bins, zero, q2_max);
  Elec_n21_ft_hodo_energy = std::make_shared<TH1D>("Elec_n21_ft_hodo_energy","Elec_n21_ft_hodo_energy", bins, zero, q2_max);
  Elec_trigger_vs_ft_hodo_energy = std::make_shared<TH2D>("Elec_trigger_vs_ft_hodo_energy","Elec_trigger_vs_ft_hodo_energy", 32, zero, 31, bins, zero, q2_max);
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

void Histogram::Fill_trigger(const std::shared_ptr<Branches12>& _d,int i,int pid) {
  if(pid==22){
  if(!std::isnan(_d->trigger())){ int T=int(_d->trigger());
                                  Pho_angle->Fill(_d->angle(i));
                                  if(T&(1<<21))Pho_21_angle->Fill(_d->angle(i));
                                  else Pho_n_21_angle->Fill(_d->angle(i));
                             
  if(!std::isnan(_d->ec_tot_energy(i))){
  Pho_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  if (T & (1<<21))Pho_21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  else   Pho_n21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ec_tot_energy->Fill(flag ,_d->ec_tot_energy(i));
 }
  
    if(!std::isnan(_d->ec_pcal_energy(i))){
  Pho_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  if (T & (1<<21))Pho_21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  else   Pho_n21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ec_pcal_energy->Fill(flag ,_d->ec_pcal_energy(i));
 }
  
    if(!std::isnan(_d->ec_ecin_energy(i))){
  Pho_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  if (T & (1<<21))Pho_21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  else   Pho_n21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ec_ecin_energy->Fill(flag ,_d->ec_ecin_energy(i));
 }
  
    if(!std::isnan(_d->ec_ecout_energy(i))){
  Pho_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  if (T & (1<<21))Pho_21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  else   Pho_n21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ec_ecout_energy->Fill(flag ,_d->ec_ecout_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_1a_energy(i))){
  Pho_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  if (T & (1<<21))Pho_21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  else   Pho_n21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_sc_ftof_1a_energy->Fill(flag ,_d->sc_ftof_1a_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_1b_energy(i))){
  Pho_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  if (T & (1<<21))Pho_21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  else   Pho_n21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_sc_ftof_1b_energy->Fill(flag ,_d->sc_ftof_1b_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_2_energy(i))){
  Pho_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  if (T & (1<<21))Pho_21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  else   Pho_n21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_sc_ftof_2_energy->Fill(flag ,_d->sc_ftof_2_energy(i));
 }
  
    if(!std::isnan(_d->sc_ctof_energy(i))){
  Pho_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  if (T & (1<<21))Pho_21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  else   Pho_n21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_sc_ctof_energy->Fill(flag ,_d->sc_ctof_energy(i));
 }
  
    if(!std::isnan(_d->sc_cnd_energy(i))){
  int T=int(_d->trigger());
  Pho_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  if (T & (1<<21))Pho_21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  else   Pho_n21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_sc_cnd_energy->Fill(flag ,_d->sc_cnd_energy(i));
 }
  
    if(!std::isnan(_d->ft_cal_energy(i))){
  Pho_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  if (T & (1<<21))Pho_21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  else   Pho_n21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ft_cal_energy->Fill(flag ,_d->ft_cal_energy(i));
 }
  
    if(!std::isnan(_d->ft_hodo_energy(i))){
  Pho_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  if (T & (1<<21))Pho_21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  else   Pho_n21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ft_hodo_energy->Fill(flag ,_d->ft_hodo_energy(i));
 }
}}
  else if(pid==11){  if(!std::isnan(_d->trigger())){ 
    int T=int(_d->trigger());
    Elec_angle->Fill(_d->angle(i));
    if(T&(1<<21))Elec_21_angle->Fill(_d->angle(i));
    else Elec_n_21_angle->Fill(_d->angle(i));
    
  if(!std::isnan(_d->ec_tot_energy(i))){
  Elec_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  if (T & (1<<21))Elec_21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  else   Elec_n21_ec_tot_energy->Fill(_d->ec_tot_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ec_tot_energy->Fill(flag ,_d->ec_tot_energy(i));
 }
  
    if(!std::isnan(_d->ec_pcal_energy(i))){
  Elec_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  if (T & (1<<21))Elec_21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  else   Elec_n21_ec_pcal_energy->Fill(_d->ec_pcal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ec_pcal_energy->Fill(flag ,_d->ec_pcal_energy(i));
 }
  
    if(!std::isnan(_d->ec_ecin_energy(i))){
  Elec_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  if (T & (1<<21))Elec_21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  else   Elec_n21_ec_ecin_energy->Fill(_d->ec_ecin_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ec_ecin_energy->Fill(flag ,_d->ec_ecin_energy(i));
 }
  
    if(!std::isnan(_d->ec_ecout_energy(i))){
  Elec_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  if (T & (1<<21))Elec_21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  else   Elec_n21_ec_ecout_energy->Fill(_d->ec_ecout_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ec_ecout_energy->Fill(flag ,_d->ec_ecout_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_1a_energy(i))){
  Elec_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  if (T & (1<<21))Elec_21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  else   Elec_n21_sc_ftof_1a_energy->Fill(_d->sc_ftof_1a_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_sc_ftof_1a_energy->Fill(flag ,_d->sc_ftof_1a_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_1b_energy(i))){
  Elec_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  if (T & (1<<21))Elec_21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  else   Elec_n21_sc_ftof_1b_energy->Fill(_d->sc_ftof_1b_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_sc_ftof_1b_energy->Fill(flag ,_d->sc_ftof_1b_energy(i));
 }
  
    if(!std::isnan(_d->sc_ftof_2_energy(i))){
  Elec_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  if (T & (1<<21))Elec_21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  else   Elec_n21_sc_ftof_2_energy->Fill(_d->sc_ftof_2_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_sc_ftof_2_energy->Fill(flag ,_d->sc_ftof_2_energy(i));
 }
  
    if(!std::isnan(_d->sc_ctof_energy(i))){
  Elec_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  if (T & (1<<21))Elec_21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  else   Elec_n21_sc_ctof_energy->Fill(_d->sc_ctof_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_sc_ctof_energy->Fill(flag ,_d->sc_ctof_energy(i));
 }
  
    if(!std::isnan(_d->sc_cnd_energy(i))){
  Elec_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  if (T & (1<<21))Elec_21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  else   Elec_n21_sc_cnd_energy->Fill(_d->sc_cnd_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_sc_cnd_energy->Fill(flag ,_d->sc_cnd_energy(i));
 }
  
    if(!std::isnan(_d->ft_cal_energy(i))){
  Elec_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  if (T & (1<<21))Elec_21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  else   Elec_n21_ft_cal_energy->Fill(_d->ft_cal_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ft_cal_energy->Fill(flag ,_d->ft_cal_energy(i));
 }
  
    if(!std::isnan(_d->ft_hodo_energy(i))){
  Elec_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  if (T & (1<<21))Elec_21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  else   Elec_n21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ft_hodo_energy->Fill(flag ,_d->ft_hodo_energy(i));
 }
}}
}

void Histogram::Write_trigger(){
        Pho_angle->SetXTitle("Pho_angle");
        Pho_angle->Write();
        Elec_angle->SetXTitle("Elec_angle");
        Elec_angle->Write();
        Pho_21_angle->Write();
        Pho_n_21_angle->Write();
        Elec_21_angle->Write();
        Elec_n_21_angle->Write();

  
        Pho_ec_tot_energy->SetXTitle("Pho_ec_tot_energy(GeV)");
        Pho_ec_tot_energy->Write();
        Pho_21_ec_tot_energy->SetXTitle("Pho_21_ec_tot_energy(GeV)");
        Pho_21_ec_tot_energy->Write();
        Pho_n21_ec_tot_energy->SetXTitle("Pho_n21_ec_tot_energy(GeV)");
        Pho_n21_ec_tot_energy->Write();
        Pho_trigger_vs_ec_tot_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ec_tot_energy->SetYTitle("Pho_ec_tot_energy(GeV)");
        Pho_trigger_vs_ec_tot_energy->Write();
  
        Pho_ec_pcal_energy->SetXTitle("Pho_ec_pcal_energy(GeV)");
        Pho_ec_pcal_energy->Write();
        Pho_21_ec_pcal_energy->SetXTitle("Pho_21_ec_pcal_energy(GeV)");
        Pho_21_ec_pcal_energy->Write();
        Pho_n21_ec_pcal_energy->SetXTitle("Pho_n21_ec_pcal_energy(GeV)");
        Pho_n21_ec_pcal_energy->Write();
        Pho_trigger_vs_ec_pcal_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ec_pcal_energy->SetYTitle("Pho_ec_pcal_energy(GeV)");
        Pho_trigger_vs_ec_pcal_energy->Write();
  
        Pho_ec_ecin_energy->SetXTitle("Pho_ec_ecin_energy(GeV)");
        Pho_ec_ecin_energy->Write();
        Pho_21_ec_ecin_energy->SetXTitle("Pho_21_ec_ecin_energy(GeV)");
        Pho_21_ec_ecin_energy->Write();
        Pho_n21_ec_ecin_energy->SetXTitle("Pho_n21_ec_ecin_energy(GeV)");
        Pho_n21_ec_ecin_energy->Write();
        Pho_trigger_vs_ec_ecin_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ec_ecin_energy->SetYTitle("Pho_ec_ecin_energy(GeV)");
        Pho_trigger_vs_ec_ecin_energy->Write();
  
        Pho_ec_ecout_energy->SetXTitle("Pho_ec_ecout_energy(GeV)");
        Pho_ec_ecout_energy->Write();
        Pho_21_ec_ecout_energy->SetXTitle("Pho_21_ec_ecout_energy(GeV)");
        Pho_21_ec_ecout_energy->Write();
        Pho_n21_ec_ecout_energy->SetXTitle("Pho_n21_ec_ecout_energy(GeV)");
        Pho_n21_ec_ecout_energy->Write();
        Pho_trigger_vs_ec_ecout_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ec_ecout_energy->SetYTitle("Pho_ec_ecout_energy(GeV)");
        Pho_trigger_vs_ec_ecout_energy->Write();
  
        Pho_sc_ftof_1a_energy->SetXTitle("Pho_sc_ftof_1a_energy(GeV)");
        Pho_sc_ftof_1a_energy->Write();
        Pho_21_sc_ftof_1a_energy->SetXTitle("Pho_21_sc_ftof_1a_energy(GeV)");
        Pho_21_sc_ftof_1a_energy->Write();
        Pho_n21_sc_ftof_1a_energy->SetXTitle("Pho_n21_sc_ftof_1a_energy(GeV)");
        Pho_n21_sc_ftof_1a_energy->Write();
        Pho_trigger_vs_sc_ftof_1a_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_sc_ftof_1a_energy->SetYTitle("Pho_sc_ftof_1a_energy(GeV)");
        Pho_trigger_vs_sc_ftof_1a_energy->Write();
  
        Pho_sc_ftof_1b_energy->SetXTitle("Pho_sc_ftof_1b_energy(GeV)");
        Pho_sc_ftof_1b_energy->Write();
        Pho_21_sc_ftof_1b_energy->SetXTitle("Pho_21_sc_ftof_1b_energy(GeV)");
        Pho_21_sc_ftof_1b_energy->Write();
        Pho_n21_sc_ftof_1b_energy->SetXTitle("Pho_n21_sc_ftof_1b_energy(GeV)");
        Pho_n21_sc_ftof_1b_energy->Write();
        Pho_trigger_vs_sc_ftof_1b_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_sc_ftof_1b_energy->SetYTitle("Pho_sc_ftof_1b_energy(GeV)");
        Pho_trigger_vs_sc_ftof_1b_energy->Write();
  
        Pho_sc_ftof_2_energy->SetXTitle("Pho_sc_ftof_2_energy(GeV)");
        Pho_sc_ftof_2_energy->Write();
        Pho_21_sc_ftof_2_energy->SetXTitle("Pho_21_sc_ftof_2_energy(GeV)");
        Pho_21_sc_ftof_2_energy->Write();
        Pho_n21_sc_ftof_2_energy->SetXTitle("Pho_n21_sc_ftof_2_energy(GeV)");
        Pho_n21_sc_ftof_2_energy->Write();
        Pho_trigger_vs_sc_ftof_2_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_sc_ftof_2_energy->SetYTitle("Pho_sc_ftof_2_energy(GeV)");
        Pho_trigger_vs_sc_ftof_2_energy->Write();
  
        Pho_sc_ctof_energy->SetXTitle("Pho_sc_ctof_energy(GeV)");
        Pho_sc_ctof_energy->Write();
        Pho_21_sc_ctof_energy->SetXTitle("Pho_21_sc_ctof_energy(GeV)");
        Pho_21_sc_ctof_energy->Write();
        Pho_n21_sc_ctof_energy->SetXTitle("Pho_n21_sc_ctof_energy(GeV)");
        Pho_n21_sc_ctof_energy->Write();
        Pho_trigger_vs_sc_ctof_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_sc_ctof_energy->SetYTitle("Pho_sc_ctof_energy(GeV)");
        Pho_trigger_vs_sc_ctof_energy->Write();
  
        Pho_sc_cnd_energy->SetXTitle("Pho_sc_cnd_energy(GeV)");
        Pho_sc_cnd_energy->Write();
        Pho_21_sc_cnd_energy->SetXTitle("Pho_21_sc_cnd_energy(GeV)");
        Pho_21_sc_cnd_energy->Write();
        Pho_n21_sc_cnd_energy->SetXTitle("Pho_n21_sc_cnd_energy(GeV)");
        Pho_n21_sc_cnd_energy->Write();
        Pho_trigger_vs_sc_cnd_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_sc_cnd_energy->SetYTitle("Pho_sc_cnd_energy(GeV)");
        Pho_trigger_vs_sc_cnd_energy->Write();
  
        Pho_ft_cal_energy->SetXTitle("Pho_ft_cal_energy(GeV)");
        Pho_ft_cal_energy->Write();
        Pho_21_ft_cal_energy->SetXTitle("Pho_21_ft_cal_energy(GeV)");
        Pho_21_ft_cal_energy->Write();
        Pho_n21_ft_cal_energy->SetXTitle("Pho_n21_ft_cal_energy(GeV)");
        Pho_n21_ft_cal_energy->Write();
        Pho_trigger_vs_ft_cal_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ft_cal_energy->SetYTitle("Pho_ft_cal_energy(GeV)");
        Pho_trigger_vs_ft_cal_energy->Write();
  
        Pho_ft_hodo_energy->SetXTitle("Pho_ft_hodo_energy(GeV)");
        Pho_ft_hodo_energy->Write();
        Pho_21_ft_hodo_energy->SetXTitle("Pho_21_ft_hodo_energy(GeV)");
        Pho_21_ft_hodo_energy->Write();
        Pho_n21_ft_hodo_energy->SetXTitle("Pho_n21_ft_hodo_energy(GeV)");
        Pho_n21_ft_hodo_energy->Write();
        Pho_trigger_vs_ft_hodo_energy->SetXTitle("trigger bit");
        Pho_trigger_vs_ft_hodo_energy->SetYTitle("Pho_ft_hodo_energy(GeV)");
        Pho_trigger_vs_ft_hodo_energy->Write();

        Elec_ec_tot_energy->SetXTitle("Elec_ec_tot_energy(GeV)");
        Elec_ec_tot_energy->Write();
        Elec_21_ec_tot_energy->SetXTitle("Elec_21_ec_tot_energy(GeV)");
        Elec_21_ec_tot_energy->Write();
        Elec_n21_ec_tot_energy->SetXTitle("Elec_n21_ec_tot_energy(GeV)");
        Elec_n21_ec_tot_energy->Write();
        Elec_trigger_vs_ec_tot_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ec_tot_energy->SetYTitle("Elec_ec_tot_energy(GeV)");
        Elec_trigger_vs_ec_tot_energy->Write();
  
        Elec_ec_pcal_energy->SetXTitle("Elec_ec_pcal_energy(GeV)");
        Elec_ec_pcal_energy->Write();
        Elec_21_ec_pcal_energy->SetXTitle("Elec_21_ec_pcal_energy(GeV)");
        Elec_21_ec_pcal_energy->Write();
        Elec_n21_ec_pcal_energy->SetXTitle("Elec_n21_ec_pcal_energy(GeV)");
        Elec_n21_ec_pcal_energy->Write();
        Elec_trigger_vs_ec_pcal_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ec_pcal_energy->SetYTitle("Elec_ec_pcal_energy(GeV)");
        Elec_trigger_vs_ec_pcal_energy->Write();
  
        Elec_ec_ecin_energy->SetXTitle("Elec_ec_ecin_energy(GeV)");
        Elec_ec_ecin_energy->Write();
        Elec_21_ec_ecin_energy->SetXTitle("Elec_21_ec_ecin_energy(GeV)");
        Elec_21_ec_ecin_energy->Write();
        Elec_n21_ec_ecin_energy->SetXTitle("Elec_n21_ec_ecin_energy(GeV)");
        Elec_n21_ec_ecin_energy->Write();
        Elec_trigger_vs_ec_ecin_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ec_ecin_energy->SetYTitle("Elec_ec_ecin_energy(GeV)");
        Elec_trigger_vs_ec_ecin_energy->Write();
  
        Elec_ec_ecout_energy->SetXTitle("Elec_ec_ecout_energy(GeV)");
        Elec_ec_ecout_energy->Write();
        Elec_21_ec_ecout_energy->SetXTitle("Elec_21_ec_ecout_energy(GeV)");
        Elec_21_ec_ecout_energy->Write();
        Elec_n21_ec_ecout_energy->SetXTitle("Elec_n21_ec_ecout_energy(GeV)");
        Elec_n21_ec_ecout_energy->Write();
        Elec_trigger_vs_ec_ecout_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ec_ecout_energy->SetYTitle("Elec_ec_ecout_energy(GeV)");
        Elec_trigger_vs_ec_ecout_energy->Write();
  
        Elec_sc_ftof_1a_energy->SetXTitle("Elec_sc_ftof_1a_energy(GeV)");
        Elec_sc_ftof_1a_energy->Write();
        Elec_21_sc_ftof_1a_energy->SetXTitle("Elec_21_sc_ftof_1a_energy(GeV)");
        Elec_21_sc_ftof_1a_energy->Write();
        Elec_n21_sc_ftof_1a_energy->SetXTitle("Elec_n21_sc_ftof_1a_energy(GeV)");
        Elec_n21_sc_ftof_1a_energy->Write();
        Elec_trigger_vs_sc_ftof_1a_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_sc_ftof_1a_energy->SetYTitle("Elec_sc_ftof_1a_energy(GeV)");
        Elec_trigger_vs_sc_ftof_1a_energy->Write();
  
        Elec_sc_ftof_1b_energy->SetXTitle("Elec_sc_ftof_1b_energy(GeV)");
        Elec_sc_ftof_1b_energy->Write();
        Elec_21_sc_ftof_1b_energy->SetXTitle("Elec_21_sc_ftof_1b_energy(GeV)");
        Elec_21_sc_ftof_1b_energy->Write();
        Elec_n21_sc_ftof_1b_energy->SetXTitle("Elec_n21_sc_ftof_1b_energy(GeV)");
        Elec_n21_sc_ftof_1b_energy->Write();
        Elec_trigger_vs_sc_ftof_1b_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_sc_ftof_1b_energy->SetYTitle("Elec_sc_ftof_1b_energy(GeV)");
        Elec_trigger_vs_sc_ftof_1b_energy->Write();
  
        Elec_sc_ftof_2_energy->SetXTitle("Elec_sc_ftof_2_energy(GeV)");
        Elec_sc_ftof_2_energy->Write();
        Elec_21_sc_ftof_2_energy->SetXTitle("Elec_21_sc_ftof_2_energy(GeV)");
        Elec_21_sc_ftof_2_energy->Write();
        Elec_n21_sc_ftof_2_energy->SetXTitle("Elec_n21_sc_ftof_2_energy(GeV)");
        Elec_n21_sc_ftof_2_energy->Write();
        Elec_trigger_vs_sc_ftof_2_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_sc_ftof_2_energy->SetYTitle("Elec_sc_ftof_2_energy(GeV)");
        Elec_trigger_vs_sc_ftof_2_energy->Write();
  
        Elec_sc_ctof_energy->SetXTitle("Elec_sc_ctof_energy(GeV)");
        Elec_sc_ctof_energy->Write();
        Elec_21_sc_ctof_energy->SetXTitle("Elec_21_sc_ctof_energy(GeV)");
        Elec_21_sc_ctof_energy->Write();
        Elec_n21_sc_ctof_energy->SetXTitle("Elec_n21_sc_ctof_energy(GeV)");
        Elec_n21_sc_ctof_energy->Write();
        Elec_trigger_vs_sc_ctof_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_sc_ctof_energy->SetYTitle("Elec_sc_ctof_energy(GeV)");
        Elec_trigger_vs_sc_ctof_energy->Write();
  
        Elec_sc_cnd_energy->SetXTitle("Elec_sc_cnd_energy(GeV)");
        Elec_sc_cnd_energy->Write();
        Elec_21_sc_cnd_energy->SetXTitle("Elec_21_sc_cnd_energy(GeV)");
        Elec_21_sc_cnd_energy->Write();
        Elec_n21_sc_cnd_energy->SetXTitle("Elec_n21_sc_cnd_energy(GeV)");
        Elec_n21_sc_cnd_energy->Write();
        Elec_trigger_vs_sc_cnd_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_sc_cnd_energy->SetYTitle("Elec_sc_cnd_energy(GeV)");
        Elec_trigger_vs_sc_cnd_energy->Write();
  
        Elec_ft_cal_energy->SetXTitle("Elec_ft_cal_energy(GeV)");
        Elec_ft_cal_energy->Write();
        Elec_21_ft_cal_energy->SetXTitle("Elec_21_ft_cal_energy(GeV)");
        Elec_21_ft_cal_energy->Write();
        Elec_n21_ft_cal_energy->SetXTitle("Elec_n21_ft_cal_energy(GeV)");
        Elec_n21_ft_cal_energy->Write();
        Elec_trigger_vs_ft_cal_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ft_cal_energy->SetYTitle("Elec_ft_cal_energy(GeV)");
        Elec_trigger_vs_ft_cal_energy->Write();
  
        Elec_ft_hodo_energy->SetXTitle("Elec_ft_hodo_energy(GeV)");
        Elec_ft_hodo_energy->Write();
        Elec_21_ft_hodo_energy->SetXTitle("Elec_21_ft_hodo_energy(GeV)");
        Elec_21_ft_hodo_energy->Write();
        Elec_n21_ft_hodo_energy->SetXTitle("Elec_n21_ft_hodo_energy(GeV)");
        Elec_n21_ft_hodo_energy->Write();
        Elec_trigger_vs_ft_hodo_energy->SetXTitle("trigger bit");
        Elec_trigger_vs_ft_hodo_energy->SetYTitle("Elec_ft_hodo_energy(GeV)");
        Elec_trigger_vs_ft_hodo_energy->Write();
}
