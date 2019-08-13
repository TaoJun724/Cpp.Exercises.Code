#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	//构造一个空的map，此时m中一个元素都没有
	map<string,string> m;
	/*operator[]的原理是用<key,T()>构造一个键值对，然后调用insert()函数将该键对插入到map中，如果key已经存在，插入失败，insert函数返回该key所在的位置的迭代器，如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器operator[]函数最后将insert返回值对中的value返回*/

	//将<"apple","">插入map中，插入失败，将<"apple","苹果">中的"苹果"返回
	cout << m["apple"] << endl;
	cout << m.size() << endl;

	//"banan"不在map中，该函数抛异常
	m.at("banan");
}
