#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

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

//���� ���
int get_height(treeNode* ptr)
{
	int height = 0;

	if (ptr != NULL)
		height = 1 + max(get_height(ptr->left), get_height(ptr->right));
	return height;
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

//�� ����Ʈ�� �������� �Ǻ�
int equal_tree(treeNode* p1, treeNode* p2)
{
	//p1 p2 �� �� null�̸鼭 p1 p2�� �����ϰ� p1 p2�������� ���� ���� ��������� �̷��� ������ �� ������ ���� ���� �ƴϸ� ������ ����
	return ((p1==NULL && p2==NULL)) || (p1 && p2 &&(p1->data == p2->data)
		&& equal_tree(p1->left, p2->left) && equal_tree(p1->right, p2->right));
}

//������ ����Ʈ�� ����
treeNode* copy_tree(treeNode* ptr)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	if (ptr!=NULL)
	{
		root->left = copy_tree(ptr->left);
		root->right = copy_tree(ptr->right);
		root->data = ptr->data;
		return root;
	}
	return NULL;
}

//�����˻�Ʈ�� �Ǻ�
int determine_b_tree(treeNode *ptr, int min, int max)
{
	//�����˻�Ʈ�� ����� ��
	if (ptr == NULL)
		return 1;

	//�����˻�Ʈ�� �ִ�, �ּ� ���� ��
	if (ptr->data < min || ptr->data > max)
		return 0;

	//���� Ʈ�� ��������� �˻�
	//���� ��� �˻� �� ���� ��� max�� ��� max���� ũ�� false����
	//������ ��� �˻� �� ���� ��� min���� ��� min���� ������ false ����
	return determine_b_tree(ptr->left, min, ptr->data-1) && determine_b_tree(ptr->right, ptr->data+1, max);
}

int deter_b_tree(treeNode *ptr)
{
	return determine_b_tree(ptr, INT_MIN, INT_MAX);
}

void menu()
{
	printf("==========================================\n");
	printf("1. ��� ���� ��� \n");
	printf("2. ����Ʈ�� ���� ��� \n");
	printf("3. ������ȸ \n");
	printf("4. ����Ʈ�� �������� �Ǵ� \n");
	printf("5. ������ ����Ʈ�� ���� \n");
	printf("6. �����˻�Ʈ������ �Ǻ� \n");
	printf("0. ���� \n");
	printf("==========================================\n");
}

