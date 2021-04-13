#include<iostream>
#include"high_precision_timer.h"
#include<chrono>
#include<thread>
int main()
{
    auto t1 = timer::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto t2 = timer::now();
    std::cout<<t2 - t1<<std::endl;
    return 0;
}
