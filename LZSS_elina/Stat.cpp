#include "Stat.h"

size_t getSize(const std::string& filename)
{
	std::ifstream myfile(filename, std::ios::binary | std::ios::ate);
	myfile.seekg(0, std::ios::end);
	size_t sz = (size_t)myfile.tellg();
	myfile.close();
	return sz;
}


Timer::Timer() : beg(clock::now()) {}
void Timer::reset() { beg = clock::now(); }
double Timer::elapsed() {
	return (double)std::chrono::duration_cast<std::chrono::milliseconds>
		(clock::now() - beg).count();
}



AvCounter::AvCounter() { dval = 0; times = 0; };
void AvCounter::AddVal(double in)
{
	dval += in; times += 1;
}
double AvCounter::GetAvg()
{
	if (times > 0)
		return dval / times;
	else
		return 0;
}

