#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include "molecule.h"

// translate molecule
void Molecule::translate(double x, double y, double z)
{
  for(int i=0; i < natom; i++) {
     geom[i][0] += x;
     geom[i][1] += y;
     geom[i][2] += z;
  }
}