#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#define MAX_VERTEX_NUM 20
#define INF 32767


//邻接链表数据结构
typedef char VertexType[20];

typedef struct ArcNode{
    //VertexType name;
    int adjvex;
    struct ArcNode *next;
    int weight;
}ArcNode;

typedef struct Node{
	VertexType name;
	ArcNode *first;
}Node,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	int vernum;//顶点数vertex
	int arcnum;//边数arc
	AdjList vertices;
}ALGraph;


//邻接矩阵数据结构
typedef int mapmax[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct Matrix{
    int vernum;//顶点数
	int arcnum;//边数
	VertexType vnum[MAX_VERTEX_NUM];
	mapmax map;
	//memset(map,0,sizeof(map));
	//int map[4][4];
}Matrix;


//邻接链表转化为邻接矩阵
void change(ALGraph *G)//,Matrix *M)
{
    Matrix M;
    memset(M.map,0,sizeof(M.map));
    int i=0,j=0;
    ArcNode *p1;
    M.arcnum=G->arcnum;
    M.vernum=G->vernum; //弧数点数直接复制
    for(i=0;i<G->arcnum;i++)
    {
        strcpy(M.vnum[i],G->vertices[i].name);
        p1=G->vertices[i].first;
        while(p1)    //第一个点指向的点依次给邻接矩阵赋值
        {
            M.map[i][p1->adjvex]=p1->weight;
            p1=p1->next;
        }
    }
    for(i=0;i<M.vernum;i++)
    {
        for(j=0;j<M.vernum;j++)
        {
            printf("%d ",M.map[i][j]);
        }
        printf("\n");
    }
}

#endif // HEAD_H_INCLUDED


