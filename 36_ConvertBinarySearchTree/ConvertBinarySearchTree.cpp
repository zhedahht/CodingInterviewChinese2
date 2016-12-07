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

// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。

#include <cstdio>
#include "..\Utilities\BinaryTree.h"

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    // pLastNodeInList指向双向链表的尾结点，
    // 我们需要返回头结点
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == nullptr)
        return;

    BinaryTreeNode *pCurrent = pNode;

    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    pCurrent->m_pLeft = *pLastNodeInList; 
    if(*pLastNodeInList != nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != nullptr)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

// ====================测试代码====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pRight == nullptr)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pLeft == nullptr)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void Test(char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    PrintTree(pRootOfTree);

    BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyList(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// 树中没有结点
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

