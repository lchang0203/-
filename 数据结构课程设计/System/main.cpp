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
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

        case 3:
			if(G.vexnum!=0)
				CreatTourSortGraph(G,M,G1);
			else
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

		case 4:
			printf("\n�Բ���˹�����δʵ�֡�\n");
			break;

        case 5:
            if(G.vexnum!=0)
			{
			    printf("\n���뾰��������һ��������Ϊ���\n");
				startVexPoi = Input(G);
				printf("\n���뾰��������һ��������Ϊ�յ�\n");
				endVexPoi = Input(G);

				if(-1==startVexPoi)
					printf("Ҫ����Ķ��㲻���ڣ�");
                if(-1==endVexPoi)
					printf("Ҫ����Ķ��㲻���ڣ�");
				else
				{
					printf("\n��ѡ��·�������Ϊ��%s  �յ�Ϊ��%s\n",M.vexs[startVexPoi],M.vexs[endVexPoi]);
					dijkstra(M, startVexPoi, endVexPoi);
				}
			}
            else
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

        case 6:
			if(G.vexnum!=0)
				prim(G,0);
			else
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

        case 7:
			if(G.vexnum!=0)
				searchWord(G);
			else
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

        case 8:
			if(G.vexnum!=0){
			    printf("1.�������ȶ�����2.�������·������---����������ʽ<1,2>��");
			    scanf("%d",&sortchoice);
				sortT(G,sortchoice);
			}
			else
				printf("\n���ȴ�������������ڽ�����洢�ṹ��\n");
			break;

        case 9:
			parkinglotSystem();
			break;

		case 0:
			exit(0);
			break;


		default:
			printf("�˵��������������������!\n");
		}
	}
    return 0;
}
