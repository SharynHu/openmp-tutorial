#include <iostream>
#include <omp.h>
#include <sstream>

using namespace std;

int main(){
    int num_procs = omp_get_num_procs();
    int num_threads= omp_get_num_threads();
    int thread_num = omp_get_thread_num();
    cout<< "Before the parallel, there are "<<num_procs<<" processors available, "
        <<num_threads<<" threads are active, and this is thread "<<thread_num<<".\n";

    #pragma omp parallel
    {
      int num_procs_parallel = omp_get_num_procs();
      int num_threads_parallel= omp_get_num_threads();
      int thread_num_parallel = omp_get_thread_num();
      stringstream proctext;
      proctext<<"In the parallel region, there are "<<num_procs_parallel<<" processors available, "
        <<num_threads_parallel<<" threads are active, and this is thread "<<thread_num_parallel<<".\n";
      cerr<<proctext.str();
    }
    num_procs = omp_get_num_procs();
    num_threads= omp_get_num_threads();
    thread_num = omp_get_thread_num();
    cout<<"After the parallel region, there are "<<num_procs<<" processors available, "
        <<num_threads<<" threads are active, and this is thread "<<thread_num<<".\n";
    return 0;
}

/*output
[hpchxj@cas073 openmp-tutorial]$ ./hello 
Before the parallel, there are 2 processors available, 1 threads are active, and this is thread 0.
In the parallel region, there are 2 processors available, 2 threads are active, and this is thread 0.
In the parallel region, there are 2 processors available, 2 threads are active, and this is thread 1.
After the parallel region, there are 2 processors available, 1 threads are active, and this is thread 0.


The parallel construct starts a parallel block.
It creates a team of N threads 
(where N is determined at runtime, usually from the number of CPU cores, 
but may be affected by a few things), all of which execute the next statement (or the next block, 
if the statement is a {…} -enclosure). After the statement, the threads join back into one.

This code corresponds to the model we just discussed:
    Immediately preceding the parallel block, one thread will be executing the code. In the main program this is the initial thread .
    
    At the start of the block, a new team of threads is created, and the thread that was active before the block becomes the master thread of that team.
    
    After the block only the master thread is active.
    
    Inside the block there is team of threads: each thread in the team executes the body of the block, 
    and it will have access to all variables of the surrounding environment. 
*/

