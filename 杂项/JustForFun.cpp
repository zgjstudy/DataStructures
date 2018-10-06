#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char p[8];
	
	for (int i = 0; i < 8; ++i)
	{
		cout << (int*)(p + i) << endl;
	}

	system("pause");

	return 0;
}