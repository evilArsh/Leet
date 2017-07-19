#include<stdio.h>
#include<stdlib.h>
#define MAX 64
//邻接信息
typedef struct arcNode{
	int index;
	int weight;//权重
	struct arcNode* next;//下一个指针
}node,*ptrArcNode;
//
typedef struct vertexNode{
	char vertex;
	node* first;
}vertexNode,*ptrVertexNode;
typedef struct {
	vertexNode vNode[MAX];
	int vNum,aNum;
}graph;
int LocateVertix(graph g,char vertex){
	int i;
	for(i=0;i<g.vNum;i++){
		if(g.vNode[i].vertex==vertex)
			return i;
	}
	return -1;
}
void InitialGraph(graph* G){
	int l,m,i;
	char first,end;
	node* p1,*p2;
	printf("input the amount of vertex and arc:\n");
	scanf("%d%d",&G->vNum,&G->aNum);
	getchar();//空格
	printf("input %d vertex :\n",G->vNum);
	for(i=0;i<G->vNum;i++){
		scanf("%c",&G->vNode[i].vertex);
		G->vNode[i].first=NULL;
	}
	printf("%d arc :\n",G->aNum);
	getchar();//空格
	for(i=0;i<G->aNum;i++){
		printf("\ninput first and ended vertex:");
		scanf("%c%c",&first,&end);
		getchar();//空格
		if((l=LocateVertix(*G,first))!=-1&&(m=LocateVertix(*G,end))!=-1){
			//无向图
			p1=(node*)malloc(sizeof(node));
			p1->index=m;
			p1->next=NULL;
			p1->next=G->vNode[l].first;
			G->vNode[l].first=p1;

			p2=(node*)malloc(sizeof(node));
			p2->index=l;
			p2->next=NULL;
			p2->next=G->vNode[m].first;
			G->vNode[m].first=p2;
		}

	}
}
int main(){
	graph *G=(graph*)malloc(sizeof(graph));
	InitialGraph(G);
	return 0;
}