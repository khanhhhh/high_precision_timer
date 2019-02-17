#include<Windows.h>
#include<cstdint>
namespace windows{
class timer
{
	private:
	static int64_t freq;
	timer()
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
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
		int64_t t;
		QueryPerformanceCounter((LARGE_INTEGER*)&t);
		return t;
	}
	static inline double elapsed_time(int64_t t2, int64_t t1)
	{
		return 1000000000*static_cast<double>(t2-t1)/freq;
	}
};
timer* timer::t = nullptr;
int64_t timer::freq = 1;
}
