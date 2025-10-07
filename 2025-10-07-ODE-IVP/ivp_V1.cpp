// euler algorithm
#include <print>
#include <valarray>
#include <string>
#include <map> // for the parameters

typedef std::valarray<double> state_t; // create a short name to represent the system state type
typedef std::map<std::string, double> params_t;

void initial_conditions(state_t & s, double t0);
void print(const state_t & s, double t);
void fderiv(const state_t & s, state_t & dsdt, double t, params_t & p);
template <class deriv_t, class s_t, class print_t>
void integrate_euler(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer);

int main(void)
{
  int N = 2; // two dimensinal system
  state_t S(N);
  params_t params;
  params["K"] = 0.98765443;
  params["M"] = 1.142187386;
  initial_conditions(S, 0);

  integrate_euler(fderiv, S, 0.0, 10.0, 0.1, params, print);
  
  return 0;
}


void fderiv(const state_t & s, state_t & dsdt, double t, params_t & params)
{
  dsdt[0] = s[1];
  dsdt[1] = -params["K"]*s[0]*s[0]*s[0]/params["M"];
}

void initial_conditions(state_t & s, double t0)
{
  s[0] = 1.9876;
  s[1] = 0.0;
}

void print(const state_t & s, double t)
{
  std::println("{:25.16e} {:25.16e} {:25.16e}", t, s[0], s[1]);
}

template <class deriv_t, class s_t, class print_t>
void integrate_euler(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer)
{
  // vector to store derivs
  state_t dsdt(s.size());

  // time loop
  for(double t = tinit; t <= tend; t = t + dt) { // NOTE: Last time step not necessarily tf
    // compute derivs
    deriv(s, dsdt, t, params);

    // compute new state. NOTE: Not using components, assuming valarray or similar
    s = s + dt*dsdt; // Euler

    // write new state
    writer(s, t);
  }
}
