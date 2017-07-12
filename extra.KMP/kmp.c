#include<stdio.h>
#include<stdlib.h>
#define MAX 256
typedef struct{
	char base[MAX];
	int length;
}str;
void get_next(str* p,int *next){
	int i=0,j=-1;
	next[0]=-1;
	while(i<p->length){
		if(j==-1||p->base[i]==p->base[j]){
			j++;
			i++;
			if(p->base[i]!=p->base[j])
				next[i]=j;
			else{
				next[i]=next[j];
			}
		}else{
			j=next[j];
		}
	}
}
void KMP_str(str* st,str *p,int *next){
	int i=-1,j=-1;
	while(i<st->length&&j<p->length){
		if((j==-1)||(st->base[i]==p->base[j])){
			j++;
			i++;
		}else{
			j=next[j];
		}
	}
	if(j>=p->length){
		printf("matched at pos %d\n",i-p->length);
	}
	else{
		printf("no matched\n");
	}

}
void getStr(str *p){
	char tmp;
	p->length=0;
	while(scanf("%c",&tmp)==1&&tmp!='*'){
		p->base[p->length]=tmp;
		p->length++;
	}
	p->base[p->length]='\0';
}
void main(){
	int i=0;
	str* st=(str*)malloc(sizeof(str));
	str* pattern=(str*)malloc(sizeof(str));
	int* next=0;
	printf("input orginal string:\n");
	getStr(st);
	getchar();
	printf("input parrern:\n");
	getStr(pattern);
	next=(int*)malloc(sizeof(int)*(pattern->length+1));
	get_next(pattern,next);
	KMP_str(st,pattern,next);

}