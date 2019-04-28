#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>
//将i am a student ---> student a am i
//思路：首先先将字符串逆转，再逆转每个单词



void reverse(char* left,char* right)
{
   assert(left != NULL);
   assert(right != NULL);
   while(left < right)
   {
     char tmp = *left;
     *left = *right;
     *right = tmp;
     left++;
     right--;
   }
}

void Reverse(char* arr)
{
  char* cur = arr;
  char* left = arr;
  char* right = arr + strlen(arr) - 1;
  assert(arr != NULL);
  reverse(left,right);
  while(*cur)
  {
    char* start = cur;
    while((*cur != '\0')&&(*cur != ' '))
    {
       cur++;
    }
    reverse(start,cur - 1);
    cur++;
  }
}


int main()
{
  char arr[] = "student a am i";
  Reverse(arr);
  cout << arr;
  return 0;
}
