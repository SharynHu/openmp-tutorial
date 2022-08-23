#include <iostream>
#include <sstream>
#include "omp.h"

using namespace std;

int main(){
    cout<<"First let openmp decide the loop bounds.\n";
    int N = 10;
    #pragma omp parallel
    {
        stringstream proctext1;
        int thread_num1 = omp_get_thread_num();
        proctext1<<"This is thread "<<thread_num1<<" .\n";
        
        #pragma omp for
        // this directive won't create a team of threads. So the for is distributed among the threads before.
        for(int i=1; i<=4*N; i++) {
            proctext1<<i<<" ";
        }
        proctext1<<"\n";
        cerr<<proctext1.str();
    }
    cout<"\n\n";
    cout<<"Now designate the loop bounds on our own.\n";
    
    
    #pragma omp parallel
    {
        stringstream proctext1;
        int thread_num1 = omp_get_thread_num();
        proctext1<<"This is thread "<<thread_num1<<" .\n";
        
        int low = N*thread_num1, high = N*(thread_num1+1);
        
        for (int i=high; i>low; i--){
            proctext1<<i<<" ";
        }
        proctext1<<"\n";
        cerr<<proctext1.str();
    }
            
}
/*
Note that the do and for pragmas do not create a team of threads: they take the team of threads
 that is active, and divide the loop iterations over them. This means that the omp for or omp 
 do directive needs to be inside a parallel region.
 */

/*output
[hpchxj@cas554 openmp-tutorial]$ ./parallelloop 
First let openmp decide the loop bounds.
This is thread 3 .
31 32 33 34 35 36 37 38 39 40 
This is thread 2 .
21 22 23 24 25 26 27 28 29 30 
This is thread 0 .
1 2 3 4 5 6 7 8 9 10 
This is thread 1 .
11 12 13 14 15 16 17 18 19 20 
Now designate the loop bounds on our own.
This is thread 3 .
40 39 38 37 36 35 34 33 32 31 
This is thread 2 .
30 29 28 27 26 25 24 23 22 21 
This is thread 0 .
10 9 8 7 6 5 4 3 2 1 
This is thread 1 .
20 19 18 17 16 15 14 13 12 11 
*/