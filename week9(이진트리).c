#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

// 트리의 노드 구조 정의
typedef struct treeNode {
	int data;              // 데이터 필드
	struct treeNode* left; // 왼쪽 서브 트리에 대한 링크 필드
	struct treeNode* right;// 오른쪽 서브 트리에 대한 링크 필드
} treeNode;

// data를 루트 노드의 데이터 필드로 하여 왼쪽과 오른쪽 서브 트리를 연결하는 연산
treeNode* addNewNode(int data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

//노드 개수 계산
int count_node(treeNode* ptr)
{
	int cnt = 0;

	if (ptr != NULL)
		cnt = 1 + count_node(ptr->left) + count_node(ptr->right);
	return cnt;
}

//높이 계산
int get_height(treeNode* ptr)
{
	int height = 0;

	if (ptr != NULL)
		height = 1 + max(get_height(ptr->left), get_height(ptr->right));
	return height;
}

//중위순회
void inorder(treeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);            //왼쪽 하위 트리 출력
		printf("[%d] ", root->data);    //부모노드출력
		inorder(root->right);           //오른쪽 하위 트리 출력
	}
}

//두 이진트리 동일한지 판별
int equal_tree(treeNode* p1, treeNode* p2)
{
	//p1 p2 둘 다 null이면서 p1 p2가 존재하고 p1 p2데이터의 값이 같고 재귀적으로 이러한 조건이 다 맞으면 참을 리턴 아니면 거짓을 리턴
	return ((p1==NULL && p2==NULL)) || (p1 && p2 &&(p1->data == p2->data)
		&& equal_tree(p1->left, p2->left) && equal_tree(p1->right, p2->right));
}

//동일한 이진트리 생성
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

//이진검색트리 판별
int determine_b_tree(treeNode *ptr, int min, int max)
{
	//이진검색트리 비었을 때
	if (ptr == NULL)
		return 1;

	//이진검색트리 최대, 최소 위반 시
	if (ptr->data < min || ptr->data > max)
		return 0;

	//하위 트리 재귀적으로 검색
	//왼쪽 노드 검사 시 상위 노드 max로 잡고 max보다 크면 false리턴
	//오른쪽 노드 검사 시 상위 노드 min으로 잡고 min보다 작으면 false 리턴
	return determine_b_tree(ptr->left, min, ptr->data-1) && determine_b_tree(ptr->right, ptr->data+1, max);
}

int deter_b_tree(treeNode *ptr)
{
	return determine_b_tree(ptr, INT_MIN, INT_MAX);
}

void menu()
{
	printf("==========================================\n");
	printf("1. 노드 개수 계산 \n");
	printf("2. 이진트리 높이 계산 \n");
	printf("3. 중위순회 \n");
	printf("4. 이진트리 동일한지 판단 \n");
	printf("5. 동일한 이진트리 생성 \n");
	printf("6. 이진검색트리인지 판별 \n");
	printf("0. 종료 \n");
	printf("==========================================\n");
}

int main(void)
{
	printf("--------------<이진 트리>--------------\n \n");
	//T1  이진검색트리 아님
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

	//T2   이진검색트리
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

	//T3   이진검색트리 아님
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
		printf("메뉴 선택: ");
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
				printf("동일성 False \n");
			else
				printf("동일성 True \n");

			printf("<T1 | T2> \n");
			if (equal_tree(T1, T2) == 0)
				printf("동일성 False \n");
			else
				printf("동일성 True \n");

			printf("<T2 | T3> \n");
			if (equal_tree(T2, T3) == 0)
				printf("동일성 False \n");
			else
				printf("동일성 True \n");
			break;

			//--------------(5)---------------
		case 5:
			printf("복사할 트리 입력(1=T1, 2=T2, 3=T3) : ");
			scanf("%d", &copy);

			if (copy == 1) {
				T4 = copy_tree(T1);
				inorder(T4);
				printf("\n");
				if (equal_tree(T1, T4) == 0)
					printf("동일성 False \n");
				else
					printf("동일성 True \n");
			}

			if (copy == 2) {
				T4 = copy_tree(T2);
				inorder(T4);
				printf("\n");
				if (equal_tree(T2, T4) == 0)
					printf("동일성 False \n");
				else
					printf("동일성 True \n");
			}

			if (copy == 3) {
				T4 = copy_tree(T3);
				inorder(T4);
				printf("\n");
				if (equal_tree(T3, T4) == 0)
					printf("동일성 False \n");
				else
					printf("동일성 True \n");
			}
			break;

			//--------------(6)---------------
		case 6:
			printf("판별할 트리 입력(1=T1, 2=T2, 3=T3) : ");
			scanf("%d", &d);

			if (d == 1) {
				if (deter_b_tree(T1))
					printf("이진검색트리 True \n");
				else
					printf("이진검색트리 False \n");
			}

			if (d == 2) {
				if (deter_b_tree(T2))
					printf("이진검색트리 True \n");
				else
					printf("이진검색트리 False \n");
			}

			if (d == 3) {
				if (deter_b_tree(T3))
					printf("이진검색트리 True \n");
				else
					printf("이진검색트리 False \n");
			}

			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}