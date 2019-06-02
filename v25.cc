#include<math.h>
#include<iostream>
using namespace std;

//求出范围内的水仙花数，并输出。
int main()
{
  int i = 0;
  for(i = 0;i <= 10000;i++)
  {
    int count = 1;
    int sum = 0;
    int tmp = i;
    //统计位数
    while(tmp / 10)
    {
      count++;
      tmp /= 10;
    }
    tmp = i;
    while(tmp)
    {
      sum = sum +(int)pow(tmp%10,count);
      tmp = tmp /10;
    }
    if(sum == i)
    {
      cout << i<< " ";
    }
  }
}
