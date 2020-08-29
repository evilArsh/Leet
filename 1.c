#include<stdlib.h>
#include<math.h>
#include<stdio.h>
struct ListNode {
   int val;
   struct ListNode *next;
  };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 struct ListNode *tmp;
    struct ListNode *node=NULL;
    struct ListNode *out;
    int lVal=0,rVal=0,left=0,all;
	if(l1->val==0&&!l1->next){
        return l2;
    }else if(l2->val==0&&!l2->next){
        return l1;
    }else{
    tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
    out=tmp;
    while((l1!=NULL)||(l2!=NULL)){
        rVal=0;
        lVal=0;
        if(l1!=NULL){
            lVal=l1->val;
        }
        if(l2!=NULL){
            rVal=l2->val;
        }
		all=lVal+rVal;
		node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=(all+left)%10;
        left=(all+left)/10;
        tmp->next=node;
        tmp=node;
		if(l1&&l1->next)
			l1=l1->next;
		else l1=NULL;
		if(l2&&l2->next)
			l2=l2->next;
		else 
			l2=NULL;
    }
    if(left!=0){
		node=(struct ListNode*)malloc(sizeof(struct ListNode));
		node->val=left;
        tmp->next=node;
		node->next=NULL;
	}
	else 
        tmp->next=NULL;
    out=out->next;
	return out;
    
    /*length=lLV>rLV?log10(lLV/10):log10(rLV/10);
    tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
    out=tmp;
    for(;length>=0;length--){
        all=(lVal/(int)pow(10,length))%10+(rVal/(int)pow(10,length))%10;
        node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=all%10+left;
        left=all/10;
        tmp->next=node;
        tmp=node;
    }
    if(left!=0){
		node=(struct ListNode*)malloc(sizeof(struct ListNode));
		node->val=left;
        tmp->next=node;
		node->next=NULL;
	}
	else 
        tmp->next=NULL;
    out=out->next;
    return out;*/
}
}
#define L 9
#define R 9
void main(){
	int i,j,k,l;
	int a[L]={0,8,6,5,6,8,3,5,7};
	int b[R]={6,7,8,0,8,5,8,9,7};
	struct ListNode* l1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* l2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tmp1;
	struct ListNode* tmp2;
	struct ListNode* result;
	tmp1=l1;
	tmp2=l2;
	for(i=0;i<L;i++){
		n1=(struct ListNode*)malloc(sizeof(struct ListNode));
		n1->val=a[i];
		tmp1->next=n1;
		tmp1=n1;
		n1->next=NULL;

	}
	for(i=0;i<R;i++){		
		n2=(struct ListNode*)malloc(sizeof(struct ListNode));		
		n2->val=b[i];		
		tmp2->next=n2;	
		tmp2=n2;		
		n2->next=NULL;
	}
	l1=l1->next;
	l2=l2->next;
	result=addTwoNumbers(l1,l2);
	while(result){
		printf("%d  ",result->val);
		result=result->next;
	}

}


