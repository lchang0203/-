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

    printf("�����붥�����ͻ���\n");
    scanf("%d %d",&(G->vernum),&(G->arcnum));

    printf("\n       ��������������֣�   \n\n");//�����������鶥��
    for(i=0;i<G->vernum;i++){
        scanf("%s",&(G->vertices[i].name));
        G->vertices[i].first=NULL;
    }

    for(i=0;i<G->arcnum;i++){
        printf("\n�����%d�ߵ����������Լ��ñߵ�Ȩֵ��",i+1);
        scanf("%s %s %d",&name1,&name2,&weight);
        int m=0,n=0;
        m=locateVertex(G,name1);
        n=locateVertex(G,name2);

        p=(ArcNode*)malloc(sizeof(ArcNode));//����һ���µ�������
        p->weight=weight;
        p->adjvex=n;
        //strcpy(p->adjvex,name2);
        p->next=G->vertices[m].first;
        G->vertices[m].first=p;
    }
    //printf("%s",G->vertices[0].name);//����
    //printf("%d",G->vertices[0].first->adjvex);

}

#endif // CREATGRAPH_H_INCLUDED
