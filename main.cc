#include<iostream>
#include<timer.h>
#include<chrono>
#include<thread>
inline void func()
{
	int x;
	for (int i=0; i<30; ++i)
		x += i;
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
