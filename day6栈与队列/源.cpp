#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MaxSize 5
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;
//��ʼ��ջ
void InitStack(SqStack& S) //Ҫ�ı�ջ����������Ҫ��ȡ��ַ
{
	S.top = -1;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return true;
	}
	return false;
}
//��ջ
bool push(SqStack& S, ElemType e)
{
	if (S.top == MaxSize - 1)//ջ��
	{
		return false;
	}
	S.data[++S.top] = e;
	return true;
}
//��ȡջ��Ԫ��
bool GetTop(SqStack S, ElemType& m)//ȡ��ַm����Ϊ�õ���mҪ���ݳ�ȥ
{
	if (StackEmpty(S))//ջ�ǿյľ�ûջ��Ԫ����
	{
		return false;
	}
	m = S.data[S.top];
	return true;
}
//����ջ��Ԫ��
bool Pop(SqStack& S, ElemType& m)
{
	if (StackEmpty(S))//ջ�ǿյľ�ûջ��Ԫ����
	{
		return false;
	}
	m = S.data[S.top];
	S.top--;
	return true;
}