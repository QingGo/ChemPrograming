#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "molecule.h"

//得到atom1到atom2的单位向量的一个坐标
double Molecule::unit(int cart, int atom1, int atom2)
{
	return (geom[atom2][cart]-geom[atom1][cart])/bond(atom1,atom2);
}

// Calculate the angles
double Molecule::angle(int atom1, int atom2, int atom3)
{
	double angle = 0, cosangle = 0;
	double vect1[3], vect2[3];
	for (int i = 0; i < 3; i++)
	{
		vect1[i] = unit(i,atom2,atom1);
		vect2[i] = unit(i,atom2,atom3);
		cosangle += vect1[i] * vect2[i];
		//printf("%f, %f, %f\n", vect1[i], vect2[i], cosangle);
	}
	//防止浮点数后面的位数超过函数定义域
	if(cosangle < -1.0) angle = acos(-1.0);
	else if(cosangle > 1.0) angle = acos(1.0);
	else angle = acos(cosangle);
	//printf("The angle between atom %d, atom %d and atom %d is %8.5f\n", atom1, atom2, atom3, angle);
	return angle;
}
