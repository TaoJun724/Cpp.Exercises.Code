#include<iostream>
using namespace std;

class StackOnly
{
	public:
		StackOnly(){

		}

		void Print()
		{
			cout << "StackOnly" << this << endl;
		}

	private:
		void* operator new(size_t size);
		void operator delete(void* p);
}

int main()
{
	StackOnly st1;
	st1.Print();
	return 0;
}
