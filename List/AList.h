/*
*	
*	数据结构
*	AList类
*	9.25
*
*/

#pragma once
#include "List.h"

template <typename T>
class AList : public List<T>
{
private:
	int maxSize;
	int listSize;
	int curr;
	T* listArray;
	static const int defaultSize = 10;

public:
	AList(int size = defaultSize)
	{
		maxSize = size;
		listSize = curr = 0;
		listArray = new T[maxSize];
	}

	~AList()
	{
		delete[] listArray;
	}

	void clear()
	{
		delete[] listArray;
		listSize = curr = 0;
		listArray = new T[maxSize];
	}

	// Insert "it" at current position
	void insert(const T& it)
	{
		if (listSize < maxSize)				//边界检查
		{
			for (int i = listSize; i > curr; --i)
				listArray[i] = listArray[i - 1];
			listArray[curr] = it;
			listSize++;
		}
		else
		{
			throw "List capacity exceeded";
		}
	}

	// Append an element at the end of the list.
	void append(const T& it)				//边界检查
	{
		Assert(listSize < maxSize, "List capacity exceeded");
		listArray[listSize++] = it;
	}

	// Remove and return the current element.
	T remove()
	{
		Assert(curr >= 0 && curr < listSize, "No element");
		T it = listArray[curr];
		for (int i = curr; i < listSize - 1; ++i)
			listArray[i] = listArray[i + 1];
		listSize--;
		return it;
	}

	void moveToStart()
	{
		curr = 0;
	}

	void moveToEnd()
	{
		curr = listSize;
	}

	void prev()
	{
		if (curr != 0)
			curr--;
	}

	void next()
	{
		if (curr < listSize) curr++;
	}

	int length() const
	{ 
		return listSize;
	}

	int currPos() const
	{
		return curr;
	}

	void moveToPos(int pos)
	{
		Assert(pos >= 0 && pos <= listSize, "Pos out of range");
		curr = pos;
	}

	const T& getValue() const
	{
		Assert(curr >= 0 && curr < listSize, "No current element");
		return listArray[curr];
	}
};