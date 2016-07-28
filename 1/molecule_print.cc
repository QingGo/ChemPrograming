#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include "molecule.h"

//print molecule information
void Molecule::print_geom()
{
  for(int i=0; i < natom; i++)
    printf("%d %20.12f %20.12f %20.12f\n", zvals[i], geom[i][0], geom[i][1], geom[i][2]);
}