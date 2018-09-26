/*
*
* 数据结构
* Link链表节点类
* 9.25
*
*/

#pragma once

// linked list node
template <typename T>
class Link
{
public:
	T element; // Value for this node
	Link *next; // Pointer to next node in list

	Link(const T& elemval, Link* nextval = NULL)
	{
		element = elemval;
		next = nextval;
	}

	Link(Link* nextval = NULL)
	{
		next = nextval;
	}
};
