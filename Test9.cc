#include<iostream>
#include<string>
using namespace std;

void Test()
{
	string num("1234");
	/*迭代器，底层类似指针用来遍历string,访问容器
	 * 迭代器是string类中的内部类型，是typedef出来的
	 * begin指向第一个位置，end指向最后一个数组的下一个的迭代器
	 * 迭代器给出一个统一的方式访问容器，不需要关心容器底层的细节*/
	 string::iterator it = num.begin();
	 int res = 0;          
	 while(it != num.end())
	 {
		 res *= 10;
		 res += (*it) - '0';
		 ++it;
	 }
	 cout << res << endl;
	 //vector为类名，vector<int>为类型
	 vector<int> v;
	 v.push_back(1);
	 v.push_back(2);
	 vector<int>::iterator vit  = v.begin();
	 while(vit != v.end())
	 {
		 cout << *vit << " ";
		 ++vit;
	 }
	 cout << endl;
}


void test1()
{
	//反向迭代器
	string num("1234");
	string::reverse_iterator rit = num.rbegin();
	while(rit != num.rend())
	{
		cout << *rit << " ";
		(*rit) += 1;
		++rit;
	}
	cout << endl;
}

int StrToNum(const string& str)
{
	//const修饰的迭代器只能读不能写
	int num = 0;
	string::const_iterator it = str.begin();
	while(it != str.end())
	{
		num *= 10;
		num += (*it) - '0';
		++it;
	}
	cout << num << endl;
	return num;
}

void test2()
{
	string s1("hello");
	for(int i = 0;i < s1.size();i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
}

void test3()
{
	string str("2345");
	int res = 0;
	for(auto e : str)
	{
		res *= 10;
		res += (e - '0');
	}
	cout << res << endl;
}

int main()
{
	test();
	test1();
	test2();
}
