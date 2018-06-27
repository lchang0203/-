#ifndef PRIMTREE_H_INCLUDED
#define PRIMTREE_H_INCLUDED
#include "DataStructure.h"

int getWeight(ALGraph G, int start, int end)
{
    ArcNode *node;

    if (start==end)
        return 0;

    node = G.vertices[start].first;
    while (node!=NULL)
    {
        if (end==node->adjvex)
            return node->weight;
        node = node->next;
    }

    return INF;
}

void prim(ALGraph G, int start)
{
    int min,i,j,k,m,n,tmp,sum;
    int index=0;         // prim最小树的索引，即prims数组的索引
    VertexType prims[MAX_VERTEX_NUM];     // prim最小树的结果数组
    int weights[MAX_VERTEX_NUM];    // 顶点间边的权值

    // prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
    strcpy(prims[index++], G.vertices[start].name);

    // 初始化"顶点的权值数组"，
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 0; i < G.vexnum; i++ )
        weights[i] = getWeight(G, start, i);

    for (i = 0; i < G.vexnum; i++)
    {
        // 由于从start开始的，因此不需要再对第start个顶点进行处理。
        if(start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;// 在未被加入到最小生成树的顶点中，找出权值最小的顶点。

        while (j < G.vexnum)
        {
            if (weights[j] != 0 && weights[j] < min)// 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            {
                min = weights[j];
                k = j;
            }
            j++;
        }// 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。

        strcpy(prims[index++],G.vertices[k].name);// 将第k个顶点加入到最小生成树的结果数组中
        weights[k] = 0;// 将"第k个顶点的权值"标记为0，意味着第k个顶点已经已经加入了最小树结果中。

        for (j = 0 ; j < G.vexnum; j++)// 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
        {
            tmp = getWeight(G, k, j);// 获取第k个顶点到第j个顶点的权值
            if (weights[j] != 0 && tmp < weights[j])// 当第j个节点没有被处理，并且需要更新时才被更新。
                weights[j] = tmp;
        }
    }

    // 计算最小生成树的权值
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        // 获取prims[i]在G中的位置
        n = locateVex(G, prims[i]);
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for (j = 0; j < i; j++)
        {
            m = locateVex(G, prims[j]);
            tmp = getWeight(G, m, n);
            if (tmp < min)
                min = tmp;
        }
        sum += min;
    }
    // 打印最小生成树
    printf("从%s修路一共需要的路程为：%d\n", G.vertices[start].name, sum);
    printf("修路的顺序是：", prims[i]);
    for (i = 0; i < index; i++)
        printf("%s ", prims[i]);
    printf("\n");
}

#endif // PRIMTREE_H_INCLUDED
