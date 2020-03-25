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
  v_float _ft_cal_energy;
  
 public:
  Branches12(){};
  Branches12(const std::shared_ptr<TChain> &tree);
  ~Branches12(){};
  void init();
  int trigger();
  float ft_cal_energy(int i);
 };
#endif
