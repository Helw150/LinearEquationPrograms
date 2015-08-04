#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace 
{
struct Problem
{ friend Problem* read_problem (const std::string& filename);
  struct Data
  {
    std::vector<gts::Int> ir, jc;
    std::vector<gts::Real> d;
  };
  Data L, U;
  gts::CrsMatrix* Lm, * Um;
  std::vector<gts::Int> p, q;
  std::vector<gts::Real> r;
  std::vector<gts::Real> xt, b;
  gts::Int m, nrhs;
  gts::Int nnzL, nnzU;

  Problem () : Lm(0), Um(0) {}

  ~Problem ()
  {
    if (Lm) gts::delete_CrsMatrix(Lm);
    if (Um) gts::delete_CrsMatrix(Um);
  }

  bool set_nrhs (const int rnrhs)
  {
    if (rnrhs > nrhs) return false;
    if (rnrhs != nrhs)
    {
      const int n = xt.size() / nrhs;
      xt.resize(rnrhs*n);
      b.resize(rnrhs*n);
      nrhs = rnrhs;
    }
    return true;
  }
};

typedef gts::Int fint;

template<typename T> bool read_scalar (std::ifstream& is, T& s) {
  return ! is.read((char*) &s, sizeof(T)).bad();
}

#pragma omp parallel for
for (int i = 0; i < n; ++i) 
{
    y[i] = 
}
