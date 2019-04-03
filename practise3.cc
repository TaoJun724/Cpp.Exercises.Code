//*将字符串转为整数*//


#include<iostream>
using namespace std;


class Solution{
  public: 
    int StrToNum1(char *str)
    {
      int num =0;
      while(*str != 0)
      {
        num = num * 10 + *str - '0';
        ++str;
      }
      return num;
    }

};
int main()
{
  char* str = "12345";
  Solution solution;
  int num = solution.StrToNum1(str);
  cout << num << endl;
  return 0;
}
