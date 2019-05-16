#include<iostream>
using namespace std;



int main()
{
   int num = 15;
   int i = 0;
   int count = 0;
   for(i = 0;i < 32; i++)
   {
     if((num >> 1) & 1 == 1) 
     {
       count++;
     }
   }
   cout << count;
}
