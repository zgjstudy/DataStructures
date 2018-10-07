#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char p[8];
	char* cp = new char[8];

	p[7] = 0;
	cp[7] = 0;
	
	cout << p << endl << cp << endl;

	system("pause");

	return 0;
}