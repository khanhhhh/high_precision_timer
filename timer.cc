#include<Windows.h>
#include<iostream>
#include<cstdint>
#include<omp.h>
#include<thread>
#include<chrono>
#include<ctime>
void func()
{
	int x = 0;
	for (int i=0; i<1000000; ++i)
		x += i;
}
int main()
{
	{
		std::cout<<"timer precision: "<<1000*omp_get_wtick()<<" ms"<<std::endl;
		auto t1 = omp_get_wtime();
		func();
		auto t2 = omp_get_wtime();
		std::cout<<"omp: "<<t2-t1<<std::endl;
	}
	{
		auto t1 = std::clock();
		func();
		auto t2 = std::clock();
		std::cout<<"clock: "<<1000*(t2-t1)/CLOCKS_PER_SEC<<" ms"<<std::endl;
	}
	{
		FILETIME t1;
		GetSystemTimeAsFileTime(&t1);
		std::cout<<"windows1: "<<t1.dwLowDateTime<<":"<<t1.dwHighDateTime<<std::endl;
		func();
		FILETIME t2;
		GetSystemTimeAsFileTime(&t2);
		std::cout<<"windows2: "<<t2.dwLowDateTime<<":"<<t2.dwHighDateTime<<std::endl;
		std::cout<<(t2.dwLowDateTime - t1.dwLowDateTime)/10000<<" ms"<<std::endl;
	}
	{
		auto t1 = std::chrono::high_resolution_clock::now();
		func();
		auto t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = t2-t1;
		std::cout<<"chrono: "<<1000*diff.count()<<" ms"<<std::endl;
	}


	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	int64_t *fp = (int64_t*)&freq;
	std::cout<<*fp<<std::endl;
	int64_t f = *fp;





	{
		LARGE_INTEGER t1;
		if (0 == QueryPerformanceCounter(&t1)) __builtin_trap();
		func();
		LARGE_INTEGER t2;
		if (0 == QueryPerformanceCounter(&t2)) __builtin_trap();
		int64_t *tt1 = (int64_t*)&t1;
		int64_t *tt2 = (int64_t*)&t2;
		double diff = *tt2 - *tt1;
		std::cout<<"...: "<<1000*diff/f<<" ms"<<std::endl;
	}
	return 0;
}
