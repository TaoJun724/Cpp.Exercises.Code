#include<iostream>
using namespace std;

struct Goods
{
	string _name;
	double _price;
};

struct Compare
{
	bool operator()(const Goods& g1,const Good& gr)
	{
		return g1._price <= gr._price;
	}
};

int main()
{
	Goods gds[] = {
	 { "苹果",2.1},{"香蕉",3},{
		 "菠萝",1.4
	 }
	};

	sort(gds,gds+sizeof(gds)/sizeof(gds[0]),Compare());
	return 0;
}
