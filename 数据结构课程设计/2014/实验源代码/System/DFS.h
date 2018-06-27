#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED
#include "DataStructure.h"
#include "CreateGraph.h"
//int visited[MAX_VERTEX_NUM];
int k=0;
bool visited[MAX_VERTEX_NUM];//判断顶点是否被遍历过
VertexType vex[MAX_VERTEX_NUM];//存储遍历的顶点序列
ArcNode *p=new ArcNode;

void DFS(ALGraph G, int v)
{
    visited[v]=true;//true=1访问过
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
    //printf("导游路线为：");
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
            if(IsEdge(G,M,vex[i+k],vex[i+1]))//如果他们之间有边就直接连接上这条边
                Is=false;
            else
                k--;//如果没有就回溯，直到找到和vex[i+1]有边的
        }
    }
    strcpy(vex1[n],vex[i]);//将最后一个顶点放进vex数组中
    for(i=0; i<=n; i++)
    {
        visited[i]=false;
    }
    for (i=0; i<G.vexnum; i++) //初始化导游图
    {
        strcpy(G1.vertices[i].name,G.vertices[i].name);
        G1.vertices[i].first=NULL;
    }
    int arcnum=0;//记录导游线路图中的边的个数
    for (k=0; k<n; k++)
    {
        i=locateVex(G,vex1[k]);
        j=locateVex(G,vex1[k+1]);
        if(visited[j])//如果该点已经在导游线路图中，就寻找它是否与已经在导游线路图中的点形成回路
        {
            int m=k+2;//跳过他的直接前驱
            if(m<=n)//判断是否超出存储导游线路图的数组
            {
                while(visited[locateVex(G,vex1[m])])//直到出现新的节点为止
                {
                    /*判断这两个点在原来的景区分布图中是否有边，如果有就连接上这条边，否者继续向后找*/
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
                    if(++m>=n)//如果在查找的过程中到了数组末尾就强行退出
                        break;
                }
            }
        }
        else    //如果没有在导游线路图中就连接上它
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
    G1.vexnum=G.vexnum;//赋值导游线路图中顶点的个数
    G1.arcnum=arcnum;//赋值导游线路图中边的个数
    printf("导游路线为：");
    for(i=0; i<=n; i++)
        printf("%s ",vex1[i]); //输出导游线路图
    printf("\n");

}
#endif // DFS_H_INCLUDED
