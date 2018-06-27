#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include "DataStructure.h"
#include "CreateGraph.h"

//输出各条最短路径
void ppth(int path[],int i,int v0,MGraph G){
	int k;
	k=path[i];
	if(k==v0)
		return;
	ppth(path,k,v0,G);
	printf("%s→",G.vexs[k]);
}

//由dist计算最短路径
void DisPath(int dist[],int path[],int s[],int n,int v0,int vd,MGraph G){
	int i;
	printf(" dist:");

    if(dist[vd]!=INF)
        printf("%7d",dist[vd]);
    else
        printf("\t∞");
	printf("\n");

    if(vd!=v0)
    if(s[vd]==1&&dist[vd]<INF){
        printf("%s→%s的最短路径长度为:%d\t路径为:",G.vexs[v0],G.vexs[vd],dist[vd]);
        printf("%s→",G.vexs[v0]);
        ppth(path,vd,v0,G);
        printf("%s\n",G.vexs[vd]);
    }
    else
        printf("%s→%s不存在路径\n",G.vexs[v0],G.vexs[vd]);
}

void dijkstra(MGraph G,int v0,int vd)  //采用Dijkstra算法求从顶点v0到其余各顶点的最短路径
{
	int dist[MAX_VERTEX_NUM],path[MAX_VERTEX_NUM];//距离与路径，path表示这个顶点前的顶点
	int s[MAX_VERTEX_NUM];//已求出最短路径的顶点集合,每求得一条最短路径 , 就将其加入到集合S中
	int mindis,i,j,u,n=G.vexnum;
	for(i=0; i<n; i++){
		dist[i]=G.arcs[v0][i];//各顶点到v0的距离设为直接到达距离
		s[i]=0;
		if(G.arcs[v0][i]<INF)//如果可以直接相连
			path[i]=v0;
		else
			path[i]=-1;
	}
	s[v0]=1;//先把v0设置为已求出最短距离的顶点
	path[v0]=0;//v0到自身的路径为0
	for(i=0; i<n; i++){
		mindis=INF;//最短距离先设置为最大
		u=-1;
		for(j=0; j<n; j++)//找出距离当前顶点直接距离最近的顶点
			if(s[j]==0&&dist[j]<mindis){
				u=j;
				mindis=dist[j];
			}
        s[u]=1;//以u作为当前顶点开始寻找
        for(j=0; j<n; j++)
            if(s[j]==0)
                if(G.arcs[u][j]<INF&&dist[u]+G.arcs[u][j]<dist[j]){
                    dist[j]=dist[u]+G.arcs[u][j];
                    path[j]=u;
                }
	}
	printf("\n输出最短路径和最短路径长度为:\n");
	DisPath(dist,path,s,n,v0,vd,G);
}
#endif // DIJKSTRA_H_INCLUDED
