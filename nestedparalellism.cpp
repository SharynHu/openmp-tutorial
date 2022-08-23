#include <iostream>
#include <omp.h>
#include <sstream>

using namespace std;

int main(){
    #pragma omp parallel
    {
      int thread_num = omp_get_thread_num();
      stringstream proctext;
      proctext<<"This is thread "<<thread_num<<".\n";
      cerr<<proctext.str();

      #pragma omp parallel
      {
        int thread_num_nested = omp_get_thread_num();
        stringstream proctext_nested;
        proctext_nested<<"This is subthread "<<thread_num_nested<<" of thread "<<thread_num<<".\n";
        cerr<<proctext_nested.str();
      }
    }
}


/*output
[hpchxj@login2 openmp-tutorial]$ ./nestedparalellism
This is thread 0.
This is thread 4.
This is thread 2.
This is thread 3.
This is thread 1.
This is subthread 0 of thread 2.
This is subthread 0 of thread 3.
This is subthread 0 of thread 1.
This is subthread 0 of thread 0.
This is subthread 0 of thread 4.
This is thread 5.
This is subthread 0 of thread 5.


[hpchxj@login2 openmp-tutorial]$ OMP_NESTED=true ./nestedparalellism
This is thread 5.
This is thread 4.
This is thread 3.
This is thread 1.
This is thread 2.
This is thread 0.
This is subthread 0 of thread 4.
This is subthread 2 of thread 5.
This is subthread 0 of thread 5.
This is subthread 5 of thread 4.
This is subthread 0 of thread 3.
This is subthread 0 of thread 2.
This is subthread 5 of thread 5.
This is subthread 3 of thread 2.
This is subthread 3 of thread 4.
This is subthread 2 of thread 3.
This is subthread 3 of thread 5.
This is subthread 4 of thread 4.
This is subthread 1 of thread 2.
This is subthread 5 of thread 2.
This is subthread 2 of thread 4.
This is subthread 4 of thread 5.
This is subthread 1 of thread 4.
This is subthread 5 of thread 3.
This is subthread 2 of thread 2.
This is subthread 4 of thread 2.
This is subthread 1 of thread 3.
This is subthread 4 of thread 3.
This is subthread 1 of thread 5.
This is subthread 3 of thread 3.
This is subthread 5 of thread 1.
This is subthread 1 of thread 1.
This is subthread 4 of thread 1.
This is subthread 3 of thread 1.
This is subthread 2 of thread 0.
This is subthread 0 of thread 0.
This is subthread 5 of thread 0.
This is subthread 1 of thread 0.
This is subthread 3 of thread 0.
This is subthread 0 of thread 1.
This is subthread 4 of thread 0.
This is subthread 2 of thread 1.
*/

