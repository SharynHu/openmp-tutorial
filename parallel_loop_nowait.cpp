#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int i, n =4;
    #pragma omp parallel 
    {

        #pragma omp for nowait
        for(i = 0; i < n; i++) {
            printf("thread %d: ++++\n", omp_get_thread_num());
        }

        #pragma omp for
        for(i = 0; i < n; i++) {
            printf("thread %d: ----\n", omp_get_thread_num());
        }
    }
    return 0;
}
