#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link
{
	int data;
	struct link *next;
};

int main()
{
	int	i = 0;                
	char	c;		
	struct link * head = NULL;	  /* 链表头指针 */	
	printf("Do you want to append a new node(Y/N)?");
	scanf(" %c",&c);	           /* %c前面有一个空格 */
	while (c=='Y' || c=='y')
	{				
		head = AppendNode(head);/* 向head为头指针的链表末尾添加节点 */
		DisplyNode(head);        /* 显示当前链表中的各节点信息 */
		printf("Do you want to append a new node(Y/N)?");
		scanf(" %c",&c);	      /* %c前面有一个空格 */
	      i++;                       
	}	
	printf("%d new nodes have been apended!\n", i);	
	DeleteMemory(head);           /* 释放所有动态分配的内存 */
	return 0;
}
/* 函数功能：新建一个节点并添加到链表末尾，返回添加节点后的链表的头指针 */
struct link *AppendNode(struct link *head)
{
	struct link *p = NULL, *pr = head;	
	int	data;
	p = (struct link *)malloc(sizeof(struct link)); /* 让p指向新建节点 */
	if (p == NULL)                 /* 若为新建节点申请内存失败，则退出程序 */
	{
		printf("No enough memory to allocate!\n");
		exit(0);						
	}	
	if (head == NULL) 	           /* 若原链表为空表 */
	{				
		head = p; 		           /* 将新建节点置为头节点 */
	}
	else                  	           /* 若原链表为非空，则将新建节点添加到表尾 */
	{		
		while (pr->next != NULL)/* 若未到表尾，则移动pr直到pr指向表尾 */
		{
			pr = pr->next;     /* 让pr指向下一个节点 */
		}
		pr->next = p; 	          /* 让末节点的指针域指向新建节点 */
	}
	printf("Input node data:");
	scanf("%d", &data);        	 /* 输入节点数据 */
	p->data = data;              /* 将新建节点的数据域赋值为输入的节点数据值 */ 
	p->next = NULL;			 /* 将新建节点置为表尾 */	
	return head;               	 /* 返回添加节点后的链表的头指针 */
}
/* 	函数的功能：显示链表中所有节点的节点号和该节点中数据项内容 */
void DisplyNode(struct link *head)
{
	struct link *p = head;
	int	j = 1;
	while (p != NULL)            /* 若不是表尾，则循环打印节点的值 */
	{
		printf("%5d%10d\n", j, p->data);/* 打印第j个节点的数据 */
		p = p->next;             /* 让p指向下一个节点 */
		j++;
	}                            
}
/*	函数功能：释放head指向的链表中所有节点占用的内存 */
void DeleteMemory(struct link *head)
{
	struct link *p = head, *pr = NULL;
	while (p != NULL)           	/* 若不是表尾，则释放节点占用的内存 */
	{	
		pr = p;                  	/* 在pr中保存当前节点的指针 */
		p = p->next;            	/* 让p指向下一个节点 */
		free(pr);                	/* 释放pr指向的当前节点占用的内存 */
	}            
}
