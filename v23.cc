#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{ 
  int ch = 0;
  int count = 0;
  while((ch = getchar()) != EOF)
  {
    if(ch == '{')
      count++;
    else if((ch == '}') && (count == 0))
      cout << "不匹配";
    else if((ch == '}') && (count != 0))
      count--;
  }
  if(cout == 0)
    cout << "匹配";
  else 
    cout << "不匹配";
}
