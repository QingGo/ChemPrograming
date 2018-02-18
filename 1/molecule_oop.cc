#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "molecule.h"

//Out-of-Plane Angles
double Molecule::oop(int atom1, int atom2, int atom3, int atom4)
{
	double oop=0, sinoop=0;
	double vect1[3], vect2[3], vect3[3], vect4[3];

	for(int i=0; i<3; i++)
	{
		//vect3[i] = vect1[(i+1)%3]*vect2[(i+2)%3]-vect1[(i+2)%3]*vect2[(i+1)%3];
		vect3[i] = cross(i, atom3, atom2, atom3, atom4);
	}

	for(int i=0; i<3; i++)
	{
		vect4[i] = unit(i,atom3,atom1);
		sinoop += vect3[i]*vect4[i]/sin(angle(atom2, atom3, atom4));
	}

	//防止浮点数后面的位数超过函数定义域
	if(sinoop < -1.0) oop = asin(-1.0);
	else if(sinoop > 1.0) oop = asin(1.0);
	else oop = asin(sinoop);

	oop = asin(sinoop);
	return oop;
}
