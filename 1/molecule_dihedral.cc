#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>
#include "molecule.h"

//定义叉乘函数，不过返回值只是叉乘向量的一个坐标
double Molecule::cross(int cart, int atom1, int atom2, int atom3, int atom4)
{
	double vect1[3], vect2[3], vect3[3];
	for(int i=0; i<3; i++)
	{
		vect1[i] = unit(i,atom1,atom2);
		vect2[i] = unit(i,atom3,atom4);
	}
	vect3[cart] = vect1[(cart+1)%3]*vect2[(cart+2)%3]-vect1[(cart+2)%3]*vect2[(cart+1)%3];
	return vect3[cart];
}

double Molecule::dihedral(int atom1, int atom2, int atom3, int atom4)
{
	double dihedral = 0, cosDihedral = 0; //不变量初始化会出现莫名其妙的错误，算不出结果。
	//按二面角公式计算余弦值
	for(int i=0; i<3; i++)
	{
		cosDihedral += cross(i, atom1, atom2, atom2, atom3)*cross(i, atom2, atom3, atom3, atom4)/
		(sin(angle(atom1, atom2, atom3))*sin(angle(atom2, atom3, atom4)));
	}
	//防止浮点数后面的位数超过函数定义域
	if(cosDihedral <= -1.0)
		{dihedral = acos(-1.0);}
	else if(cosDihedral >=1.0)
		{dihedral = acos(1.0);}
	else
		{dihedral = acos(cosDihedral);}

	  // Compute the sign of the torsion
	  double vect1[3], vect2[3], vect3[3];
	  double dot, norm;
	  for(int i=0; i<3; i++)
	  {
	  	vect1[i] = cross(i, atom1, atom2, atom2, atom3);
	  	vect2[i] = cross(i, atom2, atom3, atom3, atom4);
	  }
	  for(int i=0; i<3; i++)
	  {
		vect3[i] = vect1[(i+1)%3]*vect2[(i+2)%3]-vect1[(i+2)%3]*vect2[(i+1)%3];
		norm += vect3[i]*vect3[i];
	  }
	  for(int i=0; i<3; i++)
	  {
		vect3[i] /= norm;
		dot += vect3[i]*unit(i,atom2,atom3);
	  }
	  double sign = 1.0;

	  if(dot < 0.0) sign = -1.0;


	return dihedral*sign;

}

