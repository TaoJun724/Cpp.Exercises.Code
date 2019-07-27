#include<iostream>
using namespace std;

namespace A1
{
	int a = 20;

	int Add(int x1,int x2)
	{
		return x1 + x2;
	}
  
	namespace A2
	{
		int b = 10;

		int Sub(int x1,int x2)
		{
			return x1 - x2;
		}
	}
}

using A1::a;

void Test1()
{
	cout << a << endl;
	cout << A1::A2::b << endl;
	int ret = A1::Add(1,2);
	cout << ret << endl;
  return 0;
}

void Test2()
{
	int i;
	char c;
	double d;
	cin >> i;
	cin >> c >> d;
	cout << d << " " << c << endl;
	cout << i << endl;
	return 0;
}

int main()
{
 Test1();
 Test2();
}
