#include <iostream>
using namespace std;

int main(){
    #pragma omp parallel
    {
    //   printf("hello!\n");
      cout<<"hello!\n";
    }
    return 0;
}
