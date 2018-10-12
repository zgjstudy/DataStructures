#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s)
{
	if (!val)	// Assertion failed -- close the program
	{
		cerr << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}