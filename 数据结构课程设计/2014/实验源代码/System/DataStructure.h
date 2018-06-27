#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#define MAX_VERTEX_NUM 20
#define INF 32767
#include "stdio.h"
#include <stdlib.h>
#include <cstring>
using namespace std;

typedef char VertexType[30];
typedef struct Information{
    char introduction[200];
    int popularity;
    int roadnum;
}Information;

//�ڽ��������ݽṹ
typedef struct ArcNode{
    //VertexType name;
    int adjvex;
    struct ArcNode *next;
    int weight;
}ArcNode;

typedef struct Node{
	VertexType name;
	ArcNode *first;
	Information info;
}Node,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	int vexnum;//������vertex
	int arcnum;//����arc
	AdjList vertices;
}ALGraph;


//�ڽӾ������ݽṹ
//typedef struct
//{ int adj;  //�ߵ�Ȩֵ
//}AdjMartrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //��ά����

typedef struct
{
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //�ڽӾ���
	int vexnum, arcnum;  //��������ǰ�������ͻ���
    VertexType vexs[MAX_VERTEX_NUM];//�������������
    Information info[MAX_VERTEX_NUM];//���ܶ�����Ϣ������
} MGraph;

int locateVex(ALGraph G, VertexType v)
{
	int i;

	for(i=0; i<G.vexnum; i++)
		if(strcmp(G.vertices[i].name, v) == 0)
			return i;

		return -1;
}

void change(ALGraph &G,MGraph &M){

    int i=0,j=0;
    ArcNode *p1=NULL;
    M.arcnum=G.arcnum;
    M.vexnum=G.vexnum; //��������ֱ�Ӹ���

    //��ʼ����ά�ڽӾ���
    for(i=0;i<M.vexnum;i++){
		for(j=0;j<M.vexnum;j++)
		{ M.arcs[i][j]=INF;
		}
	}
    for(i=0;i<G.vexnum;i++){
        strcpy(M.vexs[i],G.vertices[i].name);
        strcpy(M.info[i].introduction,G.vertices[i].info.introduction);
        M.info[i].popularity=G.vertices[i].info.popularity;
        M.info[i].roadnum=G.vertices[i].info.roadnum;
        p1=G.vertices[i].first;
        while(p1){ //��һ����ָ��ĵ����θ��ڽӾ���ֵ
            M.arcs[i][p1->adjvex]=p1->weight;
            M.arcs[p1->adjvex][i]=M.arcs[i][p1->adjvex];
            p1=p1->next;
        }
    }
    //printf("change����\n");
    //for(i=0;i<M.vexnum;i++){
    //    printf("%s ",M.vexs[i]);
    //}
    printf("\n����������ڽӾ���洢�ṹת���ɹ���\n");
}

void display(MGraph M)
{
	int i,j;
	printf("\n                  ����������ڽӾ���Ϊ:\n");
	//�����ά����
	for(i=0;i<M.vexnum;i++){
	    printf("\t%s",M.vexs[i]);
	}
	printf("\n");
	for(i=0;i<M.vexnum;i++){
	    printf("%s",M.vexs[i]);
	    for(j=0;j<M.vexnum;j++)
			 if(M.arcs[i][j]!=INF)
				 printf("\t%d",M.arcs[i][j]);
			 else if(i==j)
				 printf("\t0");
			 else
				 printf("\t��");
			 printf("\n");
	}
}

int Input(ALGraph G)
{
	int i;
	VertexType vexx;
	fflush(stdin);

	scanf("%s", &vexx);
	i=locateVex(G,vexx);
    return i;
}

#endif // DATASTRUCTURE_H_INCLUDED
