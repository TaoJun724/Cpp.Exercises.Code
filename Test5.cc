#include<iostream>
using namespace std;

class OnlyHeap
{
	public:
		static OnlyHeap* CreateObj()
		{
			return new OnlyHeap;
		}

		void Print()
		{
			cout << "HeapType:" << this << endl;
		}

	private:
		OnlyHeap(OnlyHeap const&);

		OnlyHeap(){

		}
};

int main()
{
	OnlyHeap::CreateObj() -> Print();
	return 0;
}
