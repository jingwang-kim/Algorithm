#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

int len = 0; //노드 개수
float sum = 0;

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

//삽입
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

//삭제
void deleteNode(treeNode* root, int key) {
	treeNode* parent, *p, *succ, *succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->data != key)) {  // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->data) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) 
				parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우 
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->left != NULL) { // 오른쪽 서브트리에서 후계자 찾기
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

//검색
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

//내부 경로 길이
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

//경로의 합 측정
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

//메뉴
void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 노드 삽입 \n");
	printf("2. 노드 삭제 \n");
	printf("3. 키 값 검색 \n");
	printf("4. 내부 경로 길이 \n");
	printf("5. 평균 검색 성능 \n");
	printf("6. 중위순회 \n");
	printf("7. 경로의 합이 있는지 검색 \n");
	printf("0. 종료 \n");
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
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("삽입할 노드 입력 : ");
			scanf("%d", &num);
			root = treeInsert(root, num);
			len += 1;
			inorder(root);
			printf("\n");
			printf("%d번 비교 \n", cnt_num);
			cnt_num = 0;
			break;

		case 2:
			printf("삭제할 노드 입력 : ");
			scanf("%d", &del);
			deleteNode(root, del);
			len -= 1;
			inorder(root);
			printf("\n");
			break;

		case 3:
			printf("검색할 노드 입력 : ");
			scanf("%d", &key);
			if (treeSearch(root, key) != NULL)
				printf("발견하였습니다. \n");
			else
				printf("발견하지 못하였습니다. \n");
			break;

		case 4:
			cal_ipl(root, depth);
			printf("내부 경로 길이 : %.1f \n", sum);
			sum = 0;
			break;

		case 5:
			cal_ipl(root, depth);
			printf("평균 검색 성능 : %.1f \n", sum / len);
			sum = 0;
			break;

		case 6:
			inorder(root);
			printf("\n");
			break;

		case 7:
			printf("검색할 합 입력 : ");
			scanf("%d", &pathsum);
			if (haspathsum(root, pathsum)!=NULL)
				printf("발견하였습니다. \n");
			else
				printf("발견하지 못하였습니다. \n");
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}