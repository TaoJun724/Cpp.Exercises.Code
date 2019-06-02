//打印101-200的整数
#include<iostream>
#include<math.h>
using namespace std;

class Solution
{
 public:
   //素数不会被2到本身开方之间的数整除的数
   void PrintDigal(int count)
   {
      for(int i = 100; i <= 200; i++)
      {
        int j = 0;
        for(j = 2; j < sqrt(i) ; j++)
        {
          if(i%j == 0)
            break;
        }
        if(j > sqrt(i))
        {
          cout << i << endl;
          count++;
        }
      }
      cout << count << endl;
   }
};


int main()
{
  Solution s;
  s.PrintDigal(0);
}
