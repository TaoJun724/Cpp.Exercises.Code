#include<iostream>
using namespace std;

//输出一个整数的每一位

void Print(int num)
{
  if(num != 0)
  {
    if(num < 0)
    {
      num = -num;
    }
    cout << num%10;
    Print(num/10);
  }
}

//int main()
//{
//   int num = 1234;
//   Print(num);
//}
//
//

//编程实现：两个int(32位)整数m与n的二进制表达中，有多少个位（bit）不同？
int main()
{
  int n = 1999;
  int m = 2299;
  int tmp = n^m;
  int count = 0;
  while(tmp)
  {
    tmp = tmp&(tmp -1);
    count++;
  }
  cout<< count;
}
