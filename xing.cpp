//链式栈的进栈、出栈算法
#include<stdio.h>
#include<malloc.h>
#define len sizeof(stnode)
typedef struct node                                //list为头结点指针，link为结点,node为结点
{
	int data;
    struct node *link;
}stnode,*stlink;
void initialslink(stlink &top)         //堆栈初始化
{
	top=NULL;
}
int empty(stlink top)
{
	return (top==NULL);         //判断top是否为空         ,返回一个值
}
int push(stlink &top,int item)
{
	stlink p=(stlink)malloc(len);
	if(!p)        //空间未申请成功
		return 0;
	else
	{
		p->data=item;         //将item送入新节点的数据域
		p->link=top;               //将top送入新节点的指针域
		top=p;                //修改栈顶指针top的指向
		return 1;          //插入成功
	}
}
int pop(stlink &top,int &item)
{ 
	stlink p;
    p=top;
    if(empty(p))                 
    { 
		printf("栈已空！\n");
        return 0;
    }
    else 
	{
       item=p->data;          //保存被删结点的数据信息
	   top=top->link;          //后移
       free(p);
       return 1; 
	}
} 
void show(stlink &top)               
{
	stlink p=top;
	while(p!=NULL)                                       //NULL必须要大写
	{
		printf("%d\t",p->data);
		p=p->link;
	}
	printf("\n");
}

void main()
{
     int item;                      //item为要插入的数
	 int i,n,x;
	 stlink top;       //定义top指针
	 initialslink(top);           //初始化堆栈
	 printf("请输入堆栈长度:\n");
	 scanf("%d",&n);
     printf("请输入要插入数:\n");
	 for(i=0;i<n;i++)
	 {
	   scanf("%d",&item);
       push(top,item);
	 }

     printf("输出堆栈中的数据:\n");
	 show(top);
	 
     printf("输出堆栈中的数据:\n");
     for(i=0;i<n;i++)
	 {
	    pop(top,x);
		printf("%d\t",x);
	 }
	 printf("\n");
}


	 














