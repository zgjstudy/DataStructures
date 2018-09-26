/*
*
*	数据结构
*	栈抽象类
*	9.26
*
*/

#pragma once
template <typename T>
class Stack
{
private:
	void operator = (const Stack&) {}	// Protect assignment
	Stack(const Stack&) {}	// Protect copy constructor

public:
	Stack() {}
	virtual ~Stack() {}

	virtual void clear() = 0;

	virtual Stack<T>& push(const T& it) = 0;

	virtual T pop() = 0;

	virtual const T& topValue() const = 0;

	virtual int length() const = 0;
};