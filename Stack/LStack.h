/*
*
*	数据结构
*	基于链表的栈实现
*	9.26
*
*/

#pragma once
#include "Stack.h"
#include "../List/LinkWithFL.h"

template <typename T>
class LStack : public Stack<T>
{
private:
	Link<T>* top;
	int size;
	static const int defaultSize = 10;

public:
	LStack(int size = defaultSize)
	{
		top = nullptr;
		size = 0;
	}

	~LStack()
	{
		clear();
	}

	void clear()
	{
		while (top != nullptr)
		{
			Link<T>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}

	void push(const T& it)
	{
		top = new Link<T>(it, top);
		size++;
	}

	T pop()
	{
		Assert(top != nullptr, "Stack is empty");
		Link<T>* temp = top;
		top = top->next;
		T it = temp->element;
		delete temp;
		size--;
		return it;
	}

	const T& topValue() const
	{
		Assert(top != 0, "Stack is empty");
		return top->element;
	}

	int length() const
	{
		return size;
	}
};