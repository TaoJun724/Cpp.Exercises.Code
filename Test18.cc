#include<iostream>
#include<string>
#include<map>
using namespace std;

void TestMap()
{
	map<string,string> m {
	{"apple","苹果"	},{"peach","桃子"},{"waterme","水蜜桃"}
	};

	for(auto it = m.begin();it != m.end();++it)
		cout << (*it).first << "--->" << it->second << endl;
	cout << endl;
}

int main()
{
	TestMap();
}
