/*
*
*	数据结构
*	基于指针的二叉树实现
*	10.7
*
*/


#pragma once
#include "BinNode.h"

template <typename Key, typename E>
class BSTNode : public BinNode<E>
{
private:
	Key k;
	E it;
	BSTNode* lc;	//left child
	BSTNode* rc;

public:
	BSTNode()
	{
		lc = rc = nullptr;
	}

	BSTNode(Key K, E e, BSTNode* l = nullptr, BSTNode* r = nullptr)
	{
		k = K;
		it = e;
		lc = l;
		rc = r;
	}

	~BSTNode() {};

	E& element() { return it; }
	void setElement(const E& e) { it = e; }

	Key& key() { return k; }
	void setKey(const Key& K) { k = K; }

	inline BSTNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
	inline BSTNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

	bool isLeaf()
	{
		return (lc == nullptr) && (rc = nullptr);
	}
};