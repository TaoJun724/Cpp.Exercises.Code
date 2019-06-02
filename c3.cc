//给定两个数 将两个数交换
#include<iostream>
#include<stdio.h>
using namespace std;
class Solution{
  public:
    void Swap1()
    {
      int a1 = 1;
      int b1 = 2;
      int tmp = 0;
      tmp = a1;
      a1 = b1;
      b1 = tmp;
      cout <<"a = "<< a1 << endl;
      cout <<"b = "<< b1 << endl;
    }
    void Swap2()
    {
      int a = 1;
      int b = 2;
      a = a^b;
      b = a^b;
      a = a^b;
      cout <<"a = "<<a << " "<< "b = "<< b;
    }
};

int main()
{
  Solution s1;
  s1.Swap2();
}
