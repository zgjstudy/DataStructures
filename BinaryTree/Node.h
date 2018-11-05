/*
*
*	数据结构第二次实验课
*	二叉树节点类
*	10.26 张冠杰
*
*/

#pragma once

//虚基类
template <typename T> class vBinNode
{
public:
	virtual ~vBinNode() {}
	virtual bool isLeaf() = 0;
};

//二叉树节点类
template <typename T> class BinNode : public vBinNode<T>
{
public:
	BinNode() {}

	explicit BinNode(BinNode &) {}

	virtual ~BinNode() {}

	virtual T& element() = 0;

	virtual void setElement(const T&) = 0;

	virtual BinNode* left() const = 0;

	virtual void setLeft(BinNode*) = 0;

	virtual BinNode* right() const = 0;

	virtual void setRight(BinNode*) = 0;

	virtual bool isLeaf() = 0;
};