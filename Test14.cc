#include<iostream>
using namespace std;

typedef void (*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

int main()
{
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}
