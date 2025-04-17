#include"stdio.h"
#include"stdlib.h"
#define VTXUNM 8 /*n为图中顶点个数的最大可能值*/
struct arcnode{ 
	int adjvex;
	int data;
	struct arcnode *nextarc;
	}; 
typedef struct arcnode ARCNODE;

struct headnode{
	int vexdata;
	ARCNODE *firstarc;
	};
		
struct headnode G[VTXUNM+1];
int visited[VTXUNM+1];

struct headnode *creatgp(int d[],int n)   //返回顺序存储空间首地址
{
struct headnode *head;
ARCNODE*p;
int k,m;
int v;
head=(struct headnode*)malloc((n+1)*sizeof(struct headnode));//建立顺序存储空for(k=1;k<=n;k++)

for(k=1;k<=n;k++){
  	(head+k)->vexdata=d[k];
  	(head+k)->firstarc=NULL;
	printf("inputlinked listof %d:\n",d[k]);
	scanf("%d,%d",&m,&v);
	while(m>0)
	{
		p=(ARCNODE*)malloc(sizeof(ARCNODE));//建第R，k-I，….. 1个邻接表 
		p->adjvex=m; p->data=v;
		p->nextarc=(head+k)->firstarc;
		(head+k)->firstarc=p;
		scanf("%d,%d",&m,&v);
	}
	}
return(head);
}


void dfs(struct headnode G[],int v)
{ARCNODE*p;
printf("%d->",G[v].vexdata);
visited[v]=1;
p=G[v].firstarc;
while(p!=NULL)//*当邻接点存在时
{if(visited[p->adjvex]==0)
	dfs(G,p->adjvex);
p=p->nextarc;//*找下一邻接点
}
};

//深度优先遍历 
void bfs(struct headnode G[],int v)
{
int queue[VTXUNM];
int front,rear;
front=VTXUNM-1,rear=VTXUNM-1;
ARCNODE*p;
printf("%d->",G[v].vexdata);
visited[v]=1;
rear=(rear+1)%VTXUNM;
queue[rear]=v;//*访问过的顶点进队列/
while(rear!=front)
{front=(front+1)%VTXUNM;
	v=queue[front];
	p=G[v].firstarc;
	while(p!=NULL)
	 {if(visited[p->adjvex]==0)
	 {printf("%d->",G[p->adjvex].vexdata);
	 	visited[p->adjvex]=1;
		 rear=(rear+1)%VTXUNM;
		 queue[rear]=p->adjvex;}
		p=p->nextarc;}
 }
}
//广度优先遍历


 
void traver(struct headnode G[])
{int v;
for(v=1;v<=VTXUNM;v++)
	visited[v]=0;
for(v=1;v<=VTXUNM;v++)
	if (visited[v]==0) dfs(G,v);
	printf("\b\b \n");
	
for(v=1;v<=VTXUNM;v++)
	visited[v]=0;
	
for(v=1;v<=VTXUNM;v++)
	if(visited[v]==0) bfs(G,v);
	printf("\b\b \n");
};
//自定义traver函数

 
main(){
	struct headnode *t;
	int point[9]={0,1,2,3,4,5,6,7,8};
	t=creatgp(point,VTXUNM);
	traver(t);//函数嵌套，进行深度广度优先遍历 
}
