#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define INF 32767  //用整型最大值代替∞
#define MAXV 15  //最大顶点个数

typedef struct  //定义顶点类型
{ char data;
} VertexType;

typedef struct
{ int adj;  //边的权值
}AdjMartrix[MAXV][MAXV];  //二维数组

//定义无向网的结构类型
typedef struct
{
	AdjMartrix arcs;  //邻接矩阵
	int vexnum, arcnum;  //无向网当前顶点数和弧数
    VertexType vexs[MAXV]; //描述顶点的数组
} ALGraph;

// 从图G的顶点数组中查找顶点v出现的位置
int LocateVex(ALGraph G, char v)
{
	int i;

	for(i=0; i<G.vexnum; i++)
		if(v==G.vexs[i].data)
			return i;

		return -1;
}

//输出各条最短路径
void ppth(int path[],int i,int v0,ALGraph G)
{
	int k;
	//int path1[v0][]=path[];
	k=path[i];
	if(k==v0)
		return;
	ppth(path,k,v0,G);
	printf("%c→",G.vexs[k].data);
}

//由dist计算最短路径
void DisPath(int dist[],int path[],int s[],int n,int v0,ALGraph G)
{
	int i;
	printf(" dist:");
	for(i=0;i<n;i++)
		if(dist[i]!=INF)
			printf("%7d",dist[i]);
		else
		    printf("\t∞");
	printf("\n");
	for(i=0;i<n;i++)
		if(i!=v0)
		if(s[i]==1&&dist[i]<INF)
		{
			printf("%c→%c的最短路径长度为:%d\t路径为:",G.vexs[v0].data,G.vexs[i].data,dist[i]);
			printf("%c→",G.vexs[v0].data);
			ppth(path,i,v0,G);
			printf("%c\n",G.vexs[i].data);
		}
		else
			printf("%c→%c不存在路径\n",G.vexs[v0].data,G.vexs[i].data);
}

// 1--创建无向网的邻接矩阵存储结构
void CreateAdjList(ALGraph &G)
{
	int i,j,k,info;
	char vex,v1,v2;
	FILE *fp;

	// 先打开存储图的文件
	if(NULL==(fp=fopen("g.dat", "r")))
	{
		printf("无向网的存储文件打开失败，请检查文件g.dat是否存在！");
		exit(-1);
	}

	printf("请输入无向网中顶点的个数和弧的条数:");
	fscanf(fp, "%d%d", &G.vexnum, &G.arcnum);
	printf("%d %d", G.vexnum, G.arcnum);

	printf(" 请输入无向网中%d个顶点的标志:\n", G.vexnum);
	for(i=0; i<G.vexnum; i++)
	{
		vex=fgetc(fp);
		while(!isalpha(vex))
		{
			vex=fgetc(fp);
		}

		G.vexs[i].data = vex;
	}

	printf("图中的%d个顶点依次为:\n", G.vexnum);
	for(i=0; i<G.vexnum; i++)
	{
		printf("%2c", G.vexs[i].data);
	}
    for(i=0;i<G.vexnum;++i)//初始化二维邻接矩阵
	{
		for(j=0;j<G.vexnum;++j)
		{ G.arcs[i][j].adj=INF;
		}  //网，不相邻
	}
	printf("\n下面输入无向网中的%d条弧(Format:顶点1标志,顶点2标志,距离)!\n", G.arcnum);
	for(k=0; k<G.arcnum;k++)
	{
		//	fflush(stdin);
		fgetc(fp);
		// 输入一条弧的顶点1，顶点2，权值
		printf("\n请输入第%d条弧：", k+1);
		fscanf(fp, "%c,%c,%d", &v1, &v2, &info);
		printf("%c,%c,%d", v1, v2, info);
		i=LocateVex(G,v1);  //顶点1的序号
        j=LocateVex(G,v2);  //顶点2的序号
		G.arcs[i][j].adj=info;  //网
		G.arcs[j][i].adj= G.arcs[i][j].adj;  //无向，两个单元的信息相同
	}
	fclose(fp);
}

