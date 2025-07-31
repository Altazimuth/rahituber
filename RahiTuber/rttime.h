
#pragma once

#include <stdint.h>

class Time
{
public:
	Time(const int64_t perfCounter = 0);

	static Time fromSeconds(const double s);
	static Time fromMilliseconds(const int64_t ms);
	static Time fromMicroseconds(const int64_t us);

	inline double asSeconds() const { return double(_performanceCounter) / Time::_performanceFrequency; }
	inline int64_t asMilliseconds() const { return _performanceCounter * 1000 / Time::_performanceFrequency; }
	inline int64_t asMicroseconds() const { return _performanceCounter * 1000000 / Time::_performanceFrequency; }
	inline int64_t performanceCounter() const { return _performanceCounter; }

	static const Time Zero;

private:
	int64_t _performanceCounter;
	static inline int64_t _performanceFrequency = 0;
};

inline bool operator == (const Time left, const Time right) { return left.performanceCounter() == right.performanceCounter(); }
inline bool operator != (const Time left, const Time right) { return left.performanceCounter() != right.performanceCounter(); }
inline bool operator <  (const Time left, const Time right) { return left.performanceCounter() < right.performanceCounter();  }
inline bool operator >  (const Time left, const Time right) { return left.performanceCounter() > right.performanceCounter();  }
inline bool operator <= (const Time left, const Time right) { return left.performanceCounter() <= right.performanceCounter(); }
inline bool operator >= (const Time left, const Time right) { return left.performanceCounter() >= right.performanceCounter(); }

inline Time operator - (const Time right) { return Time(-right.performanceCounter()); }

inline Time operator + (const Time left, const Time right) { return Time(left.performanceCounter() + right.performanceCounter()); }
inline Time &operator += (Time &left, const Time right)
{
	left = Time(left.performanceCounter() + right.performanceCounter());
	return left;
}
inline Time operator - (const Time left, const Time right) { return Time(left.performanceCounter() - right.performanceCounter()); }
inline Time &operator -= (Time &left, const Time right)
{
	left = Time(left.performanceCounter() - right.performanceCounter());
	return left;
}

inline Time operator * (const Time left, const double right)  { return Time(left.performanceCounter() * right); }
inline Time operator * (const Time left, const int64_t right) { return Time(left.performanceCounter() * right); }
inline Time operator * (const double left, const Time right)  { return Time(left * right.performanceCounter()); }
inline Time operator * (const int64_t left, const Time right) { return Time(left * right.performanceCounter()); }

inline Time &operator *= (Time &left, const double right)
{
	left = Time(left.performanceCounter() * right);
	return left;
}
inline Time &operator *= (Time &left, const int64_t right)
{
	left = Time(left.performanceCounter() * right);
	return left;
}

inline Time operator / (const Time left, const double right)  { return Time(left.performanceCounter() / right); }
inline Time operator / (const Time left, const int64_t right) { return Time(left.performanceCounter() / right); }

inline Time &operator /= (Time &left, const double right)
{
	left = Time(left.performanceCounter() / right);
	return left;
}
inline Time &operator /= (Time &left, const int64_t right)
{
	left = Time(left.performanceCounter() / right);
	return left;
}

inline double operator / (const Time left, const Time right) { return left.performanceCounter() / double(right.performanceCounter()); }

inline Time operator % (const Time left, const Time right) { Time(left.performanceCounter() % right.performanceCounter()); }
inline Time &operator %= (Time &left, const Time right)
{
	left = Time(left.performanceCounter() % right.performanceCounter());
	return left;
}


class Clock
{
public:
	Clock();

	Time restart();
	Time getElapsedTime() const;
private:
	Time _startTime;
};