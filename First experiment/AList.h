/*
*
*	数据结构第一次实验课
*	AList线性表
*	10.12 张冠杰
*
*/


#pragma once
#include "List.h"

template <typename T>
class AList : public List<T>
{
private:
	int _maxSize;
	int _size;
	int _curr;
	T* _listArray;
	static const int DefaultSize = 10;

public:
	AList(int size = DefaultSize)
	{
		_maxSize = size;
		size = _curr = 0;
		_listArray = new T[_maxSize];
	}

	~AList()
	{
		delete[] _listArray;
	}

	void clear()
	{
		delete[] _listArray;
		_size = _curr = 0;
		_listArray = new T[_maxSize];
	}

	// Insert "it" at current position
	void insert(const T& it)
	{
		Assert(listSize < maxSize, "List capacity exceeded");
			for (int i = _size; i > _curr; --i)
				_listArray[i] = _listArray[i - 1];
			_listArray[_curr] = it;
			_size++;
	}

	// Append an element at the end of the list.
	void append(const T& it)
	{
		Assert(_size < _maxSize, "List capacity exceeded");
		_listArray[_size++] = it;
	}

	// Remove and return the current element.
	T remove()
	{
		Assert(_curr >= 0 && _curr < _size, "No element");
		T it = _listArray[_curr];
		for (int i = _curr; i < _size - 1; ++i)
			_listArray[i] = _listArray[i + 1];
		_size--;
		return it;
	}

	void moveToStart()
	{
		_curr = 0;
	}

	void moveToEnd()
	{
		_curr = _size;
	}

	void pred()
	{
		if (_curr != 0)
			_curr--;
	}

	void succ()
	{
		if (_curr < _size) _curr++;
	}

	int length() const
	{
		return _size;
	}

	int currPos() const
	{
		return _curr;
	}

	void moveToPos(int pos)
	{
		Assert(pos >= 0 && pos <= _size, "Pos out of range");
		_curr = pos;
	}

	const T& getValue() const
	{
		Assert(_curr >= 0 && _curr < _size, "No current element");
		return _listArray[_curr];
	}
};