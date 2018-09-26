/*
*
*	数据结构
*	基于数组的栈实现
*	9.26
*
*/

#pragma once
#include "Stack.h"

template <typename T>
class AStack : public Stack<T>
{
private:
	int maxSize;		// Maximum size of stack
	int top;			// Index for top element
	T* listArray;		// Array holding stack elements
	static const int defaultSize = 10;

public:
	AStack(int size = defaultSize)
	{
		maxSize = size;
		top = 0;
		listArray = new T[maxSize];
	}
	
	~AStack()
	{
		delete[] listArray;
	}

	void clear()
	{
		top = 0;
	}

	void push(const T& it)
	{
		Assert(top != maxSize, "Stack is full");
		listArray[top++] = it;
	}

	T pop()
	{
		Assert(top != 0, "Stack is empty");
		return listArray[--top];
	}

	const T& topValue() const
	{
		Assert(top != 0, "Stack is empty");
		return listArray[top - 1];
	}

	int length() const
	{
		return top;
	}
};