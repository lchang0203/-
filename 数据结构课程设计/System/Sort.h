#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include "DataStructure.h"
void hotSort(ALGraph G);
void roadSort(ALGraph G);

void sortT(ALGraph G,int sortchoice){
    if(sortchoice == 1){
        hotSort(G);
    }
    else
        roadSort(G);
}

void hotSort(ALGraph G){
    int i=0,j=0;
    int n=G.vexnum;

    struct SimpleNode{
        VertexType name;
        int popularity;
    };
    SimpleNode sortn[MAX_VERTEX_NUM];
    SimpleNode temp;

    for(i=0;i<G.vexnum;i++){
        strcpy(sortn[i].name,G.vertices[i].name);
        sortn[i].popularity=G.vertices[i].info.popularity;
    }
    for(i=0;i<G.vexnum - 1;i++){
        for(j=0;j < G.vexnum - 1 - i;j++){
            if(sortn[j].popularity > sortn[j+1].popularity){
                temp=sortn[j];

                sortn[j]=sortn[j+1];
                //strcpy(name[j],name[j+1]);
                sortn[j+1]=temp;
                //strcpy(name[j+1],temp);
            }
        }
    }

    printf("按景点热度排名顺序（从热门到冷门）为：\n");
    for(i=G.vexnum-1;i>=0;i--){
        printf("\t%s\t热门程度为 %d\n",sortn[i].name,sortn[i].popularity);
    }

}

void roadSort(ALGraph G){
    int i=0,j=0;
    int n=G.vexnum;

    struct SimpleNode{
        VertexType name;
        int roadnum;
    };
    SimpleNode sortn[MAX_VERTEX_NUM];
    SimpleNode temp;

    for(i=0;i<G.vexnum;i++){
        strcpy(sortn[i].name,G.vertices[i].name);
        sortn[i].roadnum=G.vertices[i].info.roadnum;
    }
    for(i=0;i<G.vexnum - 1;i++){
        for(j=0;j < G.vexnum - 1 - i;j++){
            if(sortn[j].roadnum > sortn[j+1].roadnum){
                temp=sortn[j];

                sortn[j]=sortn[j+1];
                //strcpy(name[j],name[j+1]);
                sortn[j+1]=temp;
                //strcpy(name[j+1],temp);
            }
        }
    }

    printf("按景点岔路数排名顺序（从多到少）为：\n");
    for(i=G.vexnum-1;i>=0;i--){
        printf("\t%s\t岔路数为 %d\n",sortn[i].name,sortn[i].roadnum);
    }

}

#endif // SORT_H_INCLUDED
