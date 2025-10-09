#pragma once
// collider.h
#include <map>
#include <string>
#include <valarray>


class Collider {
  std::map<std::string, double> params; // parameters to compute the forces
  public:
    Collider(const std::map<std::string, double> &PARAMS) { params = PARAMS; }

    template<class particle_array_t>
    void computeForces(particle_array_t & parray) {
      // reset forces
      for (auto & p : parray) {
        p.F = {0,0,0};
      }
      // individual forces
      for (auto & p : parray) {
        // gravity force
        p.F[2] += p.mass*params["G"];

        //TODO: force with floor

      }

      // force with other particles
      for (int ip = 0; ip < parray.size(); ip++) {
        for (int jp = ip + 1; jp < parray.size(); jp++) {
          std::valarray<double> Rij{0.0, 0.0, 0.0};
          Rij = parray[jp].R - parray[ip].R; 
          double rij = std::sqrt((Rij*Rij).sum());
          double delta = parray[ip].rad + parray[jp].rad - rij;
          if (delta > 0) {
            parray[jp].F += params["K"]*delta*Rij/rij;
            parray[ip].F -= params["K"]*delta*Rij/rij;
          }
        }
      }

    }
};
