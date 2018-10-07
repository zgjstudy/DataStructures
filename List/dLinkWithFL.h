/*
*
*	数据结构
*	带有FreeList的双向链表节点类
*	10.7
*
*/

#pragma once
template <typename T>
class Link
{
private:
	static Link<T>* freelist;

public:
	T element;
	Link* next;
	Link* prev;

	Link(const T& it, Link* prevp, Link*nextp)
	{
		element = it;
		prev = prevp;
		next = nextp;
	}

	Link(Link* pp = nullptr, Link* np = nullptr)
	{
		prev = pp;
		next = np;
	}

	void* operator new(size_t)
	{
		if (freelist == nullptr)
			return ::new Link;
		Link<T>* temp = freelist;
		freelist = freelist->next;
		return temp;
	}

	void operator delete(void* ptr)
	{
		((Link<T>*)ptr)->next = freelist;
		freelist = (Link<T>*)ptr;
	}
};

template <typename T>
Link<T>* Link<T>::freelist = nullptr;