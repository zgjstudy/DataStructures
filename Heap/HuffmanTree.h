/*
*
*	数据结构第二次实验课
*	HuffmanTree类
*	10.26 张冠杰
*
*/

#pragma once
#include <cstring>
#include <string>
#include "Heap.h"

#include <iostream>
using namespace std;

using std::string;

//虚基类
template <typename T> class HuffNode
{
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};

//叶子结点类
template <typename T> class LeafNode : public HuffNode<T>
{
private:
	T _value;
	int _weight;

public:
	LeafNode(const T& v, const int w)
		:_value(v), _weight(w) {}

	bool isLeaf() { return true; }
	int weight() { return _weight; }
	T getValue() { return _value; }
};

//内部结点类
template <typename T> class IntlNode : public HuffNode<T>
{
private:
	HuffNode<T>* _lc;
	HuffNode<T>* _rc;
	int _weight;

public:
	IntlNode(HuffNode<T>* l, HuffNode<T>* r)	//构建时将权重相加
		:_lc(l), _rc(r)
	{
		_weight = _lc->weight() + _rc->weight();
	}

	bool isLeaf() { return false; }
	int weight() { return _weight; }
	HuffNode<T>* left() const { return _lc; }
	HuffNode<T>* right() const { return _rc; }
};

//森林类
template <typename T> class HuffForest
{
private:
	struct Comp	//比较方法
	{
		static bool prior(HuffNode<T>* a, HuffNode<T>* b)	//权重小的排在前
		{
			return a->weight() < b->weight();
		}

		static void swap(HuffNode<T>*& a, HuffNode<T>*& b)	//交换函数
		{
			HuffNode<T>* temp = a;
			a = b;
			b = temp;
		}
	};
	heap<HuffNode<T>*, Comp>* _huffForest;
	std::pair<T, string>* _coding;	//储存编码表
	int _count;
	int _max = 100;
	HuffNode<T>* _root;

	//建立哈夫曼树
	void buildHuff()
	{
		HuffNode<T> *temp1, *temp2;
		IntlNode<T> *_root = NULL;
		while (_huffForest->size() > 1)
		{
			temp1 = _huffForest->remove();	//取出两颗树
			temp2 = _huffForest->remove();
			_root = new IntlNode<T>(temp1, temp2);	//合并
			_huffForest->insert((HuffNode<T>*)_root);	//放入堆中
		}
		_count = 0;
		coding(_root, string(""));	//导出编码表
	}

	//编码函数
	void coding(HuffNode<T>* root, string code)
	{
		if (root->isLeaf())	//对于叶节点进行编码
		{
			_coding[_count++] = make_pair(((LeafNode<T>*)root)->getValue(), code);
			return;
		}
		coding(((IntlNode<T>*)root)->left(), code + '0');	//对于左子树编码值为'0'
		coding(((IntlNode<T>*)root)->right(), code + '1');	//对于右子树编码值为'1'
	}

public:
	HuffForest(HuffNode<T>** treeArray, int count, int max = 100)
	{
		_coding = new std::pair<T, string>[_max];
		_huffForest = new heap<HuffNode<T>*, Comp>(treeArray, count, max);
		buildHuff();
	}

	~HuffForest()
	{
		delete _huffForest;	//释放资源
		delete[]_coding;
	}

	string getCoding(const T& e)
	{
		for (int i = 0; i < _count; ++i)	//顺序查找
		{
			if (_coding[i].first == e)
				return _coding[i].second;
		}
		return "";	//未找到结果 返回空串
	}
};
