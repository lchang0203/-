#ifndef CREATGRAPH_H_INCLUDED
#define CREATGRAPH_H_INCLUDED
#include "DataStructure.h"


void createGraph(ALGraph &G)
{
    int i=0;
    VertexType name1,name2;
    int weight=0;
    ArcNode *p=NULL,*node=NULL;

    printf("请输入顶点数和弧数：\n");
    scanf("%d %d",&(G.vexnum),&(G.arcnum));

    printf("请输入各顶点名字：\n");//创建链表数组顶点
    for(i=0; i<G.vexnum; i++)
    {
        scanf("%s",&(G.vertices[i].name));
        G.vertices[i].first=NULL;
        strcpy(G.vertices[i].info.introduction,"无景区介绍");
        G.vertices[i].info.popularity=-1;
        G.vertices[i].info.roadnum=-1;
    }

    for(i=0; i<G.arcnum; i++)
    {
        printf("\n输入第%d边的两个顶点以及该边的权值：",i+1);
        scanf("%s %s %d",&name1,&name2,&weight);
        int m=0,n=0;
        m=locateVex(G,name1);
        n=locateVex(G,name2);

        p=(ArcNode*)malloc(sizeof(ArcNode));//产生一个新的链表结点
        p->weight=weight;
        p->adjvex=n;
        //strcpy(p->adjvex,name2);
        p->next=G.vertices[m].first;
        G.vertices[m].first=p;
        //free(p);
        //p= NULL;
    }
    //printf("create测试\n");
    //for(i=0; i<G.vexnum; i++)
    //{
    //    printf("%s ",G.vertices[i].name);
    //}
    //printf("%s",G->vertices[0].name);//测试
    printf("\n景区景点的邻接链表存储结构创建成功！\n");
}

    //北门 狮子山 仙云石 一线天 飞流瀑 仙武湖 九曲桥 观云台
    //北门 狮子山 8
    //北门 仙云石 9
    //狮子山 飞流瀑 6
    //狮子山 一线天 7
    //一线天 观云台 11
    //飞流瀑 观云台 3
    //仙云石 九曲桥 5
    //仙云石 仙武湖 4
    //仙武湖 九曲桥 7

void addInformation (ALGraph &G)
{
    int i;

    for(i=0; i<G.vexnum; i++) //北门 狮子山 仙云石 一线天 飞流瀑 仙武湖 九曲桥 观云台
    {
        if(strcmp("北门",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=1;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"北门是景区的入口。");
        }
        else if(strcmp("狮子山",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=8;
            G.vertices[i].info.roadnum=3;
            strcpy(G.vertices[i].info.introduction,"狮子山早在1.4亿年前已形成，现在狮子山的位置，从前是一片大熔岩“狮子”头面向九龙西边，狮身连尾巴完整地伏在山上。");
        }
        else if(strcmp("仙云石",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=2;
            G.vertices[i].info.roadnum=3;
            strcpy(G.vertices[i].info.introduction,"仙云石在观沟西南，孤石高耸，造形优美，传说凤凰曾落于此处。");
        }
        else if(strcmp("一线天",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=7;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"一线天在山崖之间，形成狭长的陡峭深谷，人在谷底仰望高空，唯见一线蓝天。人立其上，险象环生，深谷生云，峭石凌风，云浮风起，仿佛山在摇晃。");
        }
        else if(strcmp("飞流瀑",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=6;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"飞流瀑是对“飞流直下三千尺,疑是银河落九天”最好的解释。");
        }
        else if(strcmp("仙武湖",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=4;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"仙武湖方圆近五里，分作五洲（环洲、樱洲、菱洲、梁洲、翠洲），洲洲堤桥相通，浑然一体，处处有山有水。");
        }
        else if(strcmp("九曲桥",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=3;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"孤山北面有一九曲桥，直通西湖平湖中的点翠洲，洲上有孤屿亭，明代建为点翠亭。亭西有枇杷洲，另有二桥可通孤山与芳华洲。");
        }
        else if(strcmp("观云台",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=5;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"云台观是中国道教二十四治之一，是东汉末年张道陵（即）张天师学道、炼丹、施法、升真之所，距今已有1860多年的历史。");
        }
    }

    //for(i=0; i<G.vexnum; i++){
    //    printf("\n测试%d\n",G.vertices[i].info.popularity);
    //}
    //printf("测试%s\n",G.vertices[1].info.introduction);
    //printf("测试%d\n",G.vertices[2].info.popularity);
}

#endif // CREATGRAPH_H_INCLUDED
