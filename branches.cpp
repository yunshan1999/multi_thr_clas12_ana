#include "branches.hpp"


Branches12::Branches12(const std::shared_ptr<TChain> &tree) {
  _tree = tree;
  Branches12::init();
}

void Branches12::init() {
_trigger = 0;
_ft_cal_energy = 0;

_tree->SetBranchStatus("*",0);
_tree->SetBranchAddress("trigger", &_trigger);
_tree->SetBranchAddress("ft_cal_energy", &_ft_cal_energy);
}

int Branches12::trigger() {
return _trigger;
}

float Branches12::ft_cal_energy(int i) {
return _ft_cal_energy->at(i);
}