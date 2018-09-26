/*
*
*	���ݽṹ
*	���е���˳�򼰺ϲ������ܵ�������
*	9.26
*
*/

#pragma once
#include "../List/List.h"
#include "../List/LinkWithFL.h"


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

	void prev()
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

	void next()
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

	void reverse()		//��ת����
	{
		if (count == 0)					//������ֱ�ӷ���
			return;

		tail->next = new Link<T>();		//��tail������δ����head
		curr = curr->next->next;		//ʹ��ת���currָ����ȷ��λ��

		Link<T>* temp1 = head->next;	
		delete head;
		head = temp1->next;
		tail = temp1;					//����tailָ��
		Link<T>* temp2 = nullptr;
		while (temp->next != nullptr)	//
		{
			temp1->next = temp2;
			temp2 = temp1;
			temp1 = head;
			head = temp1->next;
		}
		temp1->next = t2;
		head = temp1;					//����headָ��
	}

	template <typename T>
	friend bool merge(const LList<T>& input1, const LList<T>& input2, LList<T>& output)	//merge function
	{
		if (output.head->next != nullptr)
			return false;					//���ڷǿյĴ��������ֱ�ӷ���false

		Link<T>* pt1 = input1.head, *pt2 = input2.head;	//����������������в�����ָ��
		while (pt1->next != nullptr && pt2->next != nullptr)	//�鲢
		{
			if (pt1->next->element < pt2->next->element)
			{
				output.append(pt1->next->element);
				pt1 = pt1->next;
			}
			else
			{
				output.append(pt2->next->element);
				pt2 = pt2->next;
			}
		}
		while (pt1->next != nullptr)	//����input1δ�鲢��
		{
			output.append(pt1->next->element);
			pt1 = pt1->next;
		}
		while (pt2->next != nullptr)	//����input2δ�鲢��
		{
			output.append(pt2->next->element);
			pt2 = pt2->next;
		}
		return true;		//�ɹ�����
	}
};