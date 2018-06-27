#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include "head.h"


int getWeight(ALGraph *G, int start, int end){

    ArcNode *node;

    if (start==end){
        return 0;
    }
    node = G->vertices[start].first;
    while (node!=NULL){
        if (end==node->adjvex){
            //printf("%d",node->weight);//输出测试
            return node->weight;
        }
        node = node->next;
    }

    return INF;
}

void dijkstra(ALGraph *G, int prev[], int dist[]){

    int vs=0,vd=0;
    int i,j,k=0;
    int min=0;
    int tmp=0;
    VertexType name_1,name_2;
    int flag[MAX_VERTEX_NUM]={0};// flag[i]=1表示"顶点v"到"顶点i"的最短路径已成功获取。

    //输入两个景区名称
    printf("\n请输入您想查询的两个景点：");
    scanf("%s %s",&name_1,&name_2);
    vs=locateVertex(G,name_1);
    vd=locateVertex(G,name_2);
    //printf("%d,%d",vs,vd);//测试

    for (i = 0; i<G->vernum; i++){// 初始化
        flag[i] = 0;// 顶点i的最短路径还没获取到。
        prev[i] = 0;// 顶点i的前驱顶点为0。
        dist[i] = getWeight(G, vs, i);// 顶点i的最短路径为"顶点v"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vernum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G->vernum; i++){// 寻找当前最小的路径；
        min = INF;                  // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        for (j = 0; j < G->vernum; j++){
            if (flag[j]==0 && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G->vernum; j++){
            tmp = getWeight(G, k, j);
            tmp = (tmp==INF ? INF : (min + tmp)); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) ){
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("%s\n",G->vertices[0].name);
    printf("%s\n",G->vertices[1].name);
    printf("%s\n",G->vertices[2].name);
    printf("%s\n", G->vertices[vs].name);
    printf("shortest(%s, %s)=%d\n", G->vertices[vs].name, G->vertices[vd].name, dist[vd]);
    //for (i = 0; i < G->vernum; i++)
        //printf("  shortest(%s, %s)=%d\n", G->vertices[vs].name, G->vertices[i].name, dist[i]);
}




#endif // DIJKSTRA_H_INCLUDED