int main(void)
{
	printf("--------------<���� Ʈ��>--------------\n \n");
	//T1  �����˻�Ʈ�� �ƴ�
	treeNode* n8 = addNewNode(42, NULL, NULL);
	treeNode* n7 = addNewNode(30, NULL, NULL);
	treeNode* n6 = addNewNode(55, n8, NULL);
	treeNode* n5 = addNewNode(15, n7, NULL);
	treeNode* n4 = addNewNode(2, NULL, NULL);
	treeNode* n3 = addNewNode(10, NULL, n6);
	treeNode* n2 = addNewNode(16, n4, n5);
	treeNode* n1 = addNewNode(22, n2, n3);
	treeNode* T1 = n1;

	//               22
	//            /      \
	//          16        10
	//        /    \        \
	//       2     15        55
	//            /         /
	//           30        42

	//T2   �����˻�Ʈ��
	treeNode* m9 = addNewNode(41, NULL, NULL);
	treeNode* m8 = addNewNode(42, m9, NULL);
	treeNode* m7 = addNewNode(18, NULL, NULL);
	treeNode* m6 = addNewNode(55, m8, NULL);
	treeNode* m5 = addNewNode(20, m7, NULL);
	treeNode* m4 = addNewNode(2, NULL, NULL);
	treeNode* m3 = addNewNode(36, NULL, m6);
	treeNode* m2 = addNewNode(16, m4, m5);
	treeNode* m1 = addNewNode(22, m2, m3);
	treeNode* T2 = m1;

	//               22
	//            /     \
	//           16       36
	//         /   \       \
	//        2    20       55
	//            /         /
	//           18        42 
	//                     /
	//                    41 

	//T3   �����˻�Ʈ�� �ƴ�
	treeNode* p8 = addNewNode(42, NULL, NULL);
	treeNode* p7 = addNewNode(18, NULL, p8);
	treeNode* p6 = addNewNode(55, NULL, NULL);
	treeNode* p5 = addNewNode(20, p7, NULL);
	treeNode* p4 = addNewNode(2, NULL, NULL);
	treeNode* p3 = addNewNode(36, NULL, p6);
	treeNode* p2 = addNewNode(16, p4, p5);
	treeNode* p1 = addNewNode(30, p2, p3);
	treeNode* T3 = p1;

	//               30
    //            /     \
	//           16       36
	//         /   \       \
	//        2    20       55
	//            /         
	//           18         
	//            \
	//             42

	treeNode* T4;

	int choice;
	int copy;
	int equal;
	int determine;
	int d;
	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
			//--------------(1)---------------
		case 1:
			printf("T1 : %d \n", count_node(T1));
			printf("T2 : %d \n", count_node(T2));
			printf("T3 : %d \n", count_node(T3));
			break;

			//--------------(2)---------------
		case 2:
			printf("T1 : %d \n", get_height(T1));
			printf("T2 : %d \n", get_height(T2));
			printf("T3 : %d \n", get_height(T3));
			break;

			//--------------(3)---------------
		case 3:
			printf("T1 : ");
			inorder(T1);
			printf("\n");

			printf("T2 : ");
			inorder(T2);
			printf("\n");

			printf("T3 : ");
			inorder(T3);
			printf("\n");
			break;

			//--------------(4)---------------
		case 4:
			printf("<T1 | T3> \n");
			if (equal_tree(T1, T3) == 0)
				printf("���ϼ� False \n");
			else
				printf("���ϼ� True \n");

			printf("<T1 | T2> \n");
			if (equal_tree(T1, T2) == 0)
				printf("���ϼ� False \n");
			else
				printf("���ϼ� True \n");

			printf("<T2 | T3> \n");
			if (equal_tree(T2, T3) == 0)
				printf("���ϼ� False \n");
			else
				printf("���ϼ� True \n");
			break;

			//--------------(5)---------------
		case 5:
			printf("������ Ʈ�� �Է�(1=T1, 2=T2, 3=T3) : ");
			scanf("%d", &copy);

			if (copy == 1) {
				T4 = copy_tree(T1);
				inorder(T4);
				printf("\n");
				if (equal_tree(T1, T4) == 0)
					printf("���ϼ� False \n");
				else
					printf("���ϼ� True \n");
			}

			if (copy == 2) {
				T4 = copy_tree(T2);
				inorder(T4);
				printf("\n");
				if (equal_tree(T2, T4) == 0)
					printf("���ϼ� False \n");
				else
					printf("���ϼ� True \n");
			}

			if (copy == 3) {
				T4 = copy_tree(T3);
				inorder(T4);
				printf("\n");
				if (equal_tree(T3, T4) == 0)
					printf("���ϼ� False \n");
				else
					printf("���ϼ� True \n");
			}
			break;

			//--------------(6)---------------
		case 6:
			printf("�Ǻ��� Ʈ�� �Է�(1=T1, 2=T2, 3=T3) : ");
			scanf("%d", &d);

			if (d == 1) {
				if (deter_b_tree(T1))
					printf("�����˻�Ʈ�� True \n");
				else
					printf("�����˻�Ʈ�� False \n");
			}

			if (d == 2) {
				if (deter_b_tree(T2))
					printf("�����˻�Ʈ�� True \n");
				else
					printf("�����˻�Ʈ�� False \n");
			}

			if (d == 3) {
				if (deter_b_tree(T3))
					printf("�����˻�Ʈ�� True \n");
				else
					printf("�����˻�Ʈ�� False \n");
			}

			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}