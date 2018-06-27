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
            //printf("%d",node->weight);//�������
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
    int flag[MAX_VERTEX_NUM]={0};// flag[i]=1��ʾ"����v"��"����i"�����·���ѳɹ���ȡ��

    //����������������
    printf("\n�����������ѯ���������㣺");
    scanf("%s %s",&name_1,&name_2);
    vs=locateVertex(G,name_1);
    vd=locateVertex(G,name_2);
    //printf("%d,%d",vs,vd);//����

    for (i = 0; i<G->vernum; i++){// ��ʼ��
        flag[i] = 0;// ����i�����·����û��ȡ����
        prev[i] = 0;// ����i��ǰ������Ϊ0��
        dist[i] = getWeight(G, vs, i);// ����i�����·��Ϊ"����v"��"����i"��Ȩ��
    }

    // ��"����vs"������г�ʼ��
    flag[vs] = 1;
    dist[vs] = 0;

    // ����G.vernum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G->vernum; i++){// Ѱ�ҵ�ǰ��С��·����
        min = INF;                  // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        for (j = 0; j < G->vernum; j++){
            if (flag[j]==0 && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G->vernum; j++){
            tmp = getWeight(G, k, j);
            tmp = (tmp==INF ? INF : (min + tmp)); // ��ֹ���
            if (flag[j] == 0 && (tmp  < dist[j]) ){
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    printf("%s\n",G->vertices[0].name);
    printf("%s\n",G->vertices[1].name);
    printf("%s\n",G->vertices[2].name);
    printf("%s\n", G->vertices[vs].name);
    printf("shortest(%s, %s)=%d\n", G->vertices[vs].name, G->vertices[vd].name, dist[vd]);
    //for (i = 0; i < G->vernum; i++)
        //printf("  shortest(%s, %s)=%d\n", G->vertices[vs].name, G->vertices[i].name, dist[i]);
}




#endif // DIJKSTRA_H_INCLUDED
