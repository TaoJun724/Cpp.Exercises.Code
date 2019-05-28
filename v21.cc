#include<iostream>
using namespace std; 

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三
//B选手说：我第二，E第四
//C选手说：我第一，D第二
//D选手说：C最后，我第三
//E选手说：我第四，A第一


int main()
{
  int a,b,c,d,e;
  for(a = 1;a < 6;a++)
  {
    for(b = 1;b < 6;b++)
    {
      for(c = 1;c < 6;c++)
      {
        for(d =1;d < 6;d++)
        {
          for(e = 1;e < 6;e++)
          {
            if(((b == 2) + (a == 3)==1)&&
               ((b == 2) + (e == 4)==1)&&
               ((c == 1) + (d ==2)==1)&&
               ((c == 5) + (d ==3)==1)&&
               ((e == 4) + (a == 1)==1))
               {
                  if((a * b * c * d * e) == 120)
                  {
                  cout << "a = "<< a << endl;
                  cout << "b = "<< b << endl;
                  cout << "c = "<< c << endl;
                  cout << "d = "<< d << endl;
                  cout << "e = "<< e << endl;
                  }
               }
          }
        }
      }
    }
  }
}
