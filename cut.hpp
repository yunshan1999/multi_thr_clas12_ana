#ifndef CUTS_H_GUARD
#define CUTS_H_GUARD
#include "branches.hpp"
#include "constants.hpp"
#include "physics.hpp"

class Cuts {
 private:
  std::shared_ptr<Branches12> _data = nullptr;

 public:
  Cuts(const std::shared_ptr<Branches12>& data);
  ~Cuts();

  bool FT_Cut();

};

#endif
