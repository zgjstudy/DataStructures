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
	Link<T>* header;	//头哨兵
	Link<T>* tailer;	//尾哨兵
	Link<T>* curr;		//当前节点
	int size;			//规模

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

