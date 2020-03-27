#include "branches.hpp"


Branches12::Branches12(const std::shared_ptr<TChain> &tree) {
  _tree = tree;
  Branches12::init();
}

void Branches12::init() {
_trigger = 0;
_ec_tot_energy = 0;
_ec_pcal_energy = 0;
_ec_ecin_energy = 0;
_ec_ecout_energy = 0;
_sc_ftof_1a_energy = 0;
_sc_ftof_1b_energy = 0;
_sc_ftof_2_energy = 0;
_sc_ctof_energy = 0;
_sc_cnd_energy = 0;
_ft_cal_energy = 0;
_ft_hodo_energy = 0;
_pid = 0;
_px = 0;
_py = 0;
_pz = 0;
  

_tree->SetBranchStatus("*",0);
_tree->SetBranchAddress("trigger", &_trigger);
_tree->SetBranchAddress("ec_tot_energy", &_ec_tot_energy);
_tree->SetBranchAddress("ec_pcal_energy", &_ec_pcal_energy);
_tree->SetBranchAddress("ec_ecin_energy", &_ec_ecin_energy);
_tree->SetBranchAddress("ec_ecout_energy", &_ec_ecout_energy);
_tree->SetBranchAddress("sc_ftof_1a_energy", &_sc_ftof_1a_energy);
_tree->SetBranchAddress("sc_ftof_1b_energy", &_sc_ftof_1b_energy);
_tree->SetBranchAddress("sc_ftof_2_energy", &_sc_ftof_2_energy);
_tree->SetBranchAddress("sc_ctof_energy", &_sc_ctof_energy);
_tree->SetBranchAddress("sc_cnd_energy", &_sc_cnd_energy);
_tree->SetBranchAddress("ft_cal_energy", &_ft_cal_energy);
_tree->SetBranchAddress("ft_hodo_energy", &_ft_hodo_energy);
_tree->SetBranchAddress("pid", &_pid);
_tree->SetBranchAddress("px", &_px);
_tree->SetBranchAddress("py", &_py);
_tree->SetBranchAddress("pz", &_pz);
}

int Branches12::gpart(){return _pid->size();}

int Branches12::pid(int i){
  if(i >= _pid->size())return -9999;
  else return _pid->at(i);
}

float Branches12::angle(){
ppx = _px;
ppy = _py;
ppz = _pz;
return 90*acos(ppz/sqrt(ppx*ppx+ppy*ppy+ppz*ppz));
}

int Branches12::trigger() {
return _trigger;
}

float Branches12::ec_tot_energy(int i) {
  if (i >= _ec_tot_energy->size())
    return NAN;
  else
    return _ec_tot_energy->at(i);
}

float Branches12::ec_pcal_energy(int i) {
  if (i >= _ec_pcal_energy->size())
    return NAN;
  else
    return _ec_pcal_energy->at(i);
}

float Branches12::ec_ecin_energy(int i) {
  if (i >= _ec_ecin_energy->size())
    return NAN;
  else
    return _ec_ecin_energy->at(i);
}

float Branches12::ec_ecout_energy(int i) {
  if (i >= _ec_ecout_energy->size())
    return NAN;
  else
    return _ec_ecout_energy->at(i);
}

float Branches12::sc_ftof_1a_energy(int i) {
  if (i >= _sc_ftof_1a_energy->size())
    return NAN;
  else
    return _sc_ftof_1a_energy->at(i);
}

float Branches12::sc_ftof_1b_energy(int i) {
  if (i >= _sc_ftof_1b_energy->size())
    return NAN;
  else
    return _sc_ftof_1b_energy->at(i);
}

float Branches12::sc_ftof_2_energy(int i) {
  if (i >= _sc_ftof_2_energy->size())
    return NAN;
  else
    return _sc_ftof_2_energy->at(i);
}

float Branches12::sc_ctof_energy(int i) {
  if (i >= _sc_ctof_energy->size())
    return NAN;
  else
    return _sc_ctof_energy->at(i);
}

float Branches12::sc_cnd_energy(int i) {
  if (i >= _sc_cnd_energy->size())
    return NAN;
  else
    return _sc_cnd_energy->at(i);
}

float Branches12::ft_cal_energy(int i) {
  if (i >= _ft_cal_energy->size())
    return NAN;
  else
    return _ft_cal_energy->at(i);
}

float Branches12::ft_hodo_energy(int i) {
  if (i >= _ft_hodo_energy->size())
    return NAN;
  else
    return _ft_hodo_energy->at(i);
}



