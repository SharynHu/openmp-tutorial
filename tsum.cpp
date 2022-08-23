#include <omp.h>
#include <stdio.h>

using namespace std;

int main(){
    int thread_num;
    int tsum;

    #pragma omp parallel
    {
      tsum += omp_get_thread_num();
      printf("Sum is %d\n",tsum);
    }
}
/*
Sum is 4
Sum is 4
Sum is 9
Sum is 10
Sum is 13
Sum is 15
*/
