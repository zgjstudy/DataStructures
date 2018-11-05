/*
*
*	数据结构第二次实验课
*	BST类
*	10.26 张冠杰
*
*/

#pragma once
#include <iostream>
#include <iomanip>
#include "BSTNode.h"
#include "Dictionary.h"
using std::cout;
using std::endl;

template <typename Key, typename T> class BST : public Dictionary<Key, T>
{
private:
	typedef BSTNode<Key, T>* NodePtr;
	NodePtr _root;
	int _nodeCount;

	T removeAny() { return T(); }	//隐藏不需要的接口

	//用于计数的辅助函数
	int counthelp(NodePtr root)
	{
		if (root == nullptr)
			return 0;
		return 1 + counthelp(root->left()) + counthelp(root->right());
	}

	//画树辅助函数
	void drawhelp(NodePtr root, int depth, int* flag)
	{
		if (root == nullptr)	//空子树直接返回
			return;

		//按照中序遍历的反方向进行遍历
		//先遍历到的节点会画在上面

		flag[depth] = 1;	//对于右子树将flag设为1
		drawhelp(root->right(), depth + 1, flag);	//遍历右子树
		
		for (int i = 0; i < depth; ++i)	//画空格和树枝
		{
			cout << "             ";	//按照节点的深度缩进
			if (i < depth - 1 && flag[i] != flag[i + 1])	//如果该节点的深度为i的祖先是深度为i-1祖先的左子树且深度为i+1的祖先是深度为i祖先的右子树或者反过来
			{
				cout << "|";	//则画树枝
			}
			else
				cout << " ";	//否则空格
		}

		cout << "|---|" << std::setw(4) << root->key() << "|";	//绘制节点
		if (!(root->isLeaf()))	//如果不是叶子节点就画树枝
			cout << "---|";
		cout << endl;

		flag[depth] = -1;	//对于左子树将flag设为1
		drawhelp(root->left(), depth + 1, flag);	//遍历左子树
	}

protected:
	//clear helper
	void clearhelp(NodePtr root)
	{
		if (root == nullptr) return;
		clearhelp(root->left());
		clearhelp(root->right());
		delete root;
	}

	//find helper, return value
	T findhelp(NodePtr root, const Key& k) const
	{
		if (root == nullptr)
			return NULL;
		if (k < root->key())
			return findhelp(root->left(), k);
		else if (k > root->key())
			return findhelp(root->right(), k);
		else return root->element();
	}

	//获取树中最小元素节点
	NodePtr getmin(NodePtr root)
	{
		if (root->left() == nullptr)
			return root;
		else
			return getmin(root->left());
	}

	//获取最小节点并在原树中移除该节点
	NodePtr deletemin(NodePtr root)
	{
		if (root->left() == nullptr)
			return root->right();
		else
		{
			root->setLeft(deletemin(root->left()));
			return root;
		}
	}

	//insert helper
	NodePtr inserthelp(NodePtr root, const Key& k, const T& e)
	{
		if (root == NULL)
			return new BSTNode<Key, T>(k, e, nullptr, nullptr);
		if (k < root->key())
			root->setLeft(inserthelp(root->left(), k, e));
		else
			root->setRight(inserthelp(root->right(), k, e));
		return root;
	}

	//remove helper
	NodePtr removehelp(NodePtr root, const Key& k)
	{
		if (root == nullptr)	//未查询到结果
			return nullptr;
		else if (k < root->key())	//如果小于当前key则在左子树中搜索
			root->setLeft(removehelp(root->left(), k));
		else if (k > root->key())	//如果大于当前key则在右子树中搜索
			root->setRight(removehelp(root->right(), k));
		else	//命中
		{
			NodePtr temp = root;
			if (root->left() == nullptr)	//如果没有左子树
			{
				root = root->right();
				delete temp;
			}
			else if (root->right() == nullptr)	//如果没有右子树
			{
				root = root->left();
				delete temp;
			}
			else
			{
				NodePtr temp = getmin(root->right());	//将最小节点的存到root
				root->setElement(temp->element());
				root->setKey(temp->key());
				root->setRight(deletemin(root->right()));	//删除最小的节点
				delete temp;
			}
		}
		return root;
	}

	//顺序输出辅助函数
	void printhelp(BSTNode<Key, T>* root) const
	{
		if (root == NULL)		
		{
			std::cout << " / ";	//空节点输出/
			return;
		}
		std::cout << " " << root->key() << " ";	//输出当前key
		printhelp(root->left());	//输出左子树
		printhelp(root->right());	//输出右子树
	}

	//先序遍历辅助函数
	void preorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		visit(root->key(), root->element());				//根左右
		preorderhelp(root->left(), visit);
		preorderhelp(root->right(), visit);
	}

	//中序遍历辅助函数
	void inorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		inorderhelp(root->left(), visit);			//左根右
		visit(root->key(), root->element());
		inorderhelp(root->right(), visit);
	}

	//后序遍历辅助函数
	void postorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		postorderhelp(root->left(), visit);	//左右根
		postorderhelp(root->right(), visit);
		visit(root->key(), root->element());
	}

	//数叶子辅助函数
	int leafCounthelp(BSTNode<Key, T>* root) const
	{
		if (root == nullptr)	//空树返回0
			return 0;
		if (root->isLeaf())		//叶子结点返回1
			return 1;
		else
			return leafCounthelp(root->left()) + leafCounthelp(root->right());	//没啥好注释的
	}

	//遍历叶子结点辅助函数
	void leafTraversinghelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr)	//空树返回
			return;
		if (root->isLeaf())		//叶子结点执行visit
			visit(root->key(), root->element());
		leafTraversinghelp(root->left(), visit);	//遍历左子树
		leafTraversinghelp(root->right(), visit);	//遍历右子树
	}

public:
	BST() : _root(nullptr), _nodeCount(0) {};
	~BST() { clear(); }

	//清空
	void clear()
		{
			clearhelp(_root);
			_root = nullptr;
			_nodeCount = 0;
		}

	//插入
	virtual void insert(const Key& k, const T& e)
		{
			_root = inserthelp(_root, k, e);
			_nodeCount++;
		}

	//删除
	virtual T remove(const Key& k)
		{
			T temp = findhelp(_root, k);
			if (temp != NULL)
			{
				_root = removehelp(_root, k);
				_nodeCount--;
			}
			return temp;
		}

	//查询
	virtual T find(const Key& k) const
		{
			return findhelp(_root, k);
		}

	//返回节点数
	int size() const { return _nodeCount; }

	//顺序打印
	void printSequently() const
		{
			printhelp(_root);
		}

	//后序遍历
	void postorder(void(*visit)(Key&, T&))
		{
			postorderhelp(_root, visit);
		}

	//中序遍历
	void inorder(void(*visit)(Key&, T&))
		{
			inorderhelp(_root, visit);
		}

	//前序遍历
	void preorder(void(*visit)(Key&, T&))
		{
			preorderhelp(_root, visit);
		}

	//计算叶子节点的数量
	int leafCount() const
		{
			return leafCounthelp(_root);
		}

	//遍历叶子节点
	void leafTraversing(void(*visit)(Key&, T&))
		{
			leafTraversinghelp(_root, visit);
		}

	//画树
	void draw()
	{
		int* flag = new int[_nodeCount];	//用于确认是否画竖线
		drawhelp(_root, 0, flag);			//画树
		delete[]flag;
	}
};
