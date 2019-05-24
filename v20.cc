#include<iostream>
using namespace std;
 
//1/1-1/2+1/3-1/4++++ 1/99-1/100

int main()
{
   int i = 0;
   int f = 1;
   double sum = 0.0;
   for(i = 1;i < 100;i++)
   {
     sum = sum + f* 1.0/i;
     f = -f;
   }
   cout << sum;
}
