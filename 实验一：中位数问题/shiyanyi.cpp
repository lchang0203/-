//
// Created by 菜的抠脚畅 on 2017/10/13.
//


int median(int x[],int y[],int n)
{
    print(x,y,n);
    int i;
    int m=n/2;
    if(x[m]==y[m])   //如果x数组与y数组的中位数相等，返回这个中位数
    {
        return x[m];
    }
    if(n==1)   //如果n的值为1，则通过比较返回较小数(递归的出口)
    {
        if(x[n-1]<y[n-1])
        {
            return x[n-1];
        }
        else
        {
            return y[n-1];
        }
    }
    if(n%2==1)//当n为奇数时
    {
        if(x[m]<y[m])
        {
            for(i=0;i<m+1;i++)
            {
                x[i]=x[m+i];
            }
            n=m+1;
            median(x,y,n);
        }
        else
        {
            for(i=0;i<m+1;i++)
            {
                y[i]=y[m+i];
            }
            n=m+1;
            median(x,y,n);
        }
    }
    else//当n为偶数
    {
        if(x[m-1]<y[m-1])
        {
            for(i=0;i<m;i++)
            {
                x[i]=x[m+i];
            }
            n=m;
            median(x,y,n);
        }
        else
        {
            for(i=0;i<m;i++)
            {
                y[i]=y[m+i];
            }
            n=m;
            median(x,y,n);
        }
    }
}
