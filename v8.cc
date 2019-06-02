#include<iostream>
#include<string.h>
using namespace std;

int IsLeft(char arr[],char* p)
{
  if(strlen(arr) != strlen(p))
    return 0;
  strncat(arr,arr,strlen(arr));
  if(strstr(arr,p) != NULL)
    return 1;
  else 
    return 0;
}

int main()
{
  char arr[] = "abcd";
  char *p = "bdac";
  int  ret = IsLeft(arr,p);
  if(ret == 1)
    cout << "是旋转得来的"<<endl;
  else 
    cout << "不是"<<endl;
}
