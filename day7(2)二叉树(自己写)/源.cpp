#include "fun.h"
//�ݹ�ʵ��
//abdhiejcfg
//ǰ�������������ȱ�����
void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->data);//�ȼ���visit����
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//�������
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->data);//�ȼ���visit����
		InOrder(p->rchild);
	}
}
//�������
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->data);//�ȼ���visit����
	}
}
//��������ǵݹ�
void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S);//��ʼ��ջ
	BiTree p = T;//�м��������
	while (p|| !StackEmpty(S))
	{
		if (p)//��һ���ڵ㲻Ϊ�վ�ѹջȻ��ȡ��������
		{
			Push(S, p);
			p = p->lchild;
		}
		else//Ϊ�վ͵�����ǰԪ�ز��Ҵ�ӡȻ����ȡ�����Һ���
		{
			Pop(S, p);
			putchar(p->data);
			p = p->rchild;
		}
	}
}
//��α�����������ȱ�����
void LeverOrder2(BiTree T)
{
	LinkQueue Q;//���츨������
	InitQueue(Q);//��ʼ������
	BiTree p;//�м����
	EnQueue(Q, T);//�������
	while (!IsEmpty(Q))
	{
		DenQueue(Q, p);//���ӵ�ǰ�ڵ�,������ӻ���ѳ��ӵĵ�ַ��p���Կ����ҵ��������Һ���
		putchar(p->data);
		if (p->lchild != NULL)//�������
		{
			EnQueue(Q, p->lchild);
		}
		if (p->rchild != NULL)//����Һ���
		{
			EnQueue(Q, p->rchild);
		}
	}



}
int main()
{
	BiTree tree = NULL;//����
	BiTree pnew;//ÿ���½�Ҫ����λ��
	//������Ҫ����Ҫ�����������У������Ǹ������г�ʼ��
	ptag_t phead = NULL, ptail = NULL;//����ͷָ��Ͷ���βָ��
	ptag_t listpnew;
	ptag_t pcur=NULL;//listpnew�������������������Ժ�Ž����е�ָ��,��Ϊѡ�񲻶�ͷָ��
	//���б�����ѡ����pcur������
	char c;//��������Ҫ�洢������
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')//�ų��������
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//���½ڵ�����ռ�
		pnew->data = c;//�����Ž�ȥ
		//���ĸ����Ҫ����������ռ䣬����ͬ������
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;//�����������������Ԫ�ؾ���pnew�ĵ�ַ���������㶨��Ҫ������listpnewȥ�����ĵ�ַ
		if (NULL == tree)//һ��ʼ������û�е�ʱ��
		{
			tree = pnew;//�ѵ�һ�νӽ�������������������
			phead = listpnew;
			ptail = listpnew;//��Ϊһ��ʼ����ɶҲû����һ�������Ļ����Ƕ�ͷҲ�Ƕ�β
			pcur = listpnew;//��Ȼ���������ߵ�ָ��Ҳֻ��ָ�������һ������
			continue;
		}
		//��Ϊ�������Ľ���Ҫͨ����������ȥʵ�֣������Ȳ������У��ٽ��ж������Ĺ���
		else//�����������û������������Ļ����Ǿ͸��ݶ�βָ��ȥ�ж�,ͬʱpcurҲ�����ƶ�
		{
			ptail->pnext = listpnew;//���ö���ǰһ��Ԫ�صĺ��ָ��ָ��������Ԫ��
			ptail = listpnew;//����βָ��ʼ��ָ��������Ԫ����Ϊ��β�巨����������һ���Ƕ��е����һ��
		}
		//���и��������ڶԶ��������в���
		if (NULL == pcur->p->lchild)//����ʼ���ǿ�ǰһ��Ԫ�ص�������ȿ������ٿ��ֺ���
		{
			pcur->p->lchild = pnew;//����nullû�еĻ��Ǿ�������ֱ�ӷŹ�ȥ������
		}
		else if (NULL == pcur->p->rchild)//������Һ���Ϊ�յĻ��ͷŵ��ֺ�������
		{
			pcur->p->rchild = pnew;
			//��Ҫ
			pcur = pcur->pnext;//������ߵ������ô˵�����Ԫ�ص����Һ��Ӷ����ˣ��Ǿ�Ҫ��ָ����ǰ����һλ����������
		}
	}
	printf("--------ǰ�����----------\n");
	preOrder(tree);
	cout << endl;
	printf("--------�������----------\n");
	InOrder(tree);
	cout << endl;
	printf("--------�������----------\n");
	PostOrder(tree);
	cout << endl;
	printf("--------��������ǵݹ�----------\n");
	InOrder2(tree);
	cout << endl;
	printf("--------��α���----------\n");
	LeverOrder2(tree);
	cout << endl;
}
