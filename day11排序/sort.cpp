#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;//�洢Ԫ�ص���ʼ��ַ
	int TableLen;//Ԫ�ظ���
}SSTable;
//��ʼ�������������
void ST_Init(SSTable& ST, int len)
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//��������ɣ�ÿһ��ִ�д���ͻ�õ������10��Ԫ��
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//���ɵ���0-99֮��
	}
}
//��ӡ����
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//������������
void swap1(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//ð������(��С����)
void BubbleSort(ElemType A[], int n)
{
	int i, j;
	bool Flag;
	for (i = 0; i < n - 1; i++)//�����ƶ��ٸ�����
	{
		Flag = true;
		for (j = n - 1; j > i; j--)//�ڲ���ƱȽϵ�����
		{
			if (A[j - 1] > A[j])
			{
				swap1(A[j - 1], A[j]);
				Flag = false;
			}
		}
		if (Flag)
		{
			break;
		}
	}
}
//����Ҫ�õĻ���
int Partition(int* arr, int left, int right)
{
	int k, i;
	for (i = k = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			swap1(arr[i], arr[k]);
			k++;
		}
	}
	swap1(arr[k], arr[right]);
	return k;
}
//�ݹ�ʵ�ֿ���
void QuickSort(ElemType A[], int low, int high)
{
	if (low < high)//�ֶ���֮˼��
	{
		int positive = Partition(A, low, high);
		QuickSort(A, low, positive - 1);
		QuickSort(A, positive + 1, high);
	}
}
int main()
{
	SSTable T;
	ST_Init(T, 10);
	ST_print(T);
	//BubbleSort(T.elem, T.TableLen);
	QuickSort(T.elem, 0, T.TableLen-1);//�����������±��ֵ
	ST_print(T);
}