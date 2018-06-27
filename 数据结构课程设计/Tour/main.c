#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include "showMenu.h"
#include "creatGraph.h"
#include "DFS.h"
#include "Dijkstra.h"

//void showMenu();
//void creatGraph(ALGraph &G);

int main()
{
    //showMenu();
    int i,j;
    int prev[MAX_VERTEX_NUM] = {0};
    int dist[MAX_VERTEX_NUM] = {0};


    ALGraph G;
    //Matrix *M;
    creatGraph(&G);
    //i=locateVertex(&G,"222");
    //printf("%d",i);
    //memset(M.map,0,sizeof(M.map));
    //change(&G);
    //getWeight(&G,0,3);
    //printf("%d",M->map[0][0]);

    //DFSTraverse(&G);
    dijkstra(&G,prev,dist);

    return 0;
}


