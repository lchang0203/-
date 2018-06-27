
//
// Created by 菜的抠脚畅 on 2017/10/13.
//





#include<iostream>
#include<fstream>
using namespace std;

void dyna(int n,int **r);
int main()
{
    int n,i,j;
    fstream file1,file2;
    file1.open("input2-2.txt",ios::in);
    file2.open("output2-2.txt",ios::out);
    file1>>n;
    int **r=new int*[n+1];
    for(i=0;i<n+1;i++)
    {
        r[i]=new int[n+1];
    }
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n+1;j++)
        {
            file1>>r[i][j];
        }
    }
    dyna(n,r);
    cout<<r[1][n]<<endl;
    file2<<r[1][n];
    file1.close();
    file2.close();
    return 0;
}
void dyna(int n,int **r)
{
    int i,j,l,k,t;
    for(i=1;i<=n;i++)
    {
        r[i][i]=0;
    }
    for(l=2;l<=n;l++)//l为差值，从2开始
    {
        for(i=1;i<=n-l+1;i++)//i为开始的出租站
        {
            j=i+l-1;
            for(k=i+1;k<j;k++) //遍历
            {
                t=r[i][k]+r[k][j];
                if(t<r[i][j])
                {
                    r[i][j]=t; //选择租金少的的存储
                }
            }
        }
    }
}
