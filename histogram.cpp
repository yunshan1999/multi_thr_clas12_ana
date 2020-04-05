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
  
  Pho_ft_cal_energy = std::make_shared<TH1D>("Pho_ft_cal_energy","Pho_ft_cal_energy", bins, zero, q2_max);
  Pho_21_ft_cal_energy = std::make_shared<TH1D>("Pho_21_ft_cal_energy","Pho_21_ft_cal_energy", bins, zero, q2_max);
  Pho_ft_cal_energy_cut = std::make_shared<TH1D>("Pho_ft_cal_energy_cut","Pho_ft_cal_energy_cut", bins, zero, q2_max);
  Pho_21_ft_cal_energy_cut = std::make_shared<TH1D>("Pho_21_ft_cal_energy_cut","Pho_21_ft_cal_energy_cut", bins, zero, q2_max);
  Pho_n21_ft_cal_energy = std::make_shared<TH1D>("Pho_n21_ft_cal_energy","Pho_n21_ft_cal_energy", bins, zero, q2_max);
  Pho_trigger_vs_ft_cal_energy = std::make_shared<TH2D>("Pho_trigger_vs_ft_cal_energy","Pho_trigger_vs_ft_cal_energy", 32, zero, 31, bins, zero, q2_max);
  
  Pho_ft_hodo_energy = std::make_shared<TH1D>("Pho_ft_hodo_energy","Pho_ft_hodo_energy", bins, zero, q2_max);
  Pho_21_ft_hodo_energy = std::make_shared<TH1D>("Pho_21_ft_hodo_energy","Pho_21_ft_hodo_energy", bins, zero, q2_max);
  Pho_ft_hodo_energy_cut = std::make_shared<TH1D>("Pho_ft_hodo_energy_cut","Pho_ft_hodo_energy_cut", bins, zero, q2_max);
  Pho_21_ft_hodo_energy_cut = std::make_shared<TH1D>("Pho_21_ft_hodo_energy_cut","Pho_21_ft_hodo_energy_cut", bins, zero, q2_max);
  Pho_n21_ft_hodo_energy = std::make_shared<TH1D>("Pho_n21_ft_hodo_energy","Pho_n21_ft_hodo_energy", bins, zero, q2_max);
  Pho_trigger_vs_ft_hodo_energy = std::make_shared<TH2D>("Pho_trigger_vs_ft_hodo_energy","Pho_trigger_vs_ft_hodo_energy", 32, zero, 31, bins, zero, q2_max);
  
  Elec_ft_cal_energy = std::make_shared<TH1D>("Elec_ft_cal_energy","Elec_ft_cal_energy", bins, zero, q2_max);
  Elec_21_ft_cal_energy = std::make_shared<TH1D>("Elec_21_ft_cal_energy","Elec_21_ft_cal_energy", bins, zero, q2_max);
  Elec_ft_cal_energy_cut = std::make_shared<TH1D>("Elec_ft_cal_energy_cut","Elec_ft_cal_energy_cut", bins, zero, q2_max);
  Elec_21_ft_cal_energy_cut = std::make_shared<TH1D>("Elec_21_ft_cal_energy_cut","Elec_21_ft_cal_energy_cut", bins, zero, q2_max);
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
  
  std::cerr << BOLDBLUE << "Write_photon()" << DEF << std::endl;
  TDirectory* photon_folder = RootOutputFile->mkdir("photon_folder");
  photon_folder->cd();
  Write_photon();
  
  std::cerr << BOLDBLUE << "Write_electron()" << DEF << std::endl;
  TDirectory* electron_folder = RootOutputFile->mkdir("elctron_folder");
  elctron_folder->cd();
  Write_electron();
  
  std::cerr << BOLDBLUE << "Done Writing!!!" << DEF << std::endl;
}

void Histogram::Fill(const std::shared_ptr<Branches12>& _d,int i,int pid) {
  if(pid==22){
  if(!std::isnan(_d->trigger())){ int T=int(_d->trigger());
                                  Pho_angle->Fill(_d->angle(i));
                                  if(T&(1<<21))Pho_21_angle->Fill(_d->angle(i));
                                  else Pho_n_21_angle->Fill(_d->angle(i));
                             
    if(!std::isnan(_d->ft_cal_energy(i))){
     float E=_d->ft_cal_energy(i);
  Pho_ft_cal_energy->Fill(E);
  if(E>1.0&&E<4.0)Pho_ft_cal_energy_cut->Fill(E);
  if (T & (1<<21)){Pho_21_ft_cal_energy->Fill(E);
                   if(E>1.0&&E<4.0)Pho_21_ft_cal_energy_cut->Fill(E);}
  else   Pho_n21_ft_cal_energy->Fill(E);
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Pho_trigger_vs_ft_cal_energy->Fill(flag ,E);
 }
  
    if(!std::isnan(_d->ft_hodo_energy(i))){
      float E=_d->ft_hodo_energy(i);
  Pho_ft_hodo_energy->Fill(E);
  if(E>0.0)Pho_ft_hodo_energy_cut->Fill(E);
  if (T & (1<<21)){Pho_21_ft_hodo_energy->Fill(E);
                   if(E>0.0)Pho_21_ft_hodo_energy_cut->Fill(E);}
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
    
    if(!std::isnan(_d->ft_cal_energy(i))){
  float E = _d->ft_cal_energy(i);
  Elec_ft_cal_energy->Fill(E);
      if(E>1.0&&E<4.0)Elec_ft_cal_energy_cut->Fill(E);
  if (T & (1<<21)){Elec_21_ft_cal_energy->Fill(E);
                   if(E>1.0&&E<4.0)Elec_21_ft_cal_energy_cut->Fill(E);}
  else   Elec_n21_ft_cal_energy->Fill(E);
  for (int flag=0;flag<32;flag++)
   if(T & (1<<flag)) Elec_trigger_vs_ft_cal_energy->Fill(flag ,E);
 }
  
    if(!std::isnan(_d->ft_hodo_energy(i))){
      float E = _d->ft_hodo_energy(i);
  Elec_ft_hodo_energy->Fill(E);
      if(E>0.0)Elec_ft_hodo_energy_cut->Fill(E);
  if (T & (1<<21)){Elec_21_ft_hodo_energy->Fill(_d->ft_hodo_energy(i));
                   if(E>0.0)Elec_21_ft_hodo_energy_cut->Fill(E);}
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
