#ifndef BRANCHES_H
#define BRANCHES_H
#include <iostream>
#include <vector>
#include "TChain.h"

using v_int = std::vector<int> *;
using v_float = std::vector<float> *;
//
class Branches12 {
 private:
  std::shared_ptr<TChain> _tree;
  
  Float_t _trigger;
  v_float _ec_tot_energy;
  v_float _ec_pcal_energy;
  v_float _ec_ecin_energy;
  v_float _ec_ecout_energy;
  v_float _sc_ftof_1a_energy;
  v_float _sc_ftof_1b_energy;
  v_float _sc_ftof_2_energy;
  v_float _sc_ctof_energy;
  v_float _sc_cnd_energy;
  v_float _ft_cal_energy;
  v_float _ft_hodo_energy; 
  
 public:
  Branches12(){};
  Branches12(const std::shared_ptr<TChain> &tree);
  ~Branches12(){};
  void init();
  int trigger();
  float ec_tot_energy(int i);
  float ec_pcal_energy(int i);
  float ec_ecin_energy(int i);
  float ec_ecout_energy(int i);
  float sc_ftof_1a_energy(int i);
  float sc_ftof_1b_energy(int i);
  float sc_ftof_2_energy(int i);
  float sc_ctof_energy(int i);
  float sc_cnd_energy(int i);
  float ft_cal_energy(int i);
  float ft_hodo_energy(int i);
 
 };
#endif
