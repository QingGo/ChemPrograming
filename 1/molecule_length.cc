#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "molecule.h"

// Calculate the interatomic distances
double Molecule::bond(int atom1, int atom2)
{
	double length = 0, all = 0;
	for (int i = 0; i < 3; i++)
	{
		all = all + pow((geom[atom1][i] - geom[atom2][i]), 2);
	}
	length = sqrt(all);
	//printf("The length between atom %d and atom %d is %8.5f\n", atom1, atom2, length);
	return length;
}