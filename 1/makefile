PROGRAM = mol
PROGSRC = molecule.cc mol.cc molecule_print.cc molecule_tran.cc \
molecule_length.cc molecule_angle.cc molecule_oop.cc molecule_dihedral.cc \
molecule_CenterofMass.cc
OBJECTS = $(PROGSRC:%.cc=%.o)
CXXFLAGS += -std=gnu++11
#CFLAGS = -g
#CLIBS = -lm

$(PROGRAM): $(OBJECTS)
	g++ $^ -o $@

.PHONY : clean
clean:
	/bin/rm -f mol *.o
