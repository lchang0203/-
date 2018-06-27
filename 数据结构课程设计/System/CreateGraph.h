#ifndef CREATGRAPH_H_INCLUDED
#define CREATGRAPH_H_INCLUDED
#include "DataStructure.h"


void createGraph(ALGraph &G)
{
    int i=0;
    VertexType name1,name2;
    int weight=0;
    ArcNode *p=NULL,*node=NULL;

    printf("�����붥�����ͻ�����\n");
    scanf("%d %d",&(G.vexnum),&(G.arcnum));

    printf("��������������֣�\n");//�����������鶥��
    for(i=0; i<G.vexnum; i++)
    {
        scanf("%s",&(G.vertices[i].name));
        G.vertices[i].first=NULL;
        strcpy(G.vertices[i].info.introduction,"�޾�������");
        G.vertices[i].info.popularity=-1;
        G.vertices[i].info.roadnum=-1;
    }

    for(i=0; i<G.arcnum; i++)
    {
        printf("\n�����%d�ߵ����������Լ��ñߵ�Ȩֵ��",i+1);
        scanf("%s %s %d",&name1,&name2,&weight);
        int m=0,n=0;
        m=locateVex(G,name1);
        n=locateVex(G,name2);

        p=(ArcNode*)malloc(sizeof(ArcNode));//����һ���µ�������
        p->weight=weight;
        p->adjvex=n;
        //strcpy(p->adjvex,name2);
        p->next=G.vertices[m].first;
        G.vertices[m].first=p;
        //free(p);
        //p= NULL;
    }
    //printf("create����\n");
    //for(i=0; i<G.vexnum; i++)
    //{
    //    printf("%s ",G.vertices[i].name);
    //}
    //printf("%s",G->vertices[0].name);//����
    printf("\n����������ڽ�����洢�ṹ�����ɹ���\n");
}

    //���� ʨ��ɽ ����ʯ һ���� ������ ����� ������ ����̨
    //���� ʨ��ɽ 8
    //���� ����ʯ 9
    //ʨ��ɽ ������ 6
    //ʨ��ɽ һ���� 7
    //һ���� ����̨ 11
    //������ ����̨ 3
    //����ʯ ������ 5
    //����ʯ ����� 4
    //����� ������ 7

void addInformation (ALGraph &G)
{
    int i;

    for(i=0; i<G.vexnum; i++) //���� ʨ��ɽ ����ʯ һ���� ������ ����� ������ ����̨
    {
        if(strcmp("����",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=1;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"�����Ǿ�������ڡ�");
        }
        else if(strcmp("ʨ��ɽ",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=8;
            G.vertices[i].info.roadnum=3;
            strcpy(G.vertices[i].info.introduction,"ʨ��ɽ����1.4����ǰ���γɣ�����ʨ��ɽ��λ�ã���ǰ��һƬ�����ҡ�ʨ�ӡ�ͷ����������ߣ�ʨ����β�������ط���ɽ�ϡ�");
        }
        else if(strcmp("����ʯ",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=2;
            G.vertices[i].info.roadnum=3;
            strcpy(G.vertices[i].info.introduction,"����ʯ�ڹ۹����ϣ���ʯ���ʣ�������������˵��������ڴ˴���");
        }
        else if(strcmp("һ����",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=7;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"һ������ɽ��֮�䣬�γ������Ķ�����ȣ����ڹȵ������߿գ�Ψ��һ�����졣�������ϣ���������������ƣ���ʯ��磬�Ƹ����𣬷·�ɽ��ҡ�Ρ�");
        }
        else if(strcmp("������",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=6;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"�������Ƕԡ�����ֱ����ǧ��,������������족��õĽ��͡�");
        }
        else if(strcmp("�����",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=4;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"�������Բ������������ޣ����ޡ�ӣ�ޡ����ޡ����ޡ����ޣ������޵�����ͨ����Ȼһ�壬������ɽ��ˮ��");
        }
        else if(strcmp("������",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=3;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"��ɽ������һ�����ţ�ֱͨ����ƽ���еĵ���ޣ������й���ͤ��������Ϊ���ͤ��ͤ���������ޣ����ж��ſ�ͨ��ɽ�뷼���ޡ�");
        }
        else if(strcmp("����̨",G.vertices[i].name) == 0)
        {
            G.vertices[i].info.popularity=5;
            G.vertices[i].info.roadnum=2;
            strcpy(G.vertices[i].info.introduction,"��̨�����й����̶�ʮ����֮һ���Ƕ���ĩ���ŵ��꣨��������ʦѧ����������ʩ��������֮�����������1860�������ʷ��");
        }
    }

    //for(i=0; i<G.vexnum; i++){
    //    printf("\n����%d\n",G.vertices[i].info.popularity);
    //}
    //printf("����%s\n",G.vertices[1].info.introduction);
    //printf("����%d\n",G.vertices[2].info.popularity);
}

#endif // CREATGRAPH_H_INCLUDED
