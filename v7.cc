#include<iostream>
using namespace std;
//abcd 左旋一个变为bcda


void Left_Move(char* arr,int k)
{
  while(k--)
  {
    char tmp;
    char *cur = arr;
    tmp = *cur;
    while(*(cur + 1) != '\0')
    {
        *cur = *(cur + 1);
        cur++;
    }
    *cur  = tmp;
  }
}

int main()
{
   char arr[] = {"abcd"};
   int k = 0;
   cin >> k;
   Left_Move(arr,k);
   cout << arr;
}
