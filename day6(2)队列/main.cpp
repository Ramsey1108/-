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
	typedef struct {
		ElemType data[MaxSize];//����洢MaxSize-1��Ԫ��
		int front, rear;//����ͷ������β
	}SqQueue;
	//��ʼ������
	void InitQueue(SqQueue& Q)
	{
		Q.front = 0;
		Q.rear = 0;
	}
	//�ж϶����Ƿ�Ϊ��
	bool IsEmpty(SqQueue Q)//ֻ���жϲ���ı�
	{
		if (Q.front == Q.rear)
		{
			return true;
		}
		return false;
	}
	//���
	bool EnQueue(SqQueue& Q, ElemType e)
	{
		if ((Q.rear + 1) % MaxSize == Q.front)//�ж��Ƿ������
		{
			return false;
		}
		Q.data[Q.rear] = e;//�Ŷ�β
		Q.rear = (Q.rear + 1) % MaxSize;//������Ҫ+1
		//����ȡ��ֻҪ������maxsize���ͻ��ڱ�����ֵ�����һ����ж�+1���Ƿ����ͷָ���غ�
		return true;
	}
	//����
	bool DenQueue(SqQueue& Q, ElemType& e)
	{
		if (IsEmpty(Q))
		{
			return false;
		}
		e = Q.data[Q.front];
		Q.front = (Q.front + 1) % MaxSize;
		return true;
	}
	int main()
	{
		//���е�
		SqQueue Q;
		bool ret;
		ElemType e;//�洢����Ԫ��
		InitQueue(Q);
		//ջ��
		SqStack S;
		ElemType m;//������ȡ��ȡ����ջ��Ԫ��;
		bool Flag;
		InitStack(S);
		//����ʵ��
		ElemType temp3;
		//��ʼʵ��ջ��
		for (int i = 0; i < 3; i++)
		{
			cin >> temp3;
			push(S, temp3);
		}
		ElemType x;//������ȡ�񵯳�����ջ��Ԫ��;
		for (int i = 0; i < 3; i++)
		{
			Pop(S, x);
			printf("%2d", x);
		}
		cout << endl;
		//��ʼʵ�ֶ��е�
		ElemType temp2;
		for (int i = 0; i < MaxSize; i++)
		{
			
			cin >> temp2;
			ret=EnQueue(Q, temp2);
			if (!ret)
			{
				cout << "false" << endl;
			}
		}
		//����
		ElemType temp1;
		for (int i = 0; i < MaxSize-1; i++)
		{
			DenQueue(Q, temp1);
			printf("%2d", temp1);
		}
		cout << endl;
		return 0;
	}