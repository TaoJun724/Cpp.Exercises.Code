/*
2019.6.24
n皇后问题
*/


#include<iostream>  
using namespace std;  
   
#define MAX 1024  
   
int N;  
int column[MAX];//每行对应的列值  
   
int sum=0;  
bool Place(int row,int col)//判断是否该行可以放置皇后  
{  
    int i=1;  
    for(i;i<row;i++)  
    {  
        if((column[i]-col)==(i-row)||(column[i]-col)==(row-i)||column[i]==col)  
            return false;  
    }  
    return true;  
}  
   
void backTrace(int k)//回溯函数  
{  
    int i;  
    if(k>N)  
    {  
        cout<<"路径"<<++sum<<"序列为: ";  
        for(i=1;i<=N;i++)  
            cout<<column[i]<<" ";  
        cout<<endl;  
    }  
    else 
    {  
        for(i=1;i<=N;i++)  
        {  
            if(Place(k,i))  
            {  
                column[k]=i;  
                backTrace(k+1);  
            }  
        }  
    }  
}  
int main()  
{  
    cout<<"输入皇后数:";  
    cin>>N;  
    backTrace(1);  
}
