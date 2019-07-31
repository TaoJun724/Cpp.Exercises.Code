#include<iostream>
using namespace std;


class Count
{
	public:
		Count()
		{
			num++;
		}

		Count(Count& c)
		{
			num++;
		}
		
		static int getNum()
		{
			return num;
		}
		private:
		static int num;
};

int Count::num = 0;

int main()
{
	cout << Count::getNum() << endl;
	Count c;
	cout << Count::getNum() << endl;
	return 0;
}
