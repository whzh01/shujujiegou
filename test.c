
#include "stdio.h"
#include "string.h"
#include <stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
}Node;
//插入节点
void AddToTail(Node **pHead,int value)
{
	Node* pNode;
	//创建一块新的空间存放节点内容，然后连接到链表中
	Node* pNew =  malloc(sizeof(Node));
	pNew->val = value;
	pNew->next = NULL;
	if(*pHead == NULL)
	{
		//如果指针为空
		*pHead = pNew;	
	}else
	{
		//如果指针不为空
		pNode = *pHead;
		while(pNode->next != NULL)
		{
			pNode = pNode->next;
		}
		pNode->next = pNew;
	}
}
void addNode(Node **nodeHead,int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if(*nodeHead == NULL)
    {
        *nodeHead = newNode;
        return ;
    }
    Node *curNode = *nodeHead;
    while(curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = newNode;
}
void showNode(Node *nodeHead)
{
    Node* curNode = nodeHead;
    while(curNode != NULL)
    {
        printf("%d\n",curNode->val);
        curNode = curNode->next;
    }
}
int main()
{
    Node *nodeHead = NULL;
    addNode(&nodeHead,12);
    addNode(&nodeHead,123);
    addNode(&nodeHead,1234);
    addNode(&nodeHead,12345);
    addNode(&nodeHead,123456);
    AddToTail(&nodeHead,1234567);
    AddToTail(&nodeHead,12345678);
    showNode(nodeHead);
    system("pause");
}


