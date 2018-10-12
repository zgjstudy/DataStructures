/*
*
*	���ݽṹ��һ��ʵ���
*	����FreeList��˫������ڵ���
*	10.12 �Źڽ�
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
	Link* prev;

	Link(Link* pp = nullptr, Link* np = nullptr)
		:prev(pp), next(np) {}

	Link(const T& it, Link* pp, Link* np)
		:element(it), prev(pp), nextp(np) {}

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

//��ʼ��Freelist
template <typename T>
Link<T>* Link<T>::freeList = nullptr;