#include <iostream>
#include "../common/book.h"
#include "../Stack/AStack.h"
using namespace std;

long fiba(int n)
{
	Assert((n > 0) && (n < 47), "Input out of range");
	AStack<long> fib(n + 1);
	fib.push(1).push(1);
	int temp1 ,temp2;
	for (int i = 3; i <= n; ++i)
	{
		temp1 = fib.pop();
		temp2 = fib.pop();
		fib.push(temp2).push(temp1).push(temp1 + temp2);
	}
	return fib.topValue();
}

int main()
{
	int n;
	cout << "Enter an integr between 1 and 46: ";
	while (cin >> n)
	{
		cout << fiba(n) << endl << "Enter an integr between 1 and 46: ";
	}
	return 0;
}