#include <cstdlib>
#include "BST.h"

using namespace std;

//遍历函数
void visit(int& a, int& b)
{
	cout << " " << a << " ";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n1, n2;
	BST<int, int> tree1, tree2;
	cout << "请分别输入两棵树的节点数量：";
	cin >> n1 >> n2;
	cout << "请输入t1节点（int）：";
	int t;
	while (n1--)
	{
		cin >> t;
		tree1.insert(t, t);
	}
	cout << "请输入t2节点（int）：";
	while (n2--)
	{
		cin >> t;
		tree2.insert(t, t);
	}
	
	cout << endl<< endl << "tree1:";
	tree1.printSequently();
	cout << endl << "tree2:";
	tree2.printSequently();

	cout << endl << endl <<"tree1前序遍历:";
	tree1.preorder(visit);
	cout << endl << "tree1中序遍历:";
	tree1.inorder(visit);
	cout << endl << "tree1后序遍历:";
	tree1.postorder(visit);

	cout << endl << "tree2前序遍历:";
	tree2.preorder(visit);
	cout << endl << "tree2中序遍历:";
	tree2.inorder(visit);
	cout << endl << "tree2后序遍历:";
	tree2.postorder(visit);

	cout << endl << "tree1叶子结点数量：";
	cout << tree1.leafCount();
	cout << endl << "遍历tree1叶子结点：";
	tree1.leafTraversing(visit);

	cout << endl << "tree2叶子结点数量：";
	cout << tree2.leafCount();
	cout << endl << "遍历tree2叶子结点：";
	tree2.leafTraversing(visit);
	cout << endl;

	cout << endl << "tree1的结构：" << endl;
	tree1.draw();
	cout << endl << endl;

	cout << "tree2的结构：" << endl;
	tree2.draw();

	return 0;
}