#include<iostream>
#include<map>
#include<string>
using namespace std;

void TestMap()
{
	//key和value的类型都给成字符串
	map<string,string> m1;
	//c++11的类表初始化
	map<string,string> m2{
	  {
			"apple","苹果",
		},
		{
			"banan","香蕉"
		}
	};

	cout << m2["apple"] << endl;
	cout << m2["banan"] << endl;
	map<string,string> m3(m2);
}

int main()
{
	TestMap();
}
