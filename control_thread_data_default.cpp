#include <stdio.h>
#include <iostream>
#include <omp.h>
using namespace std;

int main(){
	int p=10 ; 
    // the value of p is 20

    #pragma omp parallel private(p)
    {
        // the value of p is undefined
        // p = omp_get_thread_num();
        // the value of p is defined
		#pragma omp critical 
		cout << p <<"\n";
    }
}

