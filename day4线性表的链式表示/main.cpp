#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType data;//
	struct LNode* next;//ָ����һ�ڵ�
}LNode, * LinkList;
//ͷ�巨����������
LinkList CreatList1(LinkList& L)//����ָ��
{
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//����ռ����ͷ��������
	L->next = NULL;//ͷ���û����
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//����һ���ռ�����������s
		s->data = x;//������ֵ�Ž�x
		s->next = L->next;//�ȴӺ����޸�ָ��
		L->next = s;//ͷ���ָ���½�����x
		cin >> x;
	}
	return L;
}
//β�巨����������
LinkList CreatList2(LinkList& L)//����ָ��
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ռ����ͷ��������
	LNode* s, * r = L;//r�����βָ�룬����L����Ϊ��Ū���ñ���r����
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));//����һ���ռ�����������s
		s->data = x;//������ֵ�Ž�x
		r->next = s;
		r = s;//rָ���½����ĵط�
		cin >> x;
	}
	r->next = NULL;//���ѱ�λָ�븳ֵnull��Ȼ����ж�null��ʱ������ɷǷ�����
	return L;
}
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
		/*if (L != NULL)
		{
			printf(" ");
		}*/
	}
	printf("\n");
}
//ͨ��λ�ò���Ԫ�ص�ֵ
LinkList LlemGet(LinkList L, int i)//i��Ҫ���ҵ�λ��
{
	int j = 1;
	LinkList p = L->next;//һ��ʼ��ָ���һ��Ԫ�ض�����ͷָ��
	if (0 == i)
	{
		return L;//��0������ͷָ��
	}
	if (i < 1)
	{
		return NULL;//��С��1�ľ�����
	}
	while (p && j < i)//������λ�ñ���3
	{
		p = p->next;//�Ҹ�ָ�������ƶ����α���Ŷ�
		j++;
	}
	return p;
}
//ͨ��Ԫ�ز���λ��
LinkList LocalElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}
//����i��λ�ò���Ԫ��
bool ListFrontInser(LinkList L, int i, ElemType e)//Ҫ���������λ�ã�����ֵ
{
	LinkList p = LlemGet(L, i - 1);//�ҵ�i-1��λ��
	if (NULL == p)
	{
		return false;//iԽ����
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));//���½ڵ�����ռ�
	s->data = e;//��Ҫ�����ֵ�Ž�ȥ
	s->next = p->next;//�����½ڵ�ָ������
	p->next = s;//�����½ڵ�ǰ���ָ������
	return true;
}
//ɾ����i��λ���ϵ�Ԫ��
bool ListDelete(LinkList L, int i)
{
	LinkList p = LlemGet(L, i - 1);//�õ���i-1�Ľڵ�
	if (NULL == p) 
	{
		return false;
	}
	LinkList q = p->next;//����һ��qȥָ��Ҫɾ���Ľڵ�
	p->next = q->next;//��ɾ��Ԫ�ص�ǰ��ָ��ɾ��Ԫ�صĺ��
	free(q);	
	q = NULL;
	return true;
}
int main()
{
	LinkList L;
	LinkList search;//�����ҵ�λ�õĽڵ�
	/*CreatList1(L);
	PrintList(L);*/
	CreatList2(L);
	//PrintList(L);
	/*search = LlemGet(L, 3);
	if (search != NULL)
	{
		cout << "����Ų��ҳɹ�" << endl;
		cout << "Ԫ����:" << search->data;
	}*/
	LinkList temp=LlemGet(L, 2);
	cout << temp->data<<endl;
	ListFrontInser(L, 2, 99);//�ٵڶ���λ�ò���878
	PrintList(L);
	ListDelete(L, 4);//ɾ��������ĸ�Ԫ��
	PrintList(L);

}