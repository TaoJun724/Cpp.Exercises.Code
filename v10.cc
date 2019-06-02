#include<iostream>
using namespace std;

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次 


int main()
{
  int arr[] = {1,3,8,1,3,8,4,6};
  int sz = sizeof(arr)/sizeof(arr[0]);
  int num = 0;
  int pos = 0;
  int x = 0;
  int y = 0;
  int i = 0;
  for(i = 0;i < sz; i++)
  {
    num ^= arr[i];
  }
  //找num的二进制为1的第一位
  for(i = 0 ; i < 32 ;i++)
  {
    if( ((num >> i) & 1) == 1 )
    {
      pos = i;
      break;
    }
  }

  //分开相&
  for(i = 0;i < sz;i++)
  {
    if(((arr[i]>>pos) & 1) ==1)
      x ^= arr[i];
    else 
      y ^= arr[i];
  }
  cout << x;
  cout << y;
}
