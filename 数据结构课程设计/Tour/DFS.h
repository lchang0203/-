#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED
#include "head.h"
#include "creatGraph.h"
int visited[MAX_VERTEX_NUM];

void DFS(ALGraph *G, int i){
    ArcNode *p;
    visited[i]=1;//true=1访问过
    printf("%s--",G->vertices[i].name);
    p=G->vertices[i].first;

    while(p){
        if(visited[p->adjvex]==0){
            DFS(G,p->adjvex);//引用不需使用&G
        }
        p=p->next;
    }

}

void DFSTraverse(ALGraph *G){
    int i;
    for (i=0;i<G->vernum;i++){
        visited[i] = 0;
    }
    for (i=0;i<G->vernum;i++){
        if (visited[i]==0){
            DFS(G, i);
        }
    }
}

//bool IsEdge(ALGraph G,string v1,string v2){
//}
#endif // DFS_H_INCLUDED
