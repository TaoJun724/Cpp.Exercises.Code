#include<iostream>
#include<thread>
using namespace std;


void fun()
{
	cout << "A new thread" << endl;
}

int main()
{
	thread t(fun);
	t.join();
	cout << "Main thread!" << endl;
	return 0;
}
