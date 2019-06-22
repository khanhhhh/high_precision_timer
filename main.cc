#include<iostream>
#include<timer.h>
#include<chrono>
#include<thread>
int main()
{
	auto t = timer();
	auto t1 = t.now();


	auto t2 = t.now();
	std::cout<<timer::elapsed_time(t2, t1)<<std::endl;
	return 0;
}
