#ifndef BRANCHES_H
#define BRANCHES_H
#include <iostream>
#include <vector>
#include <cmath>
#include "TChain.h"

using v_int = std::vector<int> *;
using v_float = std::vector<float> *;
//
class Branches12 {
 private:
  std::shared_ptr<TChain> _tree;
  
  Float_t _trigger;
  Double_t _liveTime;
  v_int _pid;
  v_float _px;
  v_float _py;
  v_float _pz;
  v_float _ft_cal_energy;
  v_float _ft_hodo_energy; 
  
 public:
  Branches12(){};
  Branches12(const std::shared_ptr<TChain> &tree);
  ~Branches12(){};
  void init();
  int pid(int i);
  int trigger();
  int gpart();
  float angle(int i);
  double liveTime();
  float ft_cal_energy(int i);
  float ft_hodo_energy(int i);
 
 };
#endif
