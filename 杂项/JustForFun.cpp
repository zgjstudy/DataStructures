#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char p[56];
	char* cp = new char[56];

	p[55] = 0;
	cp[55] = 0;
	
	cout << p << endl << cp << endl;
	cout << "����������������" << endl;
	system("pause");

	return 0;
}