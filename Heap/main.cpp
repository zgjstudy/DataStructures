#include <iostream>
#include <cstdlib>
#include "HuffmanTree.h"

using namespace std;

template <typename T>
struct Comp
{
	static bool prior(const T& a, const T& b)
	{
		return a < b;
	}
	static void swap(T& a, T& b)
	{
		a ^= b ^= a ^= b;
	}
};

void testHeap()
{
	int a[7] = { 2, 7, 24, 32, 42, 42, 120};
	heap<int, Comp<int> > test2(a, 7, 7);
	cout << "Size of test1: " << test2.size() << endl;
	for (int i = 0, n = test2.size(); i < n; ++i)
	{
		cout << test2.remove() << " ";
	}
	cout << endl << endl;
}

int main()
{
	//testHeap();

	HuffNode<char>* a[] = { new LeafNode<char>('a', 7), new LeafNode<char>('b', 9), 
							new LeafNode<char>('c', 2), new LeafNode<char>('d', 6), 
							new LeafNode<char>('e', 32), new LeafNode<char>('f', 3)};
	HuffForest<char> hf(a, 6, 6);

	cout << "coding of a: " << hf.getCoding('a') << endl;
	cout << "coding of b: " << hf.getCoding('b') << endl;
	cout << "coding of c: " << hf.getCoding('c') << endl;
	cout << "coding of d: " << hf.getCoding('d') << endl;
	cout << "coding of e: " << hf.getCoding('e') << endl;
	cout << "coding of f: " << hf.getCoding('f') << endl << endl;

	string s = "aabddkkkkeeedeeecccdddeee";
	string c;
	for (int i = 0, n = s.length(); i < n; ++i)
	{
		c += hf.getCoding(s[i]);
	}
	cout << "coding of " << s << " : " << c << endl;

	system("pause");

	return 0;
}