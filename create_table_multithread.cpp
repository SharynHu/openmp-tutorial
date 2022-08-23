  #include <iostream>
  int main()
  {
    const int size = 8;
    double table[size];
    
    #pragma omp parallel for
    for(int n=0; n<size; ++n){
      table[n] = n;
      std::cout << table[n] << std::endl;
    }
    // the table is now initialized
  }

  /*
  The out put is:
  $ ./create_table_multithread.o 
  2
  3
  5
  4
  7
  0
  1
  6
  */