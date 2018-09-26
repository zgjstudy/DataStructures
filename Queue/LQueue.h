/*
*
*	数据结构
*	Linked Queue 实现
*	9.26
*
*/

#pragma once
#include "Queue.h"
#include "../List/LinkWithFL.h"

template <typename T>
class LQueue : public Queue<T>
{
private:
	Link<T>* front;
	Link<T>* rear;
	int size;

public:

};