#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
	int m_Value;
	struct ListNode* m_pNext;
}ListNode;
void AddToTail(ListNode **pHead,int value);//插入节点
void RemoveTail(ListNode **pHead,int value);//删除含有某个值的节点
struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k);//删除倒数第N个节点之后的链表
struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k);//删除倒数第N个节点之后的链表
ListNode* Merge(ListNode *pHead1,ListNode *pHead2);//合并两个有序链表 
void Lianbiao_Reverse(ListNode **l);//链表反转
//插入节点
void AddToTail(ListNode **pHead,int value)
{
	ListNode* pNode;
	//创建一块新的空间存放节点内容，然后连接到链表中
	ListNode* pNew =  malloc(sizeof(ListNode));
	pNew->m_Value = value;
	pNew->m_pNext = NULL;
	if(*pHead == NULL)
	{
		//如果指针为空
		*pHead = pNew;	
	}else
	{
		//如果指针不为空
		pNode = *pHead;
		while(pNode->m_pNext != NULL)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
};
//删除含有某个值的节点
void RemoveTail(ListNode **pHead,int value)
{
	ListNode *pTailToDelete = NULL;
	ListNode *pNode = NULL;
	if((pHead == NULL) || (*pHead == NULL))
	{
		return;
	}
	//单独处理头节点
	if(((*pHead)->m_Value == value))
	{
		pTailToDelete = *pHead;
		*pHead = (*pHead)->m_pNext;
	}else
	{
		//开始遍历
		pNode = *pHead;
		while((pNode->m_pNext != NULL) && (pNode->m_pNext->m_Value != value))
		{
			pNode = pNode->m_pNext;
		}
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_Value == value)
		{
			//将节点从链表中剔除
			pTailToDelete = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if(pTailToDelete != NULL)
	{
		free(pTailToDelete);
		pTailToDelete = NULL;
	}
}
/***
*删除倒数第N个节点之后的链表
*
*/
struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k) {
        struct ListNode *curNode;
        long int cnt = k;
        curNode = pListHead;
        if((pListHead == NULL) || (cnt <1))
        {
            return NULL;
        }
        while(curNode != NULL)
        {
            cnt--;
            curNode  = curNode->m_pNext; 
        }
        if(cnt == 0)
        {
            return pListHead;
        }
        if(cnt <0)
        { 
            curNode = pListHead;
            while(++cnt != 0)
            {
                curNode = curNode->m_pNext;//find the Node n;
            }
            curNode->m_pNext=NULL;
			return pListHead;
            
        }
        return NULL;
    
};
/**
 *合并两个有序链表 
 */
ListNode* Merge(ListNode *pHead1,ListNode *pHead2)
{
	ListNode *pMergeHead = NULL;
	//Judge that if the list is null 
	if(pHead1 == NULL)
	{
		return pHead2;
	}else if(pHead2 == NULL)
	{
		return pHead1;
	}
	if(pHead1->m_Value<pHead2->m_Value)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge(pHead1->m_pNext,pHead2);
	}else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
	}
	return pMergeHead;
}
/***
*链表反转
*
*/
void Lianbiao_Reverse(ListNode **l)
{
	ListNode *prv;
	ListNode *tmp;
	ListNode *cur;
	cur = *l;
	prv = NULL;
	if(cur == NULL)
	{
		return;
	}
	while(cur->m_pNext != NULL)
	{
		tmp = cur->m_pNext;
		cur->m_pNext = prv;
		prv = cur;
		cur = tmp;
	}
}

int main()
{
	ListNode *pHead=NULL;
	ListNode *pNode = NULL;
	AddToTail(&pHead,0x2);
	AddToTail(&pHead,0x22);
	AddToTail(&pHead,0x23);
	AddToTail(&pHead,0x26);
	pNode = pHead;
	while(pNode != NULL)
	{
		printf("%x\n",pNode->m_Value);
		pNode = pNode->m_pNext;
	}
    printf("Lianbiao Reverse:");
    Lianbiao_Reverse(&pHead);
    pNode = pHead;
	while(pNode != NULL)
	{
		printf("%x\n",pNode->m_Value);
		pNode = pNode->m_pNext;
	}
    printf("Delete 22\n");
	RemoveTail(&pHead,0x22);
	pNode = pHead;
	while(pNode != NULL)
	{
		printf("%x\n",pNode->m_Value);
		pNode = pNode->m_pNext;
	}
    system("pause");
}