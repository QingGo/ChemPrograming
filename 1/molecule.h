#include <string>

using namespace std;

class Molecule
{
	public:
	int natom;
	int charge;
	int *zvals;
	double **geom;
	string point_group;

	//molecule_print.cc
	void print_geom();

	void rotate(double phi);

	//molecule_tran
	void translate(double x, double y, double z);

	//molecule_length.cc
	double bond(int atom1, int atom2);

	//molecule_angle.cc
	double unit(int cart, int atom1, int atom2); //得到atom1到atom2的单位向量的一个坐标
	double angle(int atom1, int atom2, int atom3);

	//molecule_oop.cc
	double oop(int atom1, int atom2, int atom3, int atom4); //Out-of-Plane Angles

  //molecule_dihedral.cc
	double cross(int cart, int atom1, int atom2, int atom3, int atom4); //返回1-2与3-4叉乘函数的一个坐标
	double dihedral(int atom1, int atom2, int atom3, int atom4); //1 - 2,3 - 4二面角
	//double torsion(int atom1, int atom2, int atom3, int atom4);

	//molecule_CenterofMass.cc
	double CenterOfMass(int cart);
  double ZvalToMass(int zvals);  //use masses.h instead


	//molecule.cc
	Molecule(const char *filename, int q);
	~Molecule();
};
