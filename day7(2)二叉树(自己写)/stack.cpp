#include "fun.h"
void InitStack(SqStack& S)
{
	S.top = -1;
}
//��ջ
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)
	{
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
//��ջ
bool Pop(SqStack& S, ElemType& x)
{
	if (-1 == S.top)
		return false;
	x = S.data[S.top--];
	return true;
}
//�ж��Ƿ�Ϊ��
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}