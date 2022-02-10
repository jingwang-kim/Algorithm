#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

int len = 0; //노드 개수

// 트리의 노드 구조 정의
typedef struct treeNode {
	int data;              // 데이터 필드
	struct treeNode* left; // 왼쪽 서브 트리에 대한 링크 필드
	struct treeNode* right;// 오른쪽 서브 트리에 대한 링크 필드
} treeNode;

//삽입
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

//삭제
void deleteNode(treeNode* root, int key) {
	treeNode* parent, * p, * succ, * succ_parent;
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
			if (parent->left == p) parent->left = NULL;
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
		while (succ->right != NULL) { // 왼쪽 서브트리에서 후계자 찾기
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

//평균 검색 성능
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
	printf("4. 평균 검색 성능 \n");
	printf("5. 중위순회 \n");
	printf("0. 종료 \n");
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
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("삽입할 노드 입력 : ");
			scanf("%d", &num);
			root = treeInsert(root, num);
			len += 1;
			break;

		case 2:
			printf("삭제할 노드 입력 : ");
			scanf("%d", &del);
			deleteNode(root, del);
			len -= 1;
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
			ipl = cal_ipl(root);
			printf("평균 검색 성능 : %d \n", ipl);
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
			printf("다시 입력하세요. \n");
			break;
		}
	}
}