#include<iostream>
#include<timer.h>
#include<chrono>
#include<thread>
void func()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
int main()
{
	auto t = timer();
	while (true)
	{
	auto t1 = t.now();
	func();
	auto t2 = t.now();
	std::cout<<timer::elapsed_time(t2, t1)<<std::endl;
	}
	return 0;
}
