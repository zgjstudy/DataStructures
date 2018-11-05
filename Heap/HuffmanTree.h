/*
*
*	���ݽṹ�ڶ���ʵ���
*	HuffmanTree��
*	10.26 �Źڽ�
*
*/

#pragma once
#include <cstring>
#include <string>
#include "Heap.h"

#include <iostream>
using namespace std;

using std::string;

//�����
template <typename T> class HuffNode
{
public:
	virtual ~HuffNode() {}
	virtual int weight() = 0;
	virtual bool isLeaf() = 0;
};

//Ҷ�ӽ����
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

//�ڲ������
template <typename T> class IntlNode : public HuffNode<T>
{
private:
	HuffNode<T>* _lc;
	HuffNode<T>* _rc;
	int _weight;

public:
	IntlNode(HuffNode<T>* l, HuffNode<T>* r)	//����ʱ��Ȩ�����
		:_lc(l), _rc(r)
	{
		_weight = _lc->weight() + _rc->weight();
	}

	bool isLeaf() { return false; }
	int weight() { return _weight; }
	HuffNode<T>* left() const { return _lc; }
	HuffNode<T>* right() const { return _rc; }
};

//ɭ����
template <typename T> class HuffForest
{
private:
	struct Comp	//�ȽϷ���
	{
		static bool prior(HuffNode<T>* a, HuffNode<T>* b)	//Ȩ��С������ǰ
		{
			return a->weight() < b->weight();
		}

		static void swap(HuffNode<T>*& a, HuffNode<T>*& b)	//��������
		{
			HuffNode<T>* temp = a;
			a = b;
			b = temp;
		}
	};
	heap<HuffNode<T>*, Comp>* _huffForest;
	std::pair<T, string>* _coding;	//��������
	int _count;
	int _max = 100;
	HuffNode<T>* _root;

	//������������
	void buildHuff()
	{
		HuffNode<T> *temp1, *temp2;
		IntlNode<T> *_root = NULL;
		while (_huffForest->size() > 1)
		{
			temp1 = _huffForest->remove();	//ȡ��������
			temp2 = _huffForest->remove();
			_root = new IntlNode<T>(temp1, temp2);	//�ϲ�
			_huffForest->insert((HuffNode<T>*)_root);	//�������
		}
		_count = 0;
		coding(_root, string(""));	//���������
	}

	//���뺯��
	void coding(HuffNode<T>* root, string code)
	{
		if (root->isLeaf())	//����Ҷ�ڵ���б���
		{
			_coding[_count++] = make_pair(((LeafNode<T>*)root)->getValue(), code);
			return;
		}
		coding(((IntlNode<T>*)root)->left(), code + '0');	//��������������ֵΪ'0'
		coding(((IntlNode<T>*)root)->right(), code + '1');	//��������������ֵΪ'1'
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
		delete _huffForest;	//�ͷ���Դ
		delete[]_coding;
	}

	string getCoding(const T& e)
	{
		for (int i = 0; i < _count; ++i)	//˳�����
		{
			if (_coding[i].first == e)
				return _coding[i].second;
		}
		return "";	//δ�ҵ���� ���ؿմ�
	}
};
