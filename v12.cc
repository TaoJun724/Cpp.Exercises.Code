#include<iostream>
#include<string.h>
using namespace std;



void Reverse_String(char* str)
{
   char tmp = 0;
   int len = strlen(str);
   if(len > 0)
   {
     tmp = str[0];
     str[0] = str[len -1];
     str[len -1] = '\0';
     Reverse_String(str + 1);
     str[len -1] = tmp;
   }
}

int main()
{
  char arr[] =  "abcd";
  Reverse_String(arr);
  cout << arr; 
}
