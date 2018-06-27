#ifndef PARKINGLOT_H_INCLUDED
#define PARKINGLOT_H_INCLUDED
#define N 20                 //ͣ����������ͣ����
#define MM 10                 //�򳵳�������ͣ����
#define Price 2              //ÿ��λʱ��ͣ������

typedef struct zanlind{
      int number;   //��������
      int ar_time;   //��������ʱ��
}zanInode;

typedef struct
{
    zanInode car[N];
    int top;                //ջָ��*/
} SqStack;                  //����˳��ջ���ͣ���������ͣ����*/

typedef struct
{
    int CarNo[MM];           /*���ƺ�*/
    int front,rear;         /*���׺Ͷ�βָ��*/
} SqQueue;                  /*����ѭ�������ͣ����������򳵳�*/


//����Ϊ˳��ջ�Ļ��������㷨
void InitStack(SqStack *&s)//��ʼ��ջ
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
int StackEmpty(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    return(s->top==-1);
}
int StackFull(SqStack *s)
{
    return(s->top==N-1);
}
int Push(SqStack *&s,int e1,int e2)
{
    if (s->top==N-1)
        return 0;
    s->top++;
    s->car[s->top].number=e1;
    s->car[s->top].ar_time=e2;
    return 1;
}
int Pop(SqStack *&s,int &e1,int &e2)
{
    if (s->top==-1)
        return 0;
    e1=s->car[s->top].number;
    e2=s->car[s->top].ar_time;
    s->top--;
    return 1;
}
void DispStack(SqStack *s)
{
    int i;
    for (i=s->top; i>=0; i--)
        printf("%d ",s->car[s->top].number);
    printf("\n");
}

//����Ϊѭ�����еĻ��������㷨
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
    return(q->front==q->rear);
}
int QueueFull(SqQueue *q)       /*�ж϶���*/
{
    return ((q->rear+1)%MM==q->front);
}
int enQueue(SqQueue *&q,int e)      /*����*/
{
    if ((q->rear+1)%MM==q->front)    /*����*/
        return 0;
    q->rear=(q->rear+1)%MM;
    q->CarNo[q->rear]=e;
    return 1;
}
int deQueue(SqQueue *&q,int &e)     /*����*/
{
    if (q->front==q->rear)          /*�ӿյ����*/
        return 0;
    q->front=(q->front+1)%MM;
    e=q->CarNo[q->front];
    return 1;
}
void DispQueue(SqQueue *q)      /*�������Ԫ��*/
{
    int i;
    i=(q->front+1)%MM;
    printf("%d ",q->CarNo[i]);
    while ((q->rear-i+MM)%MM>0)
    {
        i=(i+1)%MM;
        printf("%d ",q->CarNo[i]);
    }
    printf("\n");
}


void showParkingMenu(){
    printf("\n       ***ͣ�����������***      \n");
    printf("==================================\n\n");
    printf("A--������ͣ����    D--������ͣ����\n\n");
    printf("          E--�˳�����            \n\n");
    printf("==================================\n");
    printf("��ѡ��<A,D,E>(�����ִ�Сд)��");
}

/*int changeNum(){
    char temp;

    scanf("%c",&temp);
    if(temp>='a'&&temp<='z'){
        temp-=32;
    }
    if(temp=='A'||temp=='a'){
       return 1;
    }
    else if(temp=='D'||temp=='d'){
       return 2;
    }
    else if(temp=='E'||temp=='e'){
       return 0;
    }

    return -1;
}*/

void parkinglotSystem(){
    char temp;
    int comm;
    int no,e1,time,e2;
    int i,j,t;
    SqStack *St,*St1;  //St��ͣ������St1�����г��뿪ʱ����¼Ϊ�ó��ƿ�λ�õĳ���
    SqQueue *Qu;   //Qu�Ǻ򳵳�
    InitStack(St);
    InitStack(St1);
    InitQueue(Qu);

    while(1){
        showParkingMenu();
        fflush(stdin);
        scanf("%c",&temp);
        if(temp>='a'&&temp<='z'){
            temp-=32;
        }

        switch(temp){
        case 'A':
            fflush(stdin);
            printf("�����복�ƺţ�");
            scanf("%d",&no);
            fflush(stdin);
            printf("�����복������ͣ������ʱ�䣨��������");
            scanf("%d",&time);
            if (!StackFull(St))         /*ͣ��������*/
            {
                Push(St,no,time);
                printf("��ϲ��ͣ���ɹ���>>���ĳ���ͣ����λ��Ϊ:%d\n",St->top+1);
            }
            else                        /*ͣ������*/
            {
                if (!QueueFull(Qu))     /*�򳵳�����*/
                {
                    enQueue(Qu,no);
                    printf("��Ǹͣ������������ͣ�ں򳵳���>>���ĳ��ں򳵳�λ��Ϊ:%d\n",Qu->rear);
                }
                else
                    printf("��Ǹͣ������򳵳��������޷�ͣ����򳵣�\n");
            }
            break;
        case 'D':
            printf("�����복�ƺţ�");
            scanf("%d",&no);
            fflush(stdin);
            printf("�����복���뿪ͣ������ʱ�䣨��������");
            scanf("%d",&time);
            for (i=0; i<=St->top && St->car[i].number!=no; i++);  //��ջ����
            if (i>St->top)
                printf("δ�ҵ��ó��ƺŵ�����\n");
            else
            {
                t = St->top - i;  //��Ҫ��ջ�ĳ�����Ŀ
                for (j=0; j<t; j++)  //¥���۽���ԭ����д��
                {
                    Pop(St,e1,e2);
                    Push(St1,e1,e2);        /*��������ʱջSt1��*/
                }
                Pop(St,e1,e2);              /*�������뿪*/
                printf("  >>%d����ͣ������:%d\n",no,(time-e2)*Price);
                while (!StackEmpty(St1))    /*����ʱջSt1���»ص�St��*/
                {
                    Pop(St1,e1,e2);
                    Push(St,e1,e2);
                }
                if (!QueueEmpty(Qu))        /*�Ӳ���ʱ,����ͷ��ջSt*/
                {
                    deQueue(Qu,e1);
                    Push(St,e1,time);       /*�Ե�ǰʱ�俪ʼ�Ʒ�*/
                }
            }
            break;
        case 'E':
            exit(0);
            break;
        default:
			printf("�˵��������������������!\n");
			break;
        }
    }
}

#endif // PARKINGLOT_H_INCLUDED
