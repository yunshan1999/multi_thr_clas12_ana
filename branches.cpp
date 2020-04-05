#include "branches.hpp"

Branches12::Branches12(const std::shared_ptr<TChain> &tree) {
  _tree = tree;
  Branches12::init();
}

void Branches12::init() {
_trigger = 0;
_liveTime = 0;
_ft_cal_energy = 0;
_ft_hodo_energy = 0;
_pid = 0;
_px = 0;
_py = 0;
_pz = 0;
  
_tree->SetBranchStatus("*",0);
_tree->SetBranchAddress("trigger", &_trigger);
_tree->SetBranchAddress("liveTime", &_liveTime);
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

float Branches12::angle(int i){
ppx = _px->at(i);
ppy = _py->at(i);
ppz = _pz->at(i);
return 90*acos(ppz/sqrt(ppx*ppx+ppy*ppy+ppz*ppz));
}

int Branches12::trigger() {
return _trigger;
}

double Branches12::liveTime(){
return _liveTime;
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



