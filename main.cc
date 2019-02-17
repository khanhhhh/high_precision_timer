#include<iostream>
#include<timer.h>
void func()
{
	int x = 0;
	for (int i=0; i<1000000; ++i)
		x += i;
}
int main()
{
	auto t = timer::gettimer();
	auto t1 = t.now();
	func();
	auto t2 = t.now();
	std::cout<<timer::elapsed_time(t2, t1)<<std::endl;
	return 0;
}
