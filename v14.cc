#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int main()
{
  int ch = 0;
  while((ch = getchar()) != EOF)
  {
    if(ch >= 'a' && ch <= 'z')
      putchar(ch - ('a' - 'A'));
    else if(ch >= 'A' && ch <= 'Z')
      putchar(ch + ('a' - 'A'));
    else if(ch <= '9' && ch >= '0')
      ;
    else 
      putchar(ch);
  }
}
