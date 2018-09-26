/*
*
*	数据结构
*	Queue array实现
*	9.26
*
*/

#pragma once
#include "Queue.h"

template <typename T>
class AQueue : public Queue<T>
{
private:
	int maxSize;
	int front;
	int rear;
	T* listArray;
	static const int defaultSize = 10;

public:
	AQueue(int size = defaultSize)
	{
		maxSize = size + 1;
		rear = 0;
		front = 1;
		listArray = new T[maxSize];
	}

	~AQueue()
	{
		delete[] listArray;
	}

	void clear()
	{
		rear = 0;
		front = 1;
	}

	void enqueue(const T& it)
	{
		Assert(((rear + 2) % maxSize) != front, "Queue is full");
		rear = (rear + 1) % maxSize;
		listArray[rear] = it;
	}

	T dequeue()
	{
		Assert(length() != 0, "Queue is empty");
		T it = listArray[front];
		front = (front + 1) % maxSize;
		return it;
	}

	const T& frontValue() const
	{
		Assert(length() != 0, "Queue is empty");
		return listArray[front];
	}

	virtual int length() const
	{
		return (rear - front + 1) % maxSize;
	}
};