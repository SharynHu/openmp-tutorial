#include <stdio.h>
#include <iostream>


int main(){
    double y;
    #pragma omp parallel 
    #pragma omp sections reduction(+:y)
    {
        
        #pragma omp section
        y += 3.5;
        #pragma omp section
        y += 4.5;
    }
    std::cout<<"y="<<y<<"\n";
}