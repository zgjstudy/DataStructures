/*
*
*	数据结构
*	Linked Queue 实现
*	10.6
*
*/

#pragma once
#include "Queue.h"
#include "../List/LinkWithFL.h"

template <typename T>
class LQueue : public Queue<T>
{
private:
	Link<T>* front;
	Link<T>* rear;
	int size;
	const static int defaultSize = 10;

public:
	LQueue(int size = defaultSize)
	{
		front = rear = new Link<T>();
		size = 0;
	}

	~LQueue()
	{
		clear();
		delete front;
	}

	void clear()
	{
		while (front->next != nullptr)
		{
			rear = front;
			front = front->next;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	void enqueue(const T& it)
	{
		rear->next = new Link<T>(it, nullptr);
		rear = rear->next;
		size++;
	}

	T dequeue()
	{
		Assert(size != 0, "Queue is enpty");
		T it = front->element;
		Link<T>* temp = front->next;
		delete front;
		front = temp;
		size--;
		return it;
	}

	const T& frontValue() const
	{
		Assert(size != 0, "Queue is empty");
		return front->next->element;
	}

	virtual int length() const
	{
		return size;
	}
};