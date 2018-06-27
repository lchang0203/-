#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED
#include "DataStructure.h"
#include "CreateGraph.h"
//int visited[MAX_VERTEX_NUM];
int k=0;
bool visited[MAX_VERTEX_NUM];//�ж϶����Ƿ񱻱�����
VertexType vex[MAX_VERTEX_NUM];//�洢�����Ķ�������
ArcNode *p=new ArcNode;

void DFS(ALGraph G, int v)
{
    visited[v]=true;//true=1���ʹ�
    strcpy(vex[k++],G.vertices[v].name);
    //printf("%s  ",G.vertices[i].name);
    p=G.vertices[v].first;

    for(p=G.vertices[v].first; p ;p=p->next)
        if(!visited[p->adjvex])
        {
            DFS(G,p->adjvex);
            p=G.vertices[v].first;
        }


}

void DFSTraverse(ALGraph G)
{
    int v;
    //printf("����·��Ϊ��");
    for (v=0; v<G.vexnum; v++)
    {
        visited[v] = false;
    }
    for (v=0; v<G.vexnum; v++)
    {
        if (!visited[v])
        {
            DFS(G, v);
        }
    }
    printf("\n");
}
bool IsEdge(ALGraph G,MGraph M,VertexType v1,VertexType v2)
{
    int i=locateVex(G,v1);
    int j=locateVex(G,v2);
    if(M.arcs[i][j]<INF)
    {
        return true;
    }
    return false;
}

VertexType vex1[2*MAX_VERTEX_NUM];
void CreatTourSortGraph(ALGraph G,MGraph M,ALGraph &G1)
{
    DFSTraverse(G);
    //printf("\n");
    int i,j,n=0;
    bool Is;
    for (i=0; i<G.vexnum-1; i++)
    {
        k=0;
        Is=true;
        while (Is)
        {
            strcpy(vex1[n++],vex[i+k]);
            if(IsEdge(G,M,vex[i+k],vex[i+1]))//�������֮���б߾�ֱ��������������
                Is=false;
            else
                k--;//���û�оͻ��ݣ�ֱ���ҵ���vex[i+1]�бߵ�
        }
    }
    strcpy(vex1[n],vex[i]);//�����һ������Ž�vex������
    for(i=0; i<=n; i++)
    {
        visited[i]=false;
    }
    for (i=0; i<G.vexnum; i++) //��ʼ������ͼ
    {
        strcpy(G1.vertices[i].name,G.vertices[i].name);
        G1.vertices[i].first=NULL;
    }
    int arcnum=0;//��¼������·ͼ�еıߵĸ���
    for (k=0; k<n; k++)
    {
        i=locateVex(G,vex1[k]);
        j=locateVex(G,vex1[k+1]);
        if(visited[j])//����õ��Ѿ��ڵ�����·ͼ�У���Ѱ�����Ƿ����Ѿ��ڵ�����·ͼ�еĵ��γɻ�·
        {
            int m=k+2;//��������ֱ��ǰ��
            if(m<=n)//�ж��Ƿ񳬳��洢������·ͼ������
            {
                while(visited[locateVex(G,vex1[m])])//ֱ�������µĽڵ�Ϊֹ
                {
                    /*�ж�����������ԭ���ľ����ֲ�ͼ���Ƿ��бߣ�����о������������ߣ����߼��������*/
                    if(IsEdge(G,M,vex1[k],vex1[m]))
                    {
                        j=locateVex(G,vex1[m]);
                        ArcNode *P=new ArcNode;
                        ArcNode *Q=new ArcNode;
                        P->adjvex=j;
                        P->weight=M.arcs[i][j];
                        Q=G1.vertices[i].first;
                        G1.vertices[i].first=P;
                        P->next=Q;
                        arcnum++;
                    }
                    if(++m>=n)//����ڲ��ҵĹ����е�������ĩβ��ǿ���˳�
                        break;
                }
            }
        }
        else    //���û���ڵ�����·ͼ�о���������
        {
            visited[i]=visited[j]=true;
            ArcNode *P=new ArcNode;
            ArcNode *Q=new ArcNode;
            P->adjvex=j;
            P->weight=M.arcs[i][j];
            Q=G1.vertices[i].first;
            G1.vertices[i].first=P;
            P->next=Q;
            arcnum++;
        }
    }
    G1.vexnum=G.vexnum;//��ֵ������·ͼ�ж���ĸ���
    G1.arcnum=arcnum;//��ֵ������·ͼ�бߵĸ���
    printf("����·��Ϊ��");
    for(i=0; i<=n; i++)
        printf("%s ",vex1[i]); //���������·ͼ
    printf("\n");

}
#endif // DFS_H_INCLUDED
