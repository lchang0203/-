#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define INF 32767  //���������ֵ�����
#define MAXV 15  //��󶥵����

typedef struct  //���嶥������
{ char data;
} VertexType;

typedef struct
{ int adj;  //�ߵ�Ȩֵ
}AdjMartrix[MAXV][MAXV];  //��ά����

//�����������Ľṹ����
typedef struct
{
	AdjMartrix arcs;  //�ڽӾ���
	int vexnum, arcnum;  //��������ǰ�������ͻ���
    VertexType vexs[MAXV]; //�������������
} ALGraph;

// ��ͼG�Ķ��������в��Ҷ���v���ֵ�λ��
int LocateVex(ALGraph G, char v)
{
	int i;

	for(i=0; i<G.vexnum; i++)
		if(v==G.vexs[i].data)
			return i;

		return -1;
}

//����������·��
void ppth(int path[],int i,int v0,ALGraph G)
{
	int k;
	//int path1[v0][]=path[];
	k=path[i];
	if(k==v0)
		return;
	ppth(path,k,v0,G);
	printf("%c��",G.vexs[k].data);
}

//��dist�������·��
void DisPath(int dist[],int path[],int s[],int n,int v0,ALGraph G)
{
	int i;
	printf(" dist:");
	for(i=0;i<n;i++)
		if(dist[i]!=INF)
			printf("%7d",dist[i]);
		else
		    printf("\t��");
	printf("\n");
	for(i=0;i<n;i++)
		if(i!=v0)
		if(s[i]==1&&dist[i]<INF)
		{
			printf("%c��%c�����·������Ϊ:%d\t·��Ϊ:",G.vexs[v0].data,G.vexs[i].data,dist[i]);
			printf("%c��",G.vexs[v0].data);
			ppth(path,i,v0,G);
			printf("%c\n",G.vexs[i].data);
		}
		else
			printf("%c��%c������·��\n",G.vexs[v0].data,G.vexs[i].data);
}

// 1--�������������ڽӾ���洢�ṹ
void CreateAdjList(ALGraph &G)
{
	int i,j,k,info;
	char vex,v1,v2;
	FILE *fp;

	// �ȴ򿪴洢ͼ���ļ�
	if(NULL==(fp=fopen("g.dat", "r")))
	{
		printf("�������Ĵ洢�ļ���ʧ�ܣ������ļ�g.dat�Ƿ���ڣ�");
		exit(-1);
	}

	printf("�������������ж���ĸ����ͻ�������:");
	fscanf(fp, "%d%d", &G.vexnum, &G.arcnum);
	printf("%d %d", G.vexnum, G.arcnum);

	printf(" ��������������%d������ı�־:\n", G.vexnum);
	for(i=0; i<G.vexnum; i++)
	{
		vex=fgetc(fp);
		while(!isalpha(vex))
		{
			vex=fgetc(fp);
		}

		G.vexs[i].data = vex;
	}

	printf("ͼ�е�%d����������Ϊ:\n", G.vexnum);
	for(i=0; i<G.vexnum; i++)
	{
		printf("%2c", G.vexs[i].data);
	}
    for(i=0;i<G.vexnum;++i)//��ʼ����ά�ڽӾ���
	{
		for(j=0;j<G.vexnum;++j)
		{ G.arcs[i][j].adj=INF;
		}  //����������
	}
	printf("\n���������������е�%d����(Format:����1��־,����2��־,����)!\n", G.arcnum);
	for(k=0; k<G.arcnum;k++)
	{
		//	fflush(stdin);
		fgetc(fp);
		// ����һ�����Ķ���1������2��Ȩֵ
		printf("\n�������%d������", k+1);
		fscanf(fp, "%c,%c,%d", &v1, &v2, &info);
		printf("%c,%c,%d", v1, v2, info);
		i=LocateVex(G,v1);  //����1�����
        j=LocateVex(G,v2);  //����2�����
		G.arcs[i][j].adj=info;  //��
		G.arcs[j][i].adj= G.arcs[i][j].adj;  //����������Ԫ����Ϣ��ͬ
	}
	fclose(fp);
}

//2--����ڽӾ���洢�ṹ��������
void Display(ALGraph G)
{
	int i,j;
	printf("\n���������ڽӾ���Ϊ:\n");
	printf("G.arcs.adj: \n");
	for(i=0;i<G.vexnum;i++)  //�����ά����G.arcs.adj
	{ for(j=0;j<G.vexnum;j++)
			 if(G.arcs[i][j].adj!=INF)
				 printf("\t%d",G.arcs[i][j].adj);
			 else if(i==j)
				 printf("\t0");
			 else
				 printf("\t��");
			 printf("\n");
	}
}

//3--����������������һ��������ΪԴ��
int Input(ALGraph G)
{
	int i;
	char vexx;
	fflush(stdin);
    printf("��������Ҫѡ���Դ��ı�־��Ӣ����ĸ��: ");
	scanf("%c", &vexx);
	if(vexx>='a'&&vexx<='z')
		vexx-=32;	//Сдת��д
	i=LocateVex(G,vexx);
    return i;
}

//4--Dijkstra�㷨�����·�������·������
void Dijkstra(ALGraph G,int v0)  //����Dijkstra�㷨��Ӷ���v0���������������·��
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
	printf("������·�������·������Ϊ:\n");
	DisPath(dist,path,s,n,v0,G);
}

// ���ܲ˵�
void menu()
{
	printf("\n\t*********Dijkstra�㷨��Դ���·��**************\n");
	printf("\t*      1--�������������ڽӾ���洢�ṹ          *\n");
	printf("\t*      2--����ڽӾ���洢�ṹ��������          *\n");
	printf("\t*      3--����������������һ��������ΪԴ��      *\n");
	printf("\t*      4--Dijkstra�㷨�����·�������·������  *\n");
	printf("\t*      0--�˳�����                              *\n");
	printf("\t������˵��");
}

// ��ʼ��������
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
			printf("\n���������ڽӾ���洢�ṹ�����ɹ���\n");
			break;

		case 2:
			if(G.vexnum!=0)
				Display(G);
			else
				printf("\n���ȴ������������ڽӾ���洢�ṹ��\n");
			break;


		case 3:

            if(G.vexnum!=0)

			{
				startVexPoi = Input(G);

				if(-1==startVexPoi)
					printf("Ҫ����Ķ��㲻���ڣ�");
				else
				{
					printf("Dijkstra�㷨��Դ���� %c",G.vexs[startVexPoi].data );
					printf("\n��ѡ��˵�4��Դ���·����" );
				}
			}
            else
				printf("\n���ȴ������������ڽӾ���洢�ṹ��\n");
			break;


		case 4:
			if(G.vexnum!=0)
			{
				if(-1==startVexPoi)
					printf("��������Դ���־��");
				else
					Dijkstra(G, startVexPoi);
			}
            else
				printf("\n���ȴ������������ڽӾ���洢�ṹ��\n");
			break;


		case 0:
			exit(0);
			break;


		default:
			printf("�˵��������������������!\n");
		}
	}
}
