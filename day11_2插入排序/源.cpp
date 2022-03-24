#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;//����ָ��
	int TableLen;
}SSTable;
void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len + 1;//ʵ������11��Ԫ�صĿռ�
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//�����11���������ǵ�һ��Ԫ����û���õ���
	}
}
void ST_print(SSTable ST)
{
	for (int i = 1; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//�������򣬴�С������������
void InsertSort(ElemType A[], int n)
{
	int i, j;
	//24 66 94  2 15 74 28 51 22 18  2
	for (i = 2; i <= n; i++)//�����Ԫ�����ڱ����ӵڶ���Ԫ�ؿ�ʼ�ã���ǰ�����
	{
		if (A[i] < A[i - 1])//���������һ����ǰ��һ��Ԫ��С
		{
			A[0] = A[i];//�ھͰѺ����Ԫ�طŵ��ڱ�����ȥ
			for (j = i - 1; A[0] < A[j]; --j)//�������Ǹ�����Ѿ�����ıȣ�������Ҫ�����Ԫ�ر�������ĳһ��Ԫ��ҪС��ʱ��
				A[j + 1] = A[j];//�ܰ�����������ÿһ��Ԫ�ظ�Ҫ����Ҫ�صıȣ�����������󸲸�
			A[j + 1] = A[0];//�ݵ��˳�ѭ����ʱ��j�պ�ָ��û�б�Ҫ����Ԫ���������ٴ��Ԫ���ˣ������и��ظ�
			//��Ԫ�ز����˱��� [2] 1 3 3 4 5 6 7 ��ʱ��Ͱ�2���뵽��һ��3���ֵ�λ��
		}
	}
}
//��������
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//ѡ������
void SelectSort(ElemType A[], int n)
{
	int i, j, min;//��¼��С�������±�
	for ( i = 0; i < n-1; i++)
	{
		min = i;
		for ( j = i+1; j < n; j++)
		{
			if (A[j]<A[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			swap(A[i], A[min]);
		}
	}
}
int main()
{
	SSTable T;
	ST_Init(T, 10);
	//ST_print(T);
	//BubbleSort(T.elem, T.TableLen);
	int a[] = { 12 ,63, 58, 95, 41 ,35, 65,  0 ,38, 44 };
	//T.elem = a;
	//InsertSort(a, 10);//�����������±��ֵ
	//ST_print(T);
	SelectSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
}