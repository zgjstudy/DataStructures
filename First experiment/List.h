/*
*
*	数据结构第一次实验课
*	List抽象基类
*	10.12 张冠杰
*
*/

#pragma once

template <typename T>
class List
{
private:
	void operator = (const List&) {}
	List(const List&) {}

public:
	virtual ~List() {}	//虚析构

	virtual init() = 0;	//初始化

	virtual void insert(const T& item) = 0;	//在curr之后插入

	virtual void append(const T& item) = 0;	//尾插入

	virtual T remove() = 0;	//移除curr

	virtual void moveToStart() = 0;	//curr指向首元素

	virtual void moveToEnd() = 0;	//curr指向尾元素

	virtual void pred() = 0;	//curr指向前驱节点

	virtual void succ() = 0;	//curr指向后继节点

	virtual int length() const = 0;	//返回list长度

	virtual int currPos() const = 0;	//curr元素的序号

	virtual void moveToPos(int pos) = 0;	//移动到pos号元素

	virtual const T& getValue() const = 0;	//返回当前元素
};