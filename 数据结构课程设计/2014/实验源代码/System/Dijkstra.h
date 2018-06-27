#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include "DataStructure.h"
#include "CreateGraph.h"

//����������·��
void ppth(int path[],int i,int v0,MGraph G){
	int k;
	k=path[i];
	if(k==v0)
		return;
	ppth(path,k,v0,G);
	printf("%s��",G.vexs[k]);
}

//��dist�������·��
void DisPath(int dist[],int path[],int s[],int n,int v0,int vd,MGraph G){
	int i;
	printf(" dist:");

    if(dist[vd]!=INF)
        printf("%7d",dist[vd]);
    else
        printf("\t��");
	printf("\n");

    if(vd!=v0)
    if(s[vd]==1&&dist[vd]<INF){
        printf("%s��%s�����·������Ϊ:%d\t·��Ϊ:",G.vexs[v0],G.vexs[vd],dist[vd]);
        printf("%s��",G.vexs[v0]);
        ppth(path,vd,v0,G);
        printf("%s\n",G.vexs[vd]);
    }
    else
        printf("%s��%s������·��\n",G.vexs[v0],G.vexs[vd]);
}

void dijkstra(MGraph G,int v0,int vd)  //����Dijkstra�㷨��Ӷ���v0���������������·��
{
	int dist[MAX_VERTEX_NUM],path[MAX_VERTEX_NUM];//������·����path��ʾ�������ǰ�Ķ���
	int s[MAX_VERTEX_NUM];//��������·���Ķ��㼯��,ÿ���һ�����·�� , �ͽ�����뵽����S��
	int mindis,i,j,u,n=G.vexnum;
	for(i=0; i<n; i++){
		dist[i]=G.arcs[v0][i];//�����㵽v0�ľ�����Ϊֱ�ӵ������
		s[i]=0;
		if(G.arcs[v0][i]<INF)//�������ֱ������
			path[i]=v0;
		else
			path[i]=-1;
	}
	s[v0]=1;//�Ȱ�v0����Ϊ�������̾���Ķ���
	path[v0]=0;//v0�������·��Ϊ0
	for(i=0; i<n; i++){
		mindis=INF;//��̾���������Ϊ���
		u=-1;
		for(j=0; j<n; j++)//�ҳ����뵱ǰ����ֱ�Ӿ�������Ķ���
			if(s[j]==0&&dist[j]<mindis){
				u=j;
				mindis=dist[j];
			}
        s[u]=1;//��u��Ϊ��ǰ���㿪ʼѰ��
        for(j=0; j<n; j++)
            if(s[j]==0)
                if(G.arcs[u][j]<INF&&dist[u]+G.arcs[u][j]<dist[j]){
                    dist[j]=dist[u]+G.arcs[u][j];
                    path[j]=u;
                }
	}
	printf("\n������·�������·������Ϊ:\n");
	DisPath(dist,path,s,n,v0,vd,G);
}
#endif // DIJKSTRA_H_INCLUDED
