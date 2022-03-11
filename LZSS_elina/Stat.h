#pragma once
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <chrono>
#include <string>


size_t getSize(const std::string& filename);
class Timer
{
public:
	Timer();
	void reset();
	double elapsed();

private:
	typedef std::chrono::high_resolution_clock clock;
	typedef std::chrono::duration<std::chrono::milliseconds> milliseconds;
	std::chrono::time_point<clock> beg;
};


class AvCounter {
	double dval;
	int times;
public:
	AvCounter();
	void AddVal(double in);
	double GetAvg();
};
