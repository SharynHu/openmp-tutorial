#include <iostream>
#include <stdio.h>

int main(){
    double y;
    #pragma omp parallel
    {
        #pragma omp single
        std::cout<<"Prigram starting...\n";
        #pragma omp sections reduction(+:y)
        {
            #pragma omp section
            y += 3.5;
            #pragma omp section
            y += 4.5;
        }
        #pragma omp single
        std::cout<<"y="<<y<<"\n";
    }
}


/*
Prigram starting...
y=8
*/