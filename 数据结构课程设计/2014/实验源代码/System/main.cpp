#include "stdio.h"
#include "DataStructure.h"
#include "CreateGraph.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "ShowMenu.h"
#include "Sort.h"
#include "Search.h"
#include "ParkingLot.h"
#include "PrimTree.h"
using namespace std;

int main(){
    system("color 70");

    int choice,sortchoice;
    int startVexPoi=-1;
    int endVexPoi=-1;
    ALGraph G,G1;
    MGraph M;


    //createGraph(G);
    //addInformation(G);
    //memset(M.arcs,0,sizeof(M.arcs));
    //change(G,M);
    //display(M);
    //DFSTraverse(G);
    //dijkstra(M,0);
    //hotSort(G);
    //roadSort(G);
    //searchWord(G);


    while(1)
	{
		showMenu();
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			createGraph(G);
			addInformation(G);
			memset(M.arcs,0,sizeof(M.arcs));
            change(G,M);
			break;

		case 2:
			if(G.vexnum!=0)
				display(M);
			else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

        case 3:
			if(G.vexnum!=0)
				CreatTourSortGraph(G,M,G1);
			else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

		case 4:
			printf("\n对不起此功能暂未实现。\n");
			break;

        case 5:
            if(G.vexnum!=0)
			{
			    printf("\n输入景区中任意一个景点作为起点\n");
				startVexPoi = Input(G);
				printf("\n输入景区中任意一个景点作为终点\n");
				endVexPoi = Input(G);

				if(-1==startVexPoi)
					printf("要输入的顶点不存在！");
                if(-1==endVexPoi)
					printf("要输入的顶点不存在！");
				else
				{
					printf("\n您选择路径的起点为：%s  终点为：%s\n",M.vexs[startVexPoi],M.vexs[endVexPoi]);
					dijkstra(M, startVexPoi, endVexPoi);
				}
			}
            else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

        case 6:
			if(G.vexnum!=0)
				prim(G,0);
			else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

        case 7:
			if(G.vexnum!=0)
				searchWord(G);
			else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

        case 8:
			if(G.vexnum!=0){
			    printf("1.按景点热度排序2.按景点岔路数排序---请输入排序方式<1,2>：");
			    scanf("%d",&sortchoice);
				sortT(G,sortchoice);
			}
			else
				printf("\n请先创建景区景点的邻接链表存储结构！\n");
			break;

        case 9:
			parkinglotSystem();
			break;

		case 0:
			exit(0);
			break;


		default:
			printf("菜单项输入错误，请重新输入!\n");
		}
	}
    return 0;
}
