#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<string.h>
#include <string>
#include<stdlib.h>
using namespace std;
#define MaxSize 50
typedef int ElemType;
//��̬����
typedef struct {
	ElemType data[MaxSize];
	int lenth;//��ǰ˳����Ԫ�ظ���
}Sqlist;
//����Ԫ�غ���
bool ListInser(Sqlist& L, int post, ElemType e)
{
	if (post<1 || post>L.lenth + 1)//�ж�Ҫ�����λ���Ƿ�Ϸ�
		return false;
	if (L.lenth > MaxSize)//�����ռ���
		return false;
	for (int j = L.lenth; j >= post; j--)//������Ԫ�ؿ�ʼ����ƶ�Ԫ��post��λ��
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[post - 1] = e;//�ڳ���λ�ø�e
	L.lenth++;//����+1
	return true;
}
//��ӡ˳���
void PrintList(Sqlist& L)
{
	for (int i = 0; i < L.lenth; i++)
	{
		printf("%3d", L.data[i]);//����Ԫ�ش�ӡ��һ��
	}
	cout << endl;
}
//ɾ��Ԫ�غ���
bool ListDel(Sqlist& L, int post, ElemType& e)
{
	if (post<1 || post>L.lenth)//ɾ��λ�ò��Ϸ�,lenth���û����е�λ��
		return false;
	if (L.lenth == 0)//����û��Ԫ�أ�����ɾ��
		return false;
	e = L.data[post - 1];//��Ҫɾ��Ԫ�����ó���
	//�ó����Ժ��ٰѺ����Ԫ��һ����ǰ��
	for (int j = post; j < L.lenth; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.lenth--;//��ĳ���-1
	return true;

}
//ɾ��Ԫ�غ���
int LocalElem(Sqlist& L, ElemType e)
{
	for (int i = 0; i < L.lenth; i++)//��������
	{
		if (L.data[i] == e)
			return i + 1;//����ҵ��˾ͷ���λ��(��0��ʼ���ظ��û��ӽ�Ҫ+1)��
	}
	return 0;//�Ҳ����ͻ᷵�����
}
/*
��ʼ��˳���˳�����Ԫ��Ϊ���ͣ�����ߵ�Ԫ����1,2,3��
Ȼ��ͨ��scanf��ȡһ��Ԫ�أ�����������6�������뵽��2��λ�ã�
��ӡ���˳���ÿ��Ԫ��ռ3���ո񣬸�ʽΪ1  6  2  3��
Ȼ��scanf��ȡһ������������ɾ����λ�ã���������Ϊ1����
Ȼ�����˳���  6  2  3�����������λ�ò��Ϸ������false�ַ���
*/
int main()
{
	Sqlist L;//����һ��˳���
	bool ret;//�鿴����ֵ���Ƿ�ɾ���ɹ���
	ElemType del;//������Ҫɾ����Ԫ��
	//����˳����ǿյģ�����װ�㶫��
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.lenth = 3;
	//ojʵ��
	int temp;//Ҫ���������
	cin >> temp;
	ret = ListInser(L, 2, temp);
	PrintList(L);
	int del_post;//Ҫɾ��������
	cin >> del_post;
	ret = ListDel(L, del_post, del);
	if (ret)
	{
		//cout << "����ɹ�" << endl;
		PrintList(L);
	}
	else
	{
		cout << "false" << endl;
		//PrintList(L);
	}
	 
	//����ɾ��
	//ret = ListDel(L, 1,del);
	//if (ret)
	//{
	//	cout << "ɾ���ɹ�" << endl;
	//	printf("ɾ����Ԫ����%d\n", del);
	//	PrintList(L);
	//}
	//else
	//{
	//	cout << "ɾ��ʧ��" << endl;
	//	//PrintList(L);
	//}

	//���Բ���Ԫ��
	//int elem_post;//�������Ԫ���ڱ��λ��
	//elem_post = LocalElem(L, 7);//����������շ��ص�λ��
	//if (elem_post)//���ط�0������
	//{
	//	cout << "���ҳɹ�" << endl;
	//	cout << "Ԫ��λ��Ϊ:" <<elem_post<< endl;

	//}
	//else
	//{
	//	cout << "����ʧ��" << endl;
	//}
	return 0;

}