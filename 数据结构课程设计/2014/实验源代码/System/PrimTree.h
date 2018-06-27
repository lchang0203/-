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
    int index=0;         // prim��С������������prims���������
    VertexType prims[MAX_VERTEX_NUM];     // prim��С���Ľ������
    int weights[MAX_VERTEX_NUM];    // �����ߵ�Ȩֵ

    // prim��С�������е�һ������"ͼ�е�start������"����Ϊ�Ǵ�start��ʼ�ġ�
    strcpy(prims[index++], G.vertices[start].name);

    // ��ʼ��"�����Ȩֵ����"��
    // ��ÿ�������Ȩֵ��ʼ��Ϊ"��start������"��"�ö���"��Ȩֵ��
    for (i = 0; i < G.vexnum; i++ )
        weights[i] = getWeight(G, start, i);

    for (i = 0; i < G.vexnum; i++)
    {
        // ���ڴ�start��ʼ�ģ���˲���Ҫ�ٶԵ�start��������д���
        if(start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;// ��δ�����뵽��С�������Ķ����У��ҳ�Ȩֵ��С�Ķ��㡣

        while (j < G.vexnum)
        {
            if (weights[j] != 0 && weights[j] < min)// ��weights[j]=0����ζ��"��j���ڵ��Ѿ��������"(����˵�Ѿ���������С��������)��
            {
                min = weights[j];
                k = j;
            }
            j++;
        }// ��������Ĵ������δ�����뵽��С�������Ķ����У�Ȩֵ��С�Ķ����ǵ�k�����㡣

        strcpy(prims[index++],G.vertices[k].name);// ����k��������뵽��С�������Ľ��������
        weights[k] = 0;// ��"��k�������Ȩֵ"���Ϊ0����ζ�ŵ�k�������Ѿ��Ѿ���������С������С�

        for (j = 0 ; j < G.vexnum; j++)// ����k�����㱻���뵽��С�������Ľ��������֮�󣬸������������Ȩֵ��
        {
            tmp = getWeight(G, k, j);// ��ȡ��k�����㵽��j�������Ȩֵ
            if (weights[j] != 0 && tmp < weights[j])// ����j���ڵ�û�б�����������Ҫ����ʱ�ű����¡�
                weights[j] = tmp;
        }
    }

    // ������С��������Ȩֵ
    sum = 0;
    for (i = 1; i < index; i++)
    {
        min = INF;
        // ��ȡprims[i]��G�е�λ��
        n = locateVex(G, prims[i]);
        // ��vexs[0...i]�У��ҳ���j��Ȩֵ��С�Ķ��㡣
        for (j = 0; j < i; j++)
        {
            m = locateVex(G, prims[j]);
            tmp = getWeight(G, m, n);
            if (tmp < min)
                min = tmp;
        }
        sum += min;
    }
    // ��ӡ��С������
    printf("��%s��·һ����Ҫ��·��Ϊ��%d\n", G.vertices[start].name, sum);
    printf("��·��˳���ǣ�", prims[i]);
    for (i = 0; i < index; i++)
        printf("%s ", prims[i]);
    printf("\n");
}

#endif // PRIMTREE_H_INCLUDED
