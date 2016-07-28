#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "molecule.h"
#include "masses.h"

/*double Molecule::ZvalToMass(int zvals)
{
	int Mass;
	switch(zvals)
	{
		case 1:
		Mass = 1;
		break;
		case 6:
		Mass = 12;
		break;
		case 8:
		Mass = 16;
		break;
	}
	return Mass;
}*/

double Molecule::CenterOfMass(int cart)
{
	double COM1 = 0, COM2 = 0, COM = 0;
	for(int i=0; i<natom; i++)
	{
		COM1 += masses[zvals[i]] * geom[i][cart];
		COM2 += masses[zvals[i]];
	}
	COM = COM1/COM2;
	return COM;
}