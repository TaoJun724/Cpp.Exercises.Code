#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//A说：不是我
//B说：是C
//C说：是D
//D说：C在说谎
//已知3个人说了真话，1个人说的是假话
//现在请根据这些信息，写一个程序判断

int main()
{
    int killer = 0;
    for(killer = 'a';killer <= 'd';killer++)
    {
       if((killer != 'a')+ (killer == 'c')+(killer == 'd') + (killer != 'd')==3)
         printf("%c",killer);
    }
}
