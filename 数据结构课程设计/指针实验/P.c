#include <stdio.h>

int main(void){
    /*int *p = 2;
    printf("%d\n",p);//���2
    printf("%d\n",&p);//�����ַ*/

    int a = 3;
    int *p = a;
    int *q;
    q=&a;
    int b = &a;
    printf("%d\n",p);//���ֵ
    printf("%d\n",q);//�����ַ
    printf("%d\n",*q);//���ֵ

    test(a);
    printf("%d\n",a);

    return 0;
}

void test (int *start){
    *start = 6;
}
