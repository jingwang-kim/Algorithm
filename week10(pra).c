#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

int len = 0; //��� ����

// Ʈ���� ��� ���� ����
typedef struct treeNode {
	int data;              // ������ �ʵ�
	struct treeNode* left; // ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode* right;// ������ ���� Ʈ���� ���� ��ũ �ʵ�
} treeNode;

//����
treeNode* treeInsert(treeNode* root, int key)
{
	if (root == NULL)
	{
		root = (treeNode*)malloc(sizeof(treeNode));
		root->data = key;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (key < root->data)
		root->left = treeInsert(root->left, key);
	
	else
		root->right = treeInsert(root->right, key);
		
	return root;
}

//����
void deleteNode(treeNode* root, int key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->data != key)) {  // ������ ����� ��ġ Ž��
		parent = p;
		if (key < p->data) p = p->left;
		else p = p->right;
	}

	// ������ ��尡 ���� ���
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) { // ���� ����Ʈ������ �İ��� ã��
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)  succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->data = succ->data;
		p = succ;
	}
	free(p);
}

//�˻�
treeNode* treeSearch(treeNode* root, int key)
{
	if (root == NULL) {
		return NULL;
	}

	if (root->data == key)
		return root;

	if (key < root->data)
		return treeSearch(root->left, key);
	else
		return treeSearch(root->right, key);
}

//��� �˻� ����
int count = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int cal_ipl(treeNode* root)
{
	treeNode* temp = root;
	if (temp->left != NULL || temp->right != NULL)
	{
		count1 += cal_ipl(temp->left);
		count2 += cal_ipl(temp->right);

		if (count1 > count2)
			count3 = count1;
		else
			count3 = count2;

		count += count3;
		return (count + 1);
	}

	if (temp->left == NULL && temp->right == NULL)
		return 1;

	else if (root == NULL)
		return 0;

	return (count ++);
}


//������ȸ
void inorder(treeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);            //���� ���� Ʈ�� ���
		printf("[%d] ", root->data);    //�θ������
		inorder(root->right);           //������ ���� Ʈ�� ���
	}
}

//�޴�
void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ��� ���� \n");
	printf("2. ��� ���� \n");
	printf("3. Ű �� �˻� \n");
	printf("4. ��� �˻� ���� \n");
	printf("5. ������ȸ \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	int choice;
	int num=0;
	int key;
	int del;
	int ipl;
	treeNode* root = NULL;
	treeNode* search = NULL;

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("������ ��� �Է� : ");
			scanf("%d", &num);
			root = treeInsert(root, num);
			len += 1;
			break;

		case 2:
			printf("������ ��� �Է� : ");
			scanf("%d", &del);
			deleteNode(root, del);
			len -= 1;
			break;

		case 3:
			printf("�˻��� ��� �Է� : ");
			scanf("%d", &key);
			if (treeSearch(root, key) != NULL)
				printf("�߰��Ͽ����ϴ�. \n");
			else
				printf("�߰����� ���Ͽ����ϴ�. \n");
			break;

		case 4:
			ipl = cal_ipl(root);
			printf("��� �˻� ���� : %d \n", ipl);
			count = 0;
			count1 = 0;
			count2 = 0;
			count3 = 0;
			break;

		case 5:
			inorder(root);
			printf("\n");
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}