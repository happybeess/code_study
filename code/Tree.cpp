#include"stdio.h"
#include"stdlib.h"

struct btnode
{	int d;
	struct btnode *Ichild;
	struct btnode *rchild;
}; 

struct btnode *creatbt( struct btnode *bt, int k) //生成二叉树
{	int b;
	struct btnode	*p,*t;
	printf("输入数据：");
	scanf("%d",&b);
	if (b!=0)
	{p=(struct btnode*)malloc(sizeof(struct btnode));
	p->d=b;	p->Ichild=NULL;	p->rchild=NULL;
	if(k==0) t=p;
	if(k==1) bt->Ichild=p;
	if(k==2) bt->rchild=p;
	creatbt(p,1);
	creatbt(p,2);} 
	return(t);
} 
void pretrav(struct btnode *bt)
{ 	if(bt!=NULL)
{	printf("%5d",bt->d);
	pretrav(bt->Ichild);
	pretrav(bt->rchild);
}
}
void intrav(struct btnode *bt)
{	if(bt!=NULL)
{	intrav(bt->Ichild);
	printf("%5d",bt->d);
	intrav(bt->rchild);
}
}

void postrav(struct btnode *bt)
{if(bt!=NULL)
{	postrav(bt->Ichild);
	postrav(bt->rchild);
	printf("%5d",bt->d);
}
}
main(){
struct btnode *bt;
int k=0;
bt=NULL;
bt=creatbt(bt,k);
printf("前序遍历：\n");
pretrav(bt);
printf("\n中序遍历：\n");
intrav(bt);
printf("\n后序遍历：\n");
postrav(bt);
}
