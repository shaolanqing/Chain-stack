//��ʽջ�Ľ�ջ����ջ�㷨
#include<stdio.h>
#include<malloc.h>
#define len sizeof(stnode)
typedef struct node                                //listΪͷ���ָ�룬linkΪ���,nodeΪ���
{
	int data;
    struct node *link;
}stnode,*stlink;
void initialslink(stlink &top)         //��ջ��ʼ��
{
	top=NULL;
}
int empty(stlink top)
{
	return (top==NULL);         //�ж�top�Ƿ�Ϊ��         ,����һ��ֵ
}
int push(stlink &top,int item)
{
	stlink p=(stlink)malloc(len);
	if(!p)        //�ռ�δ����ɹ�
		return 0;
	else
	{
		p->data=item;         //��item�����½ڵ��������
		p->link=top;               //��top�����½ڵ��ָ����
		top=p;                //�޸�ջ��ָ��top��ָ��
		return 1;          //����ɹ�
	}
}
int pop(stlink &top,int &item)
{ 
	stlink p;
    p=top;
    if(empty(p))                 
    { 
		printf("ջ�ѿգ�\n");
        return 0;
    }
    else 
	{
       item=p->data;          //���汻ɾ����������Ϣ
	   top=top->link;          //����
       free(p);
       return 1; 
	}
} 
void show(stlink &top)               
{
	stlink p=top;
	while(p!=NULL)                                       //NULL����Ҫ��д
	{
		printf("%d\t",p->data);
		p=p->link;
	}
	printf("\n");
}

void main()
{
     int item;                      //itemΪҪ�������
	 int i,n,x;
	 stlink top;       //����topָ��
	 initialslink(top);           //��ʼ����ջ
	 printf("�������ջ����:\n");
	 scanf("%d",&n);
     printf("������Ҫ������:\n");
	 for(i=0;i<n;i++)
	 {
	   scanf("%d",&item);
       push(top,item);
	 }

     printf("�����ջ�е�����:\n");
	 show(top);
	 
     printf("�����ջ�е�����:\n");
     for(i=0;i<n;i++)
	 {
	    pop(top,x);
		printf("%d\t",x);
	 }
	 printf("\n");
}


	 














