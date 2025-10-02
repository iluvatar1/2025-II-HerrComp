// imprimir una tabla con
// n sumup(n) sumdown(n) diff_rel
// sumup(n) = sum_{i=1}^n 1/i
// sumdown(n) = sum_{i=n}^1 1/i
// diff_rel = |1 - sumup/sumdown|

#include <print>
#include <fstream>
#include <cmath>

// declaration
float sumup(int n);
float sumdown(int n);

int main()
{
    std::ofstream fout("data.txt");

    for(int nmax = 1; nmax < 1000000000; nmax = 2*nmax) {
        float resup = sumup(nmax);
        float resdown = sumdown(nmax);
        float diff = std::fabs(1 - resup/resdown);
        std::println(fout, "{:12} {:15.6e} {:15.6e} {:15.6e}", nmax, resup, resdown, diff);
    }    

    fout.close();

    return 0;
}

// implementation
float sumup(int n)
{
    float suma = 0.0;
    for (int ii = 1; ii <= n; ii++) {
        suma = suma + 1.0/ii;
    }
    return suma;
}

float sumdown(int n)
{
    float suma = 0.0;
    for (int ii = n; ii >= 1; ii--) {
        suma = suma + 1.0/ii;
    }
    return suma;
}
