#include<iostream>
using namespace std;


//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以换多少汽水
int main()
{
  int money = 0;
  int total = 0;
  int empty = 0;
  cin >> money;
  if(money <= 0)
    cout << "没有钱" << endl;
  total = money;
  empty = money;
  while(empty > 1)
  {
    total += empty/2;
    empty = empty/2 + empty%2;
  }
  cout << "买了"<< total <<"瓶";
}
