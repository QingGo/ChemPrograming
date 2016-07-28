#include <iostream>
#include <fstream>
#include "molecule.h"
#include <cmath>


using namespace std;

int main()
{
  Molecule mol("geom.dat", 0);

 /* cout << "Number of atoms: " << mol.natom << endl;
  cout << "Input Cartesian coordinates:\n";
  for(int i=0; i < mol.natom; i++)
	printf("%d %20.12f %20.12f %20.12f\n", (int) mol.zvals[i], mol.geom[i][0], mol.geom[i][1], mol.geom[i][2]);
  return 0;*/
  cout << "Number of atoms: " << mol.natom << endl;
  cout << "Input Cartesian coordinates:\n";
  mol.print_geom();

  cout << "Interatomic distances (bohr):\n";
  for(int i=0; i < mol.natom; i++)
	for(int j=0; j < i; j++)
	  printf("%d %d %8.5f\n", i, j, mol.bond(i,j));

  cout <<"\nBond angles:\n";
  for(int i=0; i < mol.natom; i++)
  	for(int j=0; j < i; j++)
  		for (int k=0; k < j; k++)
  			if(mol.bond(i,j) < 4.0 && mol.bond(j,k) < 4.0)
  				printf("%d-%d-%d %10.6f\n", i, j, k, mol.angle(i,j,k)*180/acos(-1.0));

  cout << "\nOut-of-Plane angles:\n";
  for(int i=0; i < mol.natom; i++) {
	for(int k=0; k < mol.natom; k++) {
	  for(int j=0; j < mol.natom; j++) {
		for(int l=0; l < j; l++) {
		  if(i!=j && i!=k && i!=l && j!=k && k!=l && mol.bond(i,k) < 4.0 && mol.bond(k,j) < 4.0 && mol.bond(k,l) < 4.0)
			  printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.oop(i,j,k,l)*(180.0/acos(-1.0)));
		}
	  }
	}
  }

  cout << "\nTorsional angles:\n";
  for(int i=0; i < mol.natom; i++) {
    for(int j=0; j < i; j++) {
      for(int k=0; k < j; k++) {
        for(int l=0; l < k; l++) {
          if(mol.bond(i,j) < 4.0 && mol.bond(j,k) < 4.0 && mol.bond(k,l) < 4.0)
            printf("%2d-%2d-%2d-%2d %10.6f\n", i, j, k, l, mol.dihedral(i,j,k,l)*(180.0/acos(-1.0)));
        }
      }
    }
  }

  cout << "\nCenter-of-Mass Translation\n";
  for(int cart=0; cart < 3; cart++)
  {
    printf("%10.6f", mol.CenterOfMass(cart));
  }
  cout << endl;
  return 0;
}