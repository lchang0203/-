#ifndef PARKINGLOT_H_INCLUDED
#define PARKINGLOT_H_INCLUDED
#define N 20                 //停车场内最多的停车数
#define MM 10                 //候车场内最多的停车数
#define Price 2              //每单位时间停车费用

typedef struct zanlind{
      int number;   //汽车车号
      int ar_time;   //汽车到达时间
}zanInode;

typedef struct
{
    zanInode car[N];
    int top;                //栈指针*/
} SqStack;                  //定义顺序栈类型，用于描述停车场*/

typedef struct
{
    int CarNo[MM];           /*车牌号*/
    int front,rear;         /*队首和队尾指针*/
} SqQueue;                  /*定义循环队类型，用于描述候车场*/


//以下为顺序栈的基本运算算法
void InitStack(SqStack *&s)//初始化栈
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}
int StackEmpty(SqStack *s)//判断栈是否为空
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

//以下为循环队列的基本运算算法
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
int QueueEmpty(SqQueue *q)
{
    return(q->front==q->rear);
}
int QueueFull(SqQueue *q)       /*判断队满*/
{
    return ((q->rear+1)%MM==q->front);
}
int enQueue(SqQueue *&q,int e)      /*进队*/
{
    if ((q->rear+1)%MM==q->front)    /*队满*/
        return 0;
    q->rear=(q->rear+1)%MM;
    q->CarNo[q->rear]=e;
    return 1;
}
int deQueue(SqQueue *&q,int &e)     /*出队*/
{
    if (q->front==q->rear)          /*队空的情况*/
        return 0;
    q->front=(q->front+1)%MM;
    e=q->CarNo[q->front];
    return 1;
}
void DispQueue(SqQueue *q)      /*输出队中元素*/
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
    printf("\n       ***停车场管理程序***      \n");
    printf("==================================\n\n");
    printf("A--汽车进停车场    D--汽车出停车场\n\n");
    printf("          E--退出程序            \n\n");
    printf("==================================\n");
    printf("请选择<A,D,E>(不区分大小写)：");
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
    SqStack *St,*St1;  //St是停车场，St1是在有车离开时，记录为该车移开位置的车辆
    SqQueue *Qu;   //Qu是候车场
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
            printf("请输入车牌号：");
            scanf("%d",&no);
            fflush(stdin);
            printf("请输入车辆进入停车场的时间（整数）：");
            scanf("%d",&time);
            if (!StackFull(St))         /*停车场不满*/
            {
                Push(St,no,time);
                printf("恭喜您停车成功！>>您的车在停车场位置为:%d\n",St->top+1);
            }
            else                        /*停车场满*/
            {
                if (!QueueFull(Qu))     /*候车场不满*/
                {
                    enQueue(Qu,no);
                    printf("抱歉停车场已满，已停在候车场！>>您的车在候车场位置为:%d\n",Qu->rear);
                }
                else
                    printf("抱歉停车场与候车场均满，无法停车或候车！\n");
            }
            break;
        case 'D':
            printf("请输入车牌号：");
            scanf("%d",&no);
            fflush(stdin);
            printf("请输入车辆离开停车场的时间（整数）：");
            scanf("%d",&time);
            for (i=0; i<=St->top && St->car[i].number!=no; i++);  //在栈中找
            if (i>St->top)
                printf("未找到该车牌号的汽车\n");
            else
            {
                t = St->top - i;  //需要出栈的车辆数目
                for (j=0; j<t; j++)  //楼评论讲的原错误写法
                {
                    Pop(St,e1,e2);
                    Push(St1,e1,e2);        /*倒车到临时栈St1中*/
                }
                Pop(St,e1,e2);              /*该汽车离开*/
                printf("  >>%d汽车停车费用:%d\n",no,(time-e2)*Price);
                while (!StackEmpty(St1))    /*将临时栈St1重新回到St中*/
                {
                    Pop(St1,e1,e2);
                    Push(St,e1,e2);
                }
                if (!QueueEmpty(Qu))        /*队不空时,将队头进栈St*/
                {
                    deQueue(Qu,e1);
                    Push(St,e1,time);       /*以当前时间开始计费*/
                }
            }
            break;
        case 'E':
            exit(0);
            break;
        default:
			printf("菜单项输入错误，请重新输入!\n");
			break;
        }
    }
}

#endif // PARKINGLOT_H_INCLUDED
