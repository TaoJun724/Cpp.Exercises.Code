#include<iostream>
using namespace std;


//获取一个数二进制序列中所有偶数位和基数为，分别输出二进制序列

int main()
{
  int num = 43690;
  int i = 0;
  for(i = 31; i >= 1;i -= 2)
  {
    cout << ((num >> i)& 1);
  }
  for(i = 30;i >= 0;i -= 2)
  {
    cout << ((num >> i)& 1);
  }
}
