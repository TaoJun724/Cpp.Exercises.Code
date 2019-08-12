#include<iostream>
using namespace std;

void Test()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;

	cout << a << endl;
}
