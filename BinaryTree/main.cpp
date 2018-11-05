#include <cstdlib>
#include "BST.h"

using namespace std;

//��������
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
	cout << "��ֱ������������Ľڵ�������";
	cin >> n1 >> n2;
	cout << "������t1�ڵ㣨int����";
	int t;
	while (n1--)
	{
		cin >> t;
		tree1.insert(t, t);
	}
	cout << "������t2�ڵ㣨int����";
	while (n2--)
	{
		cin >> t;
		tree2.insert(t, t);
	}
	
	cout << endl<< endl << "tree1:";
	tree1.printSequently();
	cout << endl << "tree2:";
	tree2.printSequently();

	cout << endl << endl <<"tree1ǰ�����:";
	tree1.preorder(visit);
	cout << endl << "tree1�������:";
	tree1.inorder(visit);
	cout << endl << "tree1�������:";
	tree1.postorder(visit);

	cout << endl << "tree2ǰ�����:";
	tree2.preorder(visit);
	cout << endl << "tree2�������:";
	tree2.inorder(visit);
	cout << endl << "tree2�������:";
	tree2.postorder(visit);

	cout << endl << "tree1Ҷ�ӽ��������";
	cout << tree1.leafCount();
	cout << endl << "����tree1Ҷ�ӽ�㣺";
	tree1.leafTraversing(visit);

	cout << endl << "tree2Ҷ�ӽ��������";
	cout << tree2.leafCount();
	cout << endl << "����tree2Ҷ�ӽ�㣺";
	tree2.leafTraversing(visit);
	cout << endl;

	cout << endl << "tree1�Ľṹ��" << endl;
	tree1.draw();
	cout << endl << endl;

	cout << "tree2�Ľṹ��" << endl;
	tree2.draw();

	return 0;
}