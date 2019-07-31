#include<iostream>
#include<string>
using namespace std;


void test1()
{
	string s("hello,world");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//将s中有效字符个数增加到10个，多出位置用"j"进行填充
	s.resize(10,'j');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << "-------" << endl;
	//测试reserve
	string s2("hehe");
	//reserver不会改变string中有效元素个数
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.reserve(100);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.reserve(50);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

int main()
{
	test1();
	return 0;
}
