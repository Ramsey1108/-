#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;
//Ū����������һ�¿����ǲ���ÿ�ζ������򣬱����ɺ���
void ST_Init(SSTable &ST,int len)//����ռ䣬���������������
{
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}
//��ӡ
void ST_print(SSTable ST)
{
	for (int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//����Ԫ��
 void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}
//��������
void AdjustDown1(ElemType A[], int k, int len)
{
	int dad = k;
	int son = 2 * dad + 1; //�����±�(��ʽ)
	while (son <= len)
	{
		if (son + 1 <= len && A[son] < A[son + 1])//������û���Һ��ӣ��Ƚ����Һ���ѡ���
		{
			son++;//����Һ��ӱ����Ӵ��Ǿ�ѡ��ģ�son++����ѡ���Һ�����
		}
		if (A[son] > A[dad])//�ȽϺ��Ӻ͸��ף�������ӱȸ��״󣬽�����Ȼ���ٰѽ������ٵ���Ϊ�����
		{
			swap(A[son], A[dad]);
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort1(ElemType A[], int len)
{
	int i;
	//�����󶥶�
	for (i = len / 2; i >= 0; i--)//���һ�����׵��±�=len / 2 ����ʽ�������ģ�
	{
		AdjustDown1(A, i, len);
	}
	swap(A[0], A[len]);//�����������������һ��Ԫ��

	for (i = len - 1; i > 0; i--)//���ﴫ���е㲻̫������
	{
		AdjustDown1(A, 0, i);//ʣ��Ԫ�ص���Ϊ����ѣ����ﴫ0����Ϊ��ͨ�����˵����½���
		swap(A[0], A[i]);
	}
}
//ѡ�������Լ�д���Լ�дʧ��....
void SelectSort(ElemType A[], int len)
{
	int i, j, min;//min������С���ֵ��±�
	for ( i = 0; i < len-1; i++)//����iȡlen-1����Ϊ�ڲ�j = i+1�Ϳ��ԱȽϵ����һ��Ԫ�غ͵����ڶ�Ԫ����
	{
		min = i;//�ݴ�һ�¿�ͷ��Ԫ��
		for ( j = i+1; j < len; j++)//i���������ģ���������i�ұ���С��
		{
			if (A[j] < A[min])
				min = j;//��С���±괫��ȥ
		}
		if (min != i)//��Ҫ��С�Ĳ��Ǳ�������������ұ��Ǹ��ģ��ǾͰ���С�Ļ�����
			swap(A[i], A[min]);
	}
}
int main()
{
	ElemType A[10] = { 12 ,63, 58 ,95 ,41, 35 ,65 , 0, 38 ,44 };
	SSTable ST;
	HeapSort1(A, 9);
	//SelectSort(A, 10);
	//ST_Init(ST, 10);//��ʼ��
	//memcpy(A, ST.elem, sizeof(50));
	//ST_print(ST);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", A[i]);
	}
	cout << endl;
	SelectSort(A, 10);
	//ST_print(ST);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", A[i]);
	}
	//cout << endl;
}