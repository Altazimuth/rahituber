
#include <SDL3/SDL.h>

#include "rttimer.h"

const Time Time::Zero = Time();

Time::Time(const int64_t perfCounter)
{
	if(Time::_performanceFrequency == 0)
	{
		Time::_performanceFrequency = SDL_GetPerformanceFrequency();
	}

	_performanceCounter = perfCounter;
}

Time Time::fromSeconds(double s)
{
	Time ret;
	ret._performanceCounter = int64_t(s * Time::_performanceFrequency);
	return ret;
}

Time Time::fromMilliseconds(int64_t ms)
{
	Time ret;
	ret._performanceCounter = int64_t(ms * Time::_performanceFrequency * 1000);
	return ret;
}

Time Time::fromMicroseconds(int64_t us)
{
	Time ret;
	ret._performanceCounter = int64_t(us * Time::_performanceFrequency * 1000000);
	return ret;
}

Clock::Clock()
{
	_startTime = SDL_GetPerformanceCounter();
}

Time Clock::restart()
{
	_startTime = SDL_GetPerformanceCounter();
}

Time Clock::getElapsedTime() const
{
	return Time(SDL_GetPerformanceCounter() - _startTime);
}