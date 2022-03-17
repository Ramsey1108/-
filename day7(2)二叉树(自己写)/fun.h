#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//���� ����ѵ��Ӫ ����
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;//c�����鼮�ϵ�data
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

typedef struct tag {
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag* pnext;
}tag_t, * ptag_t;

//ջ��������ݽṹ
#define MaxSize 50
typedef BiTree ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
//������ؽṹ
//���е�������ݽṹ
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
//ջ�ĺ�������
void InitStack(SqStack& S);
bool Push(SqStack& S, ElemType x);
bool Pop(SqStack& S, ElemType& x);
bool StackEmpty(SqStack& S);
//���еĺ�������
void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
bool DenQueue(LinkQueue& Q, ElemType& e);
void EnQueue(LinkQueue& Q, ElemType x);