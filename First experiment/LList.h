/*
*
*	���ݽṹ��һ��ʵ���
*	˫������
*	10.12 �Źڽ�
*
*/


#pragma once
#include "List.h"
#include "dLinkWithFreeList.h"

template <typename T>
class LList : public List<T>
{
private:
	Link<T>* header;	//ͷ�ڱ�
	Link<T>* tailer;	//β�ڱ�
	Link<T>* curr;		//��ǰ�ڵ�
	int size;			//��ģ

protected:
	void init();

	void removeAll();

public:
	LList(int size = DefaultSize);

	~LList();

	//clear
	void clear();

	//move to start
	void moveToStart();

	//move to end
	void moveToEnd();

	//curr point to predecessor
	void pred();

	//curr point to successor
	void succ();

	//insert as successor
	void insert(const T&);

	//insert as predecessor
	void insertAsPred(const T&);

	//insert as last
	void append(const T&);

	//insert as first
	void insertAsFirst(const T&);

	//remove curr node, then curr point to successor
	//return curr->element
	T remove();

	//remove pth node
	T remove(int p);

	virtual void length() const;

	virtual int currPos() const;

	virtual void moveToPos(int pos);

	virtual const T& getValue() const;

};

