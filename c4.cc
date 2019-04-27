#include<iostream>
using namespace std;

class Soution{
//求10个数中最大的数
  public:
    void Max()
    {
      int arr[10] = {1,2,3,4,5,6,7,8,9,0};
      int max = arr[0];
      for(int i = 0;i<10;i++)
      {
        if(max < arr[i])
          max = arr[i];
      }
      cout<<max;
    }
    //求最大公约数
    void GongYue()
    {
      int m = 24;
      int n = 12;
      while(m%n)
      {
        int tmp = m%n;
        m = n;
        n = tmp;
      }
      cout << n << endl;
    }

};



int main()
{
  Soution s1;
  s1.Max();
  s1.GongYue();
}
