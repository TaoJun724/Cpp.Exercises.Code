#include<iostream>
using namespace std;

//杨氏矩阵:数组的每行从左到右是递增的，每列从上到下是递增的。 
//1 2 3 
//2 3 4 
//3 4 5

class Solution 
{
  public:
   void Find(int arr[3][3],int * px,int * py,int key)
   {
      int x = 0;
      int y = *py -1;
      while((x < *px)&&(y > 0))
      {
        if(arr[x][y] == key)
        {
          *px = x;
          *py = y;
          return ;
        }
        else if(arr[x][y] > key)
        {
          y--;
        }
        else 
          x++;
      }
      *px = -1;
      *py = -1;
   }
};

int main()
{
  int arr[3][3] = {1,2,3,4,5,6,7,8,9};
  int x = 3;
  int y = 3;
  Solution s;
  s.Find(arr,&x,&y,8);
  if((x!=-1)&&(y!=-1))
  {
    cout <<"找到了"<<endl<<"x = "<< x << "y = "<<y;
  }
  else{
    cout << "没有找到"<< endl;
  }
}
