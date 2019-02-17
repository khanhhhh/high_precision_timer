#ifdef _WIN32
#include<Windows.h>
#else
#include<ctime>
#endif
#include<cstdint>
class timer
{
	private:
	#ifdef _WIN32
	static int64_t freq;
	#endif
	timer()
	{
		#ifdef _WIN32
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		#endif
	}
	static timer *t;
	public:
	static timer& gettimer()
	{
		if (t == nullptr) t = new timer();
		return *t;
	}
	~timer()
	{}
	inline int64_t now()
	{
		#ifdef _WIN32
		LARGE_INTEGER t;
		QueryPerformanceCounter(&t);
		return 1000000000*t.QuadPart/freq;
		#else
		struct timespec tp;
		clock_gettime(CLOCK_MONOTONIC_RAW, &tp);
		return static_cast<int64_t>(1000000000*tp.tv_sec) + static_cast<int64_t>(tp.tv_nsec);
		#endif
	}
	static inline double elapsed_time(int64_t t2, int64_t t1)
	{
		return static_cast<double>(t2-t1);
	}
};
timer* timer::t = nullptr;
#ifdef _WIN32
int64_t timer::freq = 1;
#endif
