#include "fun.h"
//�������
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}
//�ݹ����
int BST_Insert(BiTree& T, KeyType k)
{
	if (NULL == T)
	{	//Ϊ�½ڵ�����ռ䣬��һ�������Ϊ����
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;//�������ɹ�
	}
	else if (k == T->key)
		return 0;//������ͬԪ�أ��Ͳ�����
	else if (k < T->key)//���Ҫ����Ľ�㣬С�ڵ�ǰ���
		return BST_Insert(T->lchild, k);//�������ý��������Ӻ�ԭ���ĸ��׻��������
	else
		return BST_Insert(T->rchild, k);
}
//��������������
void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);//��ĳһ����������������
		i++;
	}
}
//�������û�ж���������ɾ������--������û��ô��
void DeleteNode(BiTree& root, KeyType x) {
	if (root == NULL) {
		return;
	}
	if (root->key > x) {
		DeleteNode(root->lchild, x);
	}
	else if (root->key < x) {
		DeleteNode(root->rchild, x);
	}
	else { //���ҵ���ɾ���ڵ�
		if (root->lchild == NULL) { //������Ϊ�գ�������ֱ�Ӷ���ȥ
			BiTree tempNode = root;//����ʱ�Ĵ��ŵ�Ŀ����һ��Ҫfree
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) { //������Ϊ�գ�������ֱ�Ӷ���ȥ
			BiTree tempNode = root;//��ʱָ��
			root = root->lchild;
			free(tempNode);
		}
		else {  //������������Ϊ��
		   //һ���ɾ����������������������� �� ����������С���� ����Ҫɾ���Ľڵ�(������ò����������������������)
			BiTree tempNode = root->lchild;
			if (tempNode->rchild != NULL) {
				tempNode = tempNode->rchild;
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild, tempNode->key);
		}
	}
}
//����Ҫ�õ�
int compare(const void* left, const void* right)//left��right����������Ԫ�صĵ�ֵַ
{
	return *(KeyType*)left - *(KeyType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//�Ӵ�С
}
//�ݹ�Ѷ�������ֵ��ֵ������
void InOrder1(BiTree T, KeyType str[], int& post)
{
	if (T != NULL)
	{
		InOrder1(T->lchild, str, post);
		//printf("%3d", T->key);
		str[post] = T->key;
		post++;
		InOrder1(T->rchild, str, post);
	}
}
//���ֲ���
int Binary_Search(KeyType str[], KeyType key, int n)//�������Ҫ�ҵ�����,�������鳤��
{
	int low = 0, high = n - 1,mid;
	while (low<=high)
	{
		mid = (high + low) / 2;
		if (str[mid] == key)
			return mid;//�ҵ���
		else if (str[mid] >key)
		{
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
}
int main()
{
	BiTree T = NULL;//����
	BiTree parent;//�洢���׽��ĵ�ֵַ
	BiTree search;
	KeyType str[] = { 87, 7, 60, 80, 59 ,34 ,86, 99 ,21 , 3 };
	KeyType str1[10] = { 0 };
	Creat_BST(T, str, 10);
	//InOrder(T);
	//cout << endl;
	qsort(str1, 10, sizeof(KeyType), compare);//qsortʵ�ֵ��ǿ���
	//����
	int post = 0;
	InOrder1(T, str1,post);
	for (int i = 0; i < 10; i++)
	{
		//cout << str1[i] << " ";
		printf("%3d", str1[i]);
	}
	cout << endl;
	int target;
	//cout<< "������������ҵ�����:";
	//cin >> target;
	//cout<<"��Ҫ�ҵ����ֵ�λ����:"<<Binary_Search(str1, target, 10)<<endl;
	cout << Binary_Search(str1, 21, 10);
}