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
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
// �ڿӷ�����������ʹ�õķ������������Ϊ�ָ�ֵ
int Partition1(ElemType A[], int low, int high)
{
	ElemType pivot = A[low];//������ߵ�ֵ�ݴ�����
	while (low < high)
	{
		while (low < high && A[high] >= pivot)

		{
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
		{
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
//�ݹ�ʵ�ֿ���
void QuickSort(ElemType A[], int low, int high)
{
	if (low < high)//�ֶ���֮˼��
	{
		int positive = Partition1(A, low, high);
		QuickSort(A, low, positive - 1);
		QuickSort(A, positive + 1, high);
	}
}
//�۰���� �������򣬿��ĺ���
void MidInsertSort(ElemType A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1; high = i - 1;//low�������еĿ�ʼ��high�������е����
		while (low <= high)//��ͨ�����ֲ����ҵ�������λ��
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			A[j + 1] = A[j];
		A[high + 1] = A[0];
	}
}
//�Լ���
void MidInsertSort1(ElemType A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];//�ڱ�Ԫ��
		low = 1; high = i - 1;//��Ϊ0���ڱ�Ԫ������low��1��ʼ��high��n-1������ԭ��
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			A[j + 1] = A[j];
		A[j + 1] = A[0];

	}
}
int main()
{
	SSTable ST;
	ElemType A[] = { 0,64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	//QuickSort(A, 0, 9);
	MidInsertSort1(A, 10);
	for (int i = 0; i < 11; i++)
	{
		printf("%3d", A[i]);
	}
	printf("\n");
}