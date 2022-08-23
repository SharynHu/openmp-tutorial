#include <stdio.h>
#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    long int nsteps=100000000;
    double quarterpi=0, pi;
    #pragma omp parallel for reduction(+:quarterpi) schedule(guided,100000)
    for (int i=0; i<nsteps; i++) {
        double h = 1.0/double(nsteps);
        double x = i*h,x2 = (i+1)*h, y = sqrt(1-x*x),y2 = sqrt(1-x2*x2), slope = (y-y2)/h;
        if (slope>15) slope = 15;
        int samples = 1+(int)slope, is;
        for (is=0; is<samples; is++) {
            double hs = h/samples, xs = x+ is*hs, ys = sqrt(1-xs*xs);
            quarterpi += hs*ys;
            // nsamples++;
        }
    }
    pi = 4*quarterpi;
    cout<<"The calculated pi is "<<pi<<".\n";
}

/*run in parallel

real    0m6.513s
user    0m6.496s
sys     0m0.001s
*/

/*
Without the schedule clasue:
real    0m2.505s
user    0m6.717s
sys     0m0.005s
*/

/*
#pragma omp parallel for reduction(+:quarterpi) schedule(static)
real    0m2.503s
user    0m6.710s
sys     0m0.004s
*/


/*
#pragma omp parallel for reduction(+:quarterpi) schedule(static,10000)
real    0m1.695s
user    0m6.740s
sys     0m0.005s
*/


/*
#pragma omp parallel for reduction(+:quarterpi) schedule(dynamic)

real    0m5.311s
user    0m21.173s
sys     0m0.005s
*/


/*
#pragma omp parallel for reduction(+:quarterpi) schedule(dynamic,10000)
real    0m1.696s
user    0m6.749s
sys     0m0.004s
*/

/*
#pragma omp parallel for reduction(+:quarterpi) schedule(guided)
real    0m1.694s
user    0m6.741s
sys     0m0.003s
*/