/*
*
*	数据结构第一次实验课
*	双向链表
*	10.12 张冠杰
*
*/


#pragma once
#include "List.h"
#include "dLinkWithFreeList.h"

template <typename T>
class LList : public List<T>
{
private:
	Link<T>* head;
	Link<T>* tail;
	Link<T>* curr;
	int count;

	void init()
	{
		curr = tail = head = new Link<T>;
		count = 0;
	}

	void removeAll()
	{
		while (head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList(int size = defaultSize)
	{
		init();
	}

	~LList()
	{
		removeAll();
	}

	void clear()
	{
		removeAll();
		init();
	}

	void insert(const T& it)
	{
		curr->next = new Link<T>(it, curr->next);
		if (tail == curr)
		{
			tail = curr->next;
		}
		count++;
	}

	void append(const T& it)
	{
		tail->next = new Link<T>(it, nullptr);
		tail = tail->next;
		count++;
	}

	T remove()
	{
		Assert(curr->next != nullptr, "No element");
		T it = curr->next->element;
		Link<T>* temp = curr->next;
		if (tail == curr->next)
		{
			tail = curr;
		}
		curr->next = curr->next->next;
		delete temp;
		count--;

		return it;
	}

	void moveToStart()
	{
		curr = head;
	}

	void moveToEnd()
	{
		curr = tail;
	}

	void pred()
	{
		if (curr == head)
			return;
		Link<T>* temp = head;
		while (temp->next != curr)
		{
			temp = temp->next;
		}
		curr = temp;
	}

	void succ()
	{
		if (curr != tail)
		{
			curr = curr->next;
		}
	}

	int length() const
	{
		return count;
	}

	int currPos() const
	{
		int i = 0;
		Link<T>* temp = head;
		while (temp != curr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}

	void moveToPos(int pos)
	{
		Assert(pos >= 0 && pos <= count, "Position out of range");
		curr = head;
		for (int i = 0; i < pos; ++i)
		{
			curr = curr->next;
		}
	}

	const T& getValue() const
	{
		Assert(curr->next != nullptr, "No value");
		return curr->next->element;
	}
};

