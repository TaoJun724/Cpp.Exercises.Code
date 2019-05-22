#include<iostream>
using namespace std; 

//1-100所有的9的次数

int main()
{
  int i = 0;
  int count = 0;
  for(i = 0;i < 100;i++)
  {
    if(i % 10 == 9)
      count++;
    if(i / 10 == 9)
      count++;
  }
  cout << count << endl;
}
