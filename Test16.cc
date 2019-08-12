#include<iostream>
using namespace std;

class A
{
	public:
		virtual void f(){

		}
};

class B:public A
{

};

void fun(A* pa)
{
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}
