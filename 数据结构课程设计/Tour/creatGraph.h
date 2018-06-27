#ifndef CREATGRAPH_H_INCLUDED
#define CREATGRAPH_H_INCLUDED
#include "head.h"
//typedef char VertexType[20];
int locateVertex(ALGraph *H,VertexType a)
{
    int i=0;
    for(i=0;i<H->vernum;i++)
    {
        if(strcmp(H->vertices[i].name, a) == 0)
            return i;
    }
    return 0;
}

void creatGraph(ALGraph *G){
    int i=0;
    VertexType name1,name2;
    int weight=0;
    ArcNode *p=NULL,*node=NULL;

    printf("请输入顶点数和弧数\n");
    scanf("%d %d",&(G->vernum),&(G->arcnum));

    printf("\n       请输入各顶点名字：   \n\n");//创建链表数组顶点
    for(i=0;i<G->vernum;i++){
        scanf("%s",&(G->vertices[i].name));
        G->vertices[i].first=NULL;
    }

    for(i=0;i<G->arcnum;i++){
        printf("\n输入第%d边的两个顶点以及该边的权值：",i+1);
        scanf("%s %s %d",&name1,&name2,&weight);
        int m=0,n=0;
        m=locateVertex(G,name1);
        n=locateVertex(G,name2);

        p=(ArcNode*)malloc(sizeof(ArcNode));//产生一个新的链表结点
        p->weight=weight;
        p->adjvex=n;
        //strcpy(p->adjvex,name2);
        p->next=G->vertices[m].first;
        G->vertices[m].first=p;
    }
    //printf("%s",G->vertices[0].name);//测试
    //printf("%d",G->vertices[0].first->adjvex);

}

#endif // CREATGRAPH_H_INCLUDED
