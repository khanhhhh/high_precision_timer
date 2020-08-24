#include<iostream>
#include<timer.h>
#include<chrono>
#include<thread>
int main()
{
	auto t1 = now();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	auto t2 = now();
	std::cout<<t2 - t1<<std::endl;
	return 0;
}
