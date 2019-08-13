#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string,string> m;

	//向map中插入元素的方式
	//将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string,string>("peach","桃子"));

	//将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
	m.insert(make_pair("banan","香蕉"));

	//用operator【】向map中插入元素
	m["apple"] = "苹果";

	m.insert(m.find("banan"),make_pair("waterme","水密桃"));
	cout << m.size() << endl;

	//用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for(auto& e : m)
			cout << e.first << "--->" << e.second << endl;
	cout << endl;

	//map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach","桃色"));
	if(ret.second)
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" << ret.first->second << "插入失败" << endl;

}
