/*
*
*	数据结构第三次实验课
*	精确计时类
*	5.10 张冠杰
*
*/


#ifndef TIME_H
#define TIME_H

#include <windows.h>

//精确计时类
class Timestamp
{
protected:
	LARGE_INTEGER _frequency;
	LARGE_INTEGER _startCount;

public:
	Timestamp()
	{
		QueryPerformanceFrequency(&_frequency);
		QueryPerformanceCounter(&_startCount);
	}

	//获取微秒
	double getElapsedTimeInMicroSec()
	{
		LARGE_INTEGER endCount;
		QueryPerformanceCounter(&endCount);

		double  startTimeInMicroSec = _startCount.QuadPart * (1000000.0 / _frequency.QuadPart);
		double  endTimeInMicroSec = endCount.QuadPart * (1000000.0 / _frequency.QuadPart);

		return  endTimeInMicroSec - startTimeInMicroSec;
	}

	//获得毫秒
	double getElapsedTimeInMilliSec()
	{
		return this->getElapsedTimeInMicroSec() * 0.001;
	}

	//刷新时钟
	void update()
	{
		QueryPerformanceCounter(&_startCount);
	}
};

#endif // !TIME_H