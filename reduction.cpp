#include <stdio.h>
#include <iostream>
#include <omp.h>


using namespace std;

int main(){
    using namespace std;
    int result=0;
    int N=1000;
    #pragma omp parallel for reduction(+:result)
    // #pragma omp parallel for
    for(int i=0;i<N;i++){
        result += 1;
    }
    cout<<result<<"\n";
}








