#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <limits.h>
#include <windows.h>
#define MAX_VERTICES 20
#define MAX_D_VERTICES 100
#define INF 1000000

int visited[MAX_VERTICES];

typedef struct GNode {
	int data;
	struct GNode *link;
} GNode;

typedef struct graphtype {
	int n;
	GNode *list[MAX_VERTICES];
}gtype;

typedef struct dgraphtype {
	int n;
	int weight[MAX_D_VERTICES][MAX_D_VERTICES];
}dtype;

//리스트 초기화
void init_g(gtype *g)
{
	int v;
	g->n = 0;
	for (v = 0;v < MAX_VERTICES;v++)
		g->list[v] = NULL;
}

//리스트에 정점 개수 삽입
void insert_v(gtype *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "정점 개수 초과 \n");
		return;
	}
	g->n++;
}

//리스트에 정점끼리 연결
void insert_e(gtype *g, int u, int v)
{
	GNode *node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "정점 번호 오류 \n");
		return;
	}

	node = (GNode*)malloc(sizeof(GNode));
	node->data = v;
	node->link = g->list[u];
	g->list[u] = node;
}

//노드 생성 함수
GNode* create_node(int data) {
	GNode* node = (GNode*)malloc(sizeof(GNode));
	node->data = data;
	node->link = NULL;
	return node;
}

//노드 삽입 함수
void Insert_head(GNode** R, GNode* NewNode) {
	NewNode->link = (*R);
	(*R) = NewNode;
}


//리스트 출력
void print_list(gtype*g)
{
	for (int i = 0;i < g->n;i++)
	{
		GNode *p = g->list[i];
		printf("%d ", i);
		while (p != NULL)
		{
			printf("-> %d", p->data);
			p = p->link;
		}
		printf("\n");
	}
}

//리스트 깊이 우선 탐색
void DFS_TS(gtype *g, int v, GNode* R)
{
	GNode *w;
	visited[v] = 1;
	for (w = g->list[v];w;w = w->link)
		if (!visited[w->data])
			DFS_TS(g, w->data, R);
	
	GNode* newnode = create_node(v);
	Insert_head(R, newnode);
}

int topologicalSort(gtype* g, GNode** R) {
	for (int i = 0; i < g->n; i++)   visited[i] = FALSE;
	for (int i = 0; i < g->n; i++) {
		if (visited[i] == FALSE)   DFS_TS(g, i, R);
	}
}

int distance[MAX_D_VERTICES];	// 시작 정점으로부터의 최단 경로 길이 저장
int S[MAX_D_VERTICES];		// 정점의 집합 S
int prev[MAX_D_VERTICES];     // 경로 저장

int choose(int distance[], int n, int S[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for (i = 0;i < n;i++) {
		if (distance[i] < min && !S[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

int step = 1;
void print_status(dtype *g)
{
	
	printf("STEp : %d \n", step++);
	printf("distance: ");
	for (int i = 0;i < g->n;i++)
	{
		if (distance[i] == INF)
			printf(" X ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" S: ");
	for (int i = 0;i < g->n;i++)
		printf("%2d ", S[i]);
	printf("\n \n");
}

void dijkstra_shortestpath(dtype *g, int start)
{
	int i, u, w;
	for (i = 0;i < g->n;i++)
	{
		distance[i] = g->weight[start][i];
		S[i] = FALSE;
	}
	S[start] = TRUE;
	distance[start] = 0;
	for (i = 0;i < g->n-1;i++)
	{
		print_status(g);
		u = choose(distance, g->n, S);
		S[u] = TRUE;
		for (w = 0;w < g->n;w++)
		{
			if (distance[i] + g->weight[u][w] < distance[w])
				distance[w] = distance[u] + g->weight[u][w];
		}
	}
}



void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 위상정렬 \n");
	printf("2. 다익스트라 알고리즘(G1) \n");
	printf("3. 다익스트라 알고리즘(G2) \n");
	printf("0. 종료 \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	gtype *g1;
	g1 = (gtype*)malloc(sizeof(gtype));
	init_g(g1);
	GNode* R = NULL;

	for (int i = 0;i < 6;i++)
		insert_v(g1, i);
	insert_e(g1, 0, 2);
	insert_e(g1, 0, 3);
	insert_e(g1, 1, 3);
	insert_e(g1, 1, 4);
	insert_e(g1, 2, 3);
	insert_e(g1, 2, 5);
	insert_e(g1, 3, 5);
	insert_e(g1, 4, 5);

	dtype g2 = { 8,
		{{0,INF,INF,INF,INF,INF,INF,INF},
		{300,0,INF,INF,INF,INF,INF,INF},
		{INF,INF,1200,0,INF,INF,INF,INF},
		{INF,INF,INF,1500,0,250,INF,INF},
		{INF,INF,INF,1000,INF,0,900,1400},
		{INF,INF,INF,INF,INF,INF,0,1000},
		{1700,INF,INF,INF,INF,INF,INF,0}}
	};

	dtype g3 = { 7,
		{{0,7,INF,INF,3,10,INF},
		{7,0,4,INF,2,6,INF},
		{INF,4,0,3,INF,INF,INF},
		{INF,INF,2,0,INF,9,4},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}
	};

	int choice;
	while (1)
	{
		menu();
		printf("\n");
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("**순서**\n");
			topologicalSort(g1, &R);
			printf("\n");
			while (R != NULL) {
				printf("정점 %d -> ", R->data);
				R = R->link;
			}
			printf("\n");

		case 2:
			step = 1;
			dijkstra_shortestpath(&g2, 4);
			break;

		case 3:
			step = 1;
			dijkstra_shortestpath(&g3, 0);
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}