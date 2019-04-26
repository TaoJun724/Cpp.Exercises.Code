#include<iostream>
using namespace std;


class Solution
{
  public:
    //返回组成数字之和
    int DigitSum(int x)
    {
      int i;
      if(x == 0)
        return 0;
      else 
      {
         i = x%10;
         x = x/10;
        return i + DigitSum(x);
      }
    }

};

int main()
{
  Solution s;
  int ret = s.DigitSum(1729);
  cout << ret;
}
