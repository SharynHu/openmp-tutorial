#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using std::mutex;

void function_1()
{
    for (int i = 0; i != 4; i++)
    {
        std::cout << "Function 1 i = " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


void function_2()
{
    for (int j = 0; j != 4; j++)
    {
        std::cout << "                   Function 2 j = " 
                  << j << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}


int main()
{
    std::thread thread_1(function_1);
    std::thread thread_2(function_2);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    int thread_num = omp_get_num_threads();
    std::cout<<"There are "<<thread_num<<" threads in the process.\n";
    
    thread_1.join();
    thread_2.join();
    
    return 0;
}