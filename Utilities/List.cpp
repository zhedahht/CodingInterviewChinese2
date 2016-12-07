/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;

        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}