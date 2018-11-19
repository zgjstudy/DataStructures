/*
*
*	���ݽṹ������ʵ���
*	��ȷ��ʱ��
*	5.10 �Źڽ�
*
*/


#ifndef TIME_H
#define TIME_H

#include <windows.h>

//��ȷ��ʱ��
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

	//��ȡ΢��
	double getElapsedTimeInMicroSec()
	{
		LARGE_INTEGER endCount;
		QueryPerformanceCounter(&endCount);

		double  startTimeInMicroSec = _startCount.QuadPart * (1000000.0 / _frequency.QuadPart);
		double  endTimeInMicroSec = endCount.QuadPart * (1000000.0 / _frequency.QuadPart);

		return  endTimeInMicroSec - startTimeInMicroSec;
	}

	//��ú���
	double getElapsedTimeInMilliSec()
	{
		return this->getElapsedTimeInMicroSec() * 0.001;
	}

	//ˢ��ʱ��
	void update()
	{
		QueryPerformanceCounter(&_startCount);
	}
};

#endif // !TIME_H