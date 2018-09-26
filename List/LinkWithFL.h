/*
*
*	数据结构
*	带有FreeList的链表节点类
*	9.26
*
*/

#pragma once
template <typename T>
class Link
{
private:
	static Link<T>* freeList;

public:
	T element;
	Link* next;
	
	Link(Link* nextval = nullptr)
	{
		next = nextval;
	}

	Link(const T& elemval, Link<T>* nextval)
	{
		element = elemval;
		next = nextval;
	}

	void* operator new(size_t)
	{
		if (freeList == nullptr)
		{
			return ::new Link;
		}
		else
		{
			Link<T>* temp = freeList;
			freeList = freeList->next;
			return temp;
		}
	}

	void operator delete(void* ptr)
	{
		((Link<T>*)ptr)->next = freeList;
		freeList = (Link<T>*)ptr;
	}
};

//初始化Freelist
template <typename T>
Link<T>* Link<T>::freeList = nullptr;