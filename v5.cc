//调整数组使奇数位于偶数的前面
#include<iostream>
using namespace std;
class Soultion 
{
  public:
    void Swap_Arr(int* arr,int sz)
    {
      int tmp = 0;
      int left = 0;
      int right = sz - 1;
      while(left < right)
      {
        if((left < right) && (arr[left]%2 == 1))
            left++;
        if((left < right) && (arr[right]%2 == 0))
            right--;
        if(left < right)
        {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        }
      }
    }

    void Print_Arr(int* arr,int sz)
    {
      for(int i = 0;i < sz;i++)
      {
        cout << arr[i] << endl; 
      }
    }
};


int main()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9};
  int sz = sizeof(arr)/sizeof(arr[0]);
  Soultion s1;
  s1.Swap_Arr(arr,sz);
  s1.Print_Arr(arr,sz);
}
