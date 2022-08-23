#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    double pi = 0.0;
    int N = 100;
    #pragma omp parallel for reduction(+:pi)
    for(int i=0; i<N; i++){
        double x = double(i)/double(N);
        double delta_x = 1.0/double(N);
        pi += 4.0 *delta_x*sqrt(1-pow(x,2));
    }
    
    cout<<"The calculated pi is "<<pi<<".\n";
}