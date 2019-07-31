#include<iostream>
#include<string>
using namespace std;


int main()
{
	string s1;//构造空的string类对象s1
	string s2("hello,world");//使用C字符串构造
	string s3(10,'a');//10个a构造对象
	string s4(s2);
	string s5(s2,9);//从s2对象下标为9的位置开始构造

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;
	cout << s4.c_str() << endl;
	cout << s5.c_str() << endl;
	return 0;
}
