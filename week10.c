#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

int len = 0; //��� ����
float sum = 0;

// Ʈ���� ��� ���� ����
typedef struct treeNode {
	int data;              // ������ �ʵ�
	struct treeNode* left; // ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode* right;// ������ ���� Ʈ���� ���� ��ũ �ʵ�
} treeNode;

// data�� ��Ʈ ����� ������ �ʵ�� �Ͽ� ���ʰ� ������ ���� Ʈ���� �����ϴ� ����
treeNode* addNewNode(int data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

//��� ���� ���
int count_node(treeNode* ptr)
{
	int cnt = 0;

	if (ptr != NULL)
		cnt = 1 + count_node(ptr->left) + count_node(ptr->right);
	return cnt;
}

//����
int cnt_num = 0;
treeNode* treeInsert(treeNode* root, int key)
{
	cnt_num += 1;
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
	treeNode* parent, *p, *succ, *succ_parent;
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
			if (parent->left == p) 
				parent->left = NULL;
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
		while (succ->left != NULL) { // ������ ����Ʈ������ �İ��� ã��
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent->right == succ)  succ_parent->right = succ->right;
		else succ_parent->left = succ->right;
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

//���� ��� ����
void cal_ipl(treeNode* root, int depth)
{
	sum += 1;

	if (root->left != NULL) {
		cal_ipl(root->left, depth+1);
		sum += depth;
	}

	if (root->right != NULL) {
		cal_ipl(root->right, depth+1);
		sum += depth;
	}
}

//����� �� ����
int haspathsum(treeNode *root, int pathsum)
{
	if (root == NULL)
		return 0;

	else
	{
		int path = 0;
		int temp = pathsum - root->data;
		if (temp == 0 && root->left == NULL && root->right == NULL)
			return 1;

		if (root->left != NULL)
			path = (path || haspathsum(root->left, temp));

		if (root->right != NULL)
			path = (path || haspathsum(root->right, temp));

		return path;
	}
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
	printf("4. ���� ��� ���� \n");
	printf("5. ��� �˻� ���� \n");
	printf("6. ������ȸ \n");
	printf("7. ����� ���� �ִ��� �˻� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	int choice;
	int num = 0;
	int key;
	int del;
	int depth = 1;
	int pathsum;
	int bol;
	treeNode* search = NULL;

	treeNode* m7 = addNewNode(55, NULL, NULL);
	treeNode* m6 = addNewNode(35, NULL, NULL);
	treeNode* m5 = addNewNode(25, NULL, NULL);
	treeNode* m4 = addNewNode(15, NULL, NULL);
	treeNode* m3 = addNewNode(40, m6, m7);
	treeNode* m2 = addNewNode(20, m4, m5);
	treeNode* m1 = addNewNode(30, m2, m3);
	treeNode* root = m1;

	//               30
	//           /        \
	//         20         40
	//       /     \    /     \
	//      15     25  35      55

	len = count_node(root);

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
			inorder(root);
			printf("\n");
			printf("%d�� �� \n", cnt_num);
			cnt_num = 0;
			break;

		case 2:
			printf("������ ��� �Է� : ");
			scanf("%d", &del);
			deleteNode(root, del);
			len -= 1;
			inorder(root);
			printf("\n");
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
			cal_ipl(root, depth);
			printf("���� ��� ���� : %.1f \n", sum);
			sum = 0;
			break;

		case 5:
			cal_ipl(root, depth);
			printf("��� �˻� ���� : %.1f \n", sum / len);
			sum = 0;
			break;

		case 6:
			inorder(root);
			printf("\n");
			break;

		case 7:
			printf("�˻��� �� �Է� : ");
			scanf("%d", &pathsum);
			if (haspathsum(root, pathsum)!=NULL)
				printf("�߰��Ͽ����ϴ�. \n");
			else
				printf("�߰����� ���Ͽ����ϴ�. \n");
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}