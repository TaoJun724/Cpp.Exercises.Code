//1.打印乘法口诀表
#include<stdio.h>
#include<iostream>
using namespace std;

class Solution1
{
public:
  void Print()
  {
    for(int i = 1; i <= 9; i++)
    {
      for(int j = 1;j <= i;j++)
      {
        printf("%d * %d = %d \t",i,j,i*j);
      }
      cout<< endl;
    }
  }
};

//判断1000-2000的润年
class Solution2{
public:
  void Printf()
  {
    for(int i = 1000;i < 2000 ;i++)
    {
      if((i%4 == 0)&&(i%100 != 0)||(i%400 == 0))
      {
        cout << i << endl;
      }
    }
  }
};


int main()
{
  Solution1 s1;
  s1.Print();
  Solution2 s2;
  s2.Printf();
}

