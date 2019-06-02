#include<iostream>
using namespace std;

//将数组交换
//数组一样大


int main()
{
  int arr1[] = {1,2,3,4,5};
  int arr2[] = {6,7,8,9,0};
  int sz = sizeof(arr1)/sizeof(arr1[0]);
  int i = 0;
  for(i = 0;i < sz;i++)
  {
    int tmp = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = tmp;
  }
  for(i = 0;i < sz;i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for(i = 0;i < sz;i++)
  {
    cout << arr2[i] << " ";
  }
}
