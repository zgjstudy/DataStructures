/*
*
*	数据结构
*	Queue抽象类
*	9.26
*
*/

#pragma once

template <typename T>
class Queue
{
private:
	void operator = (const Queue&) {}	// Protect assignment
	Queue(const Queue&) {}				// Protect copy constructor

public:
	Queue() {}
	virtual ~Queue() {}

	virtual void clear() = 0;

	virtual void enqueue(const T&) = 0;

	virtual T dequeue() = 0;

	virtual const T& frontValue() const = 0;

	virtual int length() const = 0;
};