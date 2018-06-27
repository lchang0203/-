#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include "DataStructure.h"

void searchWord(ALGraph G){
    int i=0;
    Node searchnode[MAX_VERTEX_NUM];
    char word[50];

    printf("������Ҫ���ҵĹؼ��֣�\n");
    scanf("%s",word);
    for(i=0;i<G.vexnum;i++){
        searchnode[i].info.popularity=G.vertices[i].info.popularity;
        searchnode[i].info.roadnum=G.vertices[i].info.roadnum;
        strcpy(searchnode[i].name,G.vertices[i].name);
        strcpy(searchnode[i].info.introduction,G.vertices[i].info.introduction);
    }
    for(i=0;i<G.vexnum;i++){
            if(strstr(searchnode[i].name,word)!=NULL){
                printf("��Ҫ���ҵľ���Ϊ��%s\n",searchnode[i].name);
                printf("�������Ϊ��%s\n",searchnode[i].info.introduction);
            }
            else if(strstr(searchnode[i].info.introduction,word)!=NULL){
                printf("��Ҫ���ҵľ���Ϊ��%s\n",searchnode[i].name);
                printf("�������Ϊ��%s\n",searchnode[i].info.introduction);
            }
            //else
            //    printf("δ�ҵ�Ҫ���ҵĹؼ���\n");
    }
}

#endif // SEARCH_H_INCLUDED
