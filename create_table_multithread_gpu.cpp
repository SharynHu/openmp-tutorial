  #include <iostream>
  int main()
  {
    const int size = 8;
    double table[size];
    
    #pragma omp target teams distribute parallel for map(from:table[0:8])
    for(int n=0; n<size; ++n){
      table[n] = n;
      // std::cout << table[n] << std::endl;
    }
    // the table is now initialized
  }

