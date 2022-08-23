#include <iostream>
#include <stdio.h>
#include <omp.h>

int main(){
    double y;
    #pragma omp parallel
    {
        #pragma omp master
        {
            int thread_num = omp_get_thread_num();
            std::cout<<"Master code block1 is executed by thread "+std::to_string(thread_num)+".\n";
        }
    
        #pragma omp sections 
       {
            #pragma omp section
            {
                int thread_num = omp_get_thread_num();
                std::cout<<"Section code block1 is executed by thread "+std::to_string(thread_num)+".\n";   
            }
            #pragma omp section
            {
                int thread_num = omp_get_thread_num();
                std::cout<<"Section code block2 is executed by thread "+std::to_string(thread_num)+".\n";   
            }
        }
        #pragma omp master
        {
            int thread_num = omp_get_thread_num();
            std::cout<<"Master code block2 is executed by thread "+std::to_string(thread_num)+".\n";
        }
        
    }
}


/*
[hpchxj@cas505 openmp-tutorial]$ ./master 
Section code block1 is executed by thread 3.
Master code block1 is executed by thread 0.
Section code block2 is executed by thread 2.
Master code block2 is executed by thread 0.
*/