//2--输出邻接矩阵存储结构的无向网
void Display(ALGraph G)
{
	int i,j;
	printf("\n无向网的邻接矩阵为:\n");
	printf("G.arcs.adj: \n");
	for(i=0;i<G.vexnum;i++)  //输出二维数组G.arcs.adj
	{ for(j=0;j<G.vexnum;j++)
			 if(G.arcs[i][j].adj!=INF)
				 printf("\t%d",G.arcs[i][j].adj);
			 else if(i==j)
				 printf("\t0");
			 else
				 printf("\t∞");
			 printf("\n");
	}
}

//3--输入无向网中任意一个顶点作为源点
int Input(ALGraph G)
{
	int i;
	char vexx;
	fflush(stdin);
    printf("请输入你要选择的源点的标志（英文字母）: ");
	scanf("%c", &vexx);
	if(vexx>='a'&&vexx<='z')
		vexx-=32;	//小写转大写
	i=LocateVex(G,vexx);
    return i;
}

//4--Dijkstra算法求最短路径和最短路径长度
void Dijkstra(ALGraph G,int v0)  //采用Dijkstra算法求从顶点v0到其余各顶点的最短路径
{
	int dist[MAXV],path[MAXV];
	int s[MAXV];
	int mindis,i,j,u,n=G.vexnum;
	for(i=0; i<n; i++)
	{
		dist[i]=G.arcs[v0][i].adj;
		s[i]=0;
		if(G.arcs[v0][i].adj<INF)
			path[i]=v0;
		else
			path[i]=-1;
	}
	s[v0]=1;
	path[v0]=0;
	for(i=0; i<n; i++)
	{
		mindis=INF;
		u=-1;
		for(j=0; j<n; j++)
			if(s[j]==0&&dist[j]<mindis)
			{
				u=j;
				mindis=dist[j];
			}
			s[u]=1;
			for(j=0; j<n; j++)
				if(s[j]==0)
					if(G.arcs[u][j].adj<INF&&dist[u]+G.arcs[u][j].adj<dist[j])
					{
						dist[j]=dist[u]+G.arcs[u][j].adj;
						path[j]=u;
					}
	}
	printf("输出最短路径和最短路径长度为:\n");
	DisPath(dist,path,s,n,v0,G);
}

// 功能菜单
void menu()
{
	printf("\n\t*********Dijkstra算法求单源最短路径**************\n");
	printf("\t*      1--创建无向网的邻接矩阵存储结构          *\n");
	printf("\t*      2--输出邻接矩阵存储结构的无向网          *\n");
	printf("\t*      3--输入无向网中任意一个顶点作为源点      *\n");
	printf("\t*      4--Dijkstra算法求最短路径和最短路径长度  *\n");
	printf("\t*      0--退出程序                              *\n");
	printf("\t请输入菜单项：");
}

// 初始化无向网
void init(ALGraph &G)
{
	G.arcnum = 0;
	G.vexnum = 0;
}

int main()
{
	system("color f0");
	ALGraph G;
	int startVexPoi=-1;
	int choice;

	init(G);

	while(1)
	{
		menu();
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			CreateAdjList(G);
			printf("\n无向网的邻接矩阵存储结构创建成功！\n");
			break;

		case 2:
			if(G.vexnum!=0)
				Display(G);
			else
				printf("\n请先创建无向网的邻接矩阵存储结构！\n");
			break;


		case 3:

            if(G.vexnum!=0)

			{
				startVexPoi = Input(G);

				if(-1==startVexPoi)
					printf("要输入的顶点不存在！");
				else
				{
					printf("Dijkstra算法的源点是 %c",G.vexs[startVexPoi].data );
					printf("\n请选择菜单4求单源最短路径！" );
				}
			}
            else
				printf("\n请先创建无向网的邻接矩阵存储结构！\n");
			break;


		case 4:
			if(G.vexnum!=0)
			{
				if(-1==startVexPoi)
					printf("请先输入源点标志！");
				else
					Dijkstra(G, startVexPoi);
			}
            else
				printf("\n请先创建无向网的邻接矩阵存储结构！\n");
			break;


		case 0:
			exit(0);
			break;


		default:
			printf("菜单项输入错误，请重新输入!\n");
		}
	}
}
