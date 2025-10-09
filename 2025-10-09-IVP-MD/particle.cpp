// particle.cpp
#include "particle.h"
void Particle::print(void) {
  std::println("{:25.16e} {:25.16e} {:25.16e} {:25.16e} {:25.16e} "
	       "{:25.16e} {:25.16e} {:25.16e} {:25.16e} {:25.16e} {:25.16e}",
	       mass, rad, R[0], R[1], R[2],
	       V[0], V[1], V[2], F[0], F[1], F[2]);
}

// You can also overload the cout operator: friend declared to acces possible private data
// see: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
