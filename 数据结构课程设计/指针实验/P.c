#include <stdio.h>

int main(void){
    /*int *p = 2;
    printf("%d\n",p);//输出2
    printf("%d\n",&p);//输出地址*/

    int a = 3;
    int *p = a;
    int *q;
    q=&a;
    int b = &a;
    printf("%d\n",p);//输出值
    printf("%d\n",q);//输出地址
    printf("%d\n",*q);//输出值

    test(a);
    printf("%d\n",a);

    return 0;
}

void test (int *start){
    *start = 6;
}
