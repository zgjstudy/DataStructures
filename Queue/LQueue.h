/*
*
*	���ݽṹ
*	Linked Queue ʵ��
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