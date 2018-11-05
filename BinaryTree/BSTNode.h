/*
*
*	数据结构第二次实验课
*	BST节点类
*	10.26 张冠杰
*
*/

#pragma once
#include "Node.h"

template <typename KEY, typename T> class BSTNode : public BinNode<T>
{
private:
	KEY		_key;
	T		_value;
	BSTNode *_lc;
	BSTNode *_rc;

public:
	BSTNode()
		:_rc(nullptr), _lc(nullptr) {}

	BSTNode(KEY K, T e, BSTNode* l = nullptr, BSTNode* r = nullptr)
		:_key(K), _value(e), _lc(l), _rc(r) {}

	~BSTNode() {};

	T& element() { return _value; }
	void setElement(const T& e) { _value = e; }

	KEY& key() { return _key; }
	void setKey(const KEY& K) { _key = K; }

	inline BSTNode* left() const { return _lc; }
	void setLeft(BinNode<T>* b) { _lc = (BSTNode*)b; }
	inline BSTNode* right() const { return _rc; }
	void setRight(BinNode<T>* b) { _rc = (BSTNode*)b; }

	bool isLeaf()
	{
		return (_lc == nullptr) && (_rc == nullptr);
	}
};

