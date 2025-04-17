#include "stdio.h"
#include"stdlib.h" 
struct node{     //结构体类型的定义
	int xi;
	int zhi; 
	struct node *next;};
typedef struct node NODE;

NODE *creatlink(char c) //链表的正向创建
{
NODE *head,*p,*s;
int x,z;
printf("Input Poly %c, end with 0 e\n",c);
head=(NODE*)malloc(sizeof(NODE));
scanf("%d%d",&x,&z);
  p=head;
while(x!=0||z!=0)
{s=(NODE*)malloc(sizeof(NODE)); 
s->xi=x;
s->zhi=z;
p->next=s;
	p=s;
scanf("%d%d",&x,&z);}
p->next=NULL;
printf("successful set!!");
return head;
}

void del(NODE *head,int i) //链表结点的影除
{
	NODE *p,*s;
	int j=0;
	p=head;
while((p->next!=NULL)&&(j<i-1))
	{p=p->next;
  	j++;} 
if((p->next==NULL)||(j>i-1))
	printf("i的值不合法！\n");
else
{s=p->next;
p->next=s->next;
free(s);}
}

void hebing(NODE *head1,NODE *head2) //将第二个链表合并于第一个链表
{
	NODE *q1,*q2;
int n=1;
if(head2->next!=NULL)
{
	q2=head2->next;
	while(q2!=NULL)
		{q1=head1->next;
		while(q1!=NULL)
		{
			if(q1->zhi==q2->zhi)
			{q1->xi=q1->xi+q2->xi;
			del(head2,n);
			q2=head2;
			n=0;
			break;}
        q1=q1->next;
      }
	q2=q2->next;
	n++;
		}
	}
}

void lianjie(NODE *head1,NODE *head2) //将第二个多项式链接到第一个多项式
{ 
	NODE *q1,*q2;
	q1=head1;
	while(q1!=NULL) q2=q1->next;
	if(head2->next!=NULL)q1->next=head2->next;} 
void del0(NODE *head) //删除链表中系数为0的项
{
	NODE *q1,*q2;
	q1=head; 
	while(q1!=NULL)
	{if(q1->next!=NULL)q2=q1->next;
	if(q1->next!=NULL&& q2->xi==0)
		{q1->next=q2->next;free(q2);break;} 
	q1=q1->next;} 
}
	
void show(NODE *head) //显示链表
{	
NODE *q;
printf("The combined poly:\n");
q=head->next;
	while(q!=NULL)
	{
	printf("%d*x(%d)",q->xi,q->zhi);
	q=q->next;
	}
	printf("\n\n");
} 
main() //主函数
{
	NODE *head1,*head2;
	char A,B;
	head1=creatlink('A');  //创建第一个链表
	head2=creatlink('B'); //创建第二个链表
hebing(head1,head2); //将第二个链表台并于第一个链表
lianjie(head1,head2);//将第二个多项式链接到第一个多项式
	free(head2);//将第二个多项式头结点删院
	del0(head1); //删除链表中系数为0的项
	show(head1); //显示第一个链表的结果
}
