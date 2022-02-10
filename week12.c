#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 20

//ť ����ü
typedef struct QNode {
	int data;
	struct QNode *link;
} QNode;

//queue link
typedef struct LQueueType {
	QNode *front, *rear;
} LQueueType;

//��������Ʈ ����ü
typedef struct graphtype {
	int n;
	QNode *list[MAX_VERTICES];
}gtype;

//������� ����ü
typedef struct mgraphtype {
	int m;
	int mat[MAX_VERTICES][MAX_VERTICES];
}mgtype;

//queue �ʱ�ȭ
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

//queue ����ִ��� �˻�
int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		return 1;
	}
	else return 0;
}

//queue ����
void enQueue(LQueueType *LQ, int item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

//queue ����
int deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	int item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

//����Ʈ �ʱ�ȭ
void init_g(gtype *g)
{
	int v;
	g->n = 0;
	for (v = 0;v < MAX_VERTICES;v++)
		g->list[v] = NULL;
}

//��� �ʱ�ȭ
void init_m(mgtype *g)
{
	int r, c;
	g->m = 0;
	for (r = 0;r < MAX_VERTICES;r++)
		for (c = 0;c < MAX_VERTICES;c++)
			g->mat[r][c] = 0;
}

//����Ʈ�� ���� ���� ����
void insert_v(gtype *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "���� ���� �ʰ� \n");
		return;
	}
	g->n++;
}

//��Ŀ� ���� ���� ����
void insert_m_v(mgtype *g, int v)
{
	if (((g->m) + 1) > MAX_VERTICES) {
		fprintf(stderr, "���� ���� �ʰ�\n");
		return;
	}
	g->m++;
}

//����Ʈ�� �������� ����
void insert_e(gtype *g, int u, int v)
{
	QNode *node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "���� ��ȣ ���� \n");
		return;
	}

	node = (QNode*)malloc(sizeof(QNode));
	node->data = v;
	node->link = g->list[u];
	g->list[u] = node;
}

//��Ŀ� �������� ����
void insert_m_e(mgtype *g, int start, int end)
{
	if (start >= g->m || end >= g->m) {
		fprintf(stderr, "���� ��ȣ ���� \n");
		return;
	}

	g->mat[start][end] = 1;
	g->mat[end][start] = 1;
}

//����Ʈ ���
void print_list(gtype*g)
{
	for (int i = 0;i < g->n;i++)
	{
		QNode *p = g->list[i];
		printf("%d ", i);
		while (p != NULL)
		{
			printf("-> %d", p->data);
			p = p->link;
		}
		printf("\n");
	}
}

//��� ���
void print_mat(mgtype*g)
{
	for (int i = 0;i < g->m;i++) {
		for (int j = 0;j < g->m;j++)
			printf("%2d ", g->mat[i][j]);
		printf("\n");
	}
}

int visited[MAX_VERTICES];
//����Ʈ ���� �켱 Ž��
void DFS_list(gtype *g, int v)
{
	QNode *w;
	visited[v] = 1;
	printf("���� %d -> ", v);
	for (w = g->list[v];w;w = w->link)
		if (!visited[w->data])
			DFS_list(g, w->data);
}

//��� ���� �켱 Ž��
void DFS_mat(mgtype *g, int v)
{
	int w;
	visited[v] = 1;
	printf("���� %d -> ", v);
	for (w = 0;w < g->m;w++)
		if (g->mat[v][w] && !visited[w])
			DFS_mat(g, w);
}

//����Ʈ �ʺ� �켱 Ž��
void BFS_list(gtype *g, int v)
{
	QNode *w;
	LQueueType *q;

	q = createLinkedQueue();
	visited[v] = 1;
	printf("%d �湮 ->", v);
	enQueue(q, v);
	while (!isEmpty(q))
	{
		v = deQueue(q);
		for (w = g->list[v];w;w = w->link)
		{
			if (!visited[w->data])
			{
				visited[w->data] = 1;
				printf("%d �湮 -> ", w->data);
				enQueue(q, w->data);
			}
		}
	}
}

//��� �ʺ� �켱 Ž��
void BFS_mat(mgtype *g, int v)
{
	int w;
	LQueueType *q;

	q = createLinkedQueue();
	visited[v] = 1;
	printf("%d �湮 ->", v);
	enQueue(q, v);
	while (!isEmpty(q))
	{
		v = deQueue(q);
		for(w=0;w<g->m;w++)
			if (g->mat[v][w] && !visited[w]) {
				visited[w] = 1;
				printf("%d �湮 -> ", w);
				enQueue(q, w);
			}
	}
}

//�޴�
void menu()
{
	printf("===========================================\n");
	printf("1. ������� g1 ��� \n");
	printf("2. g1 BFS \n");
	printf("3. g1 DFS \n");
	
	printf("4. ��������Ʈ g2 ��� \n");
	printf("5. g2 BFS \n");
	printf("6. g2 DFS \n");
	
	printf("7. ��������Ʈ g3 ��� \n");
	printf("8. g3 BFS \n");
	printf("9. g3 DFS \n");
	
	printf("0. ���� \n");
	printf("===========================================\n");
}

//����
int main(void)
{
	int choice;
	mgtype *g1;
	gtype *g2, *g3;
	g1 = (mgtype*)malloc(sizeof(mgtype));
	g2 = (gtype*)malloc(sizeof(gtype));
	g3 = (gtype*)malloc(sizeof(gtype));
	init_m(g1);
	init_g(g2);
	init_g(g3);
	int start;

	//G1
	for (int i = 0;i < 6;i++)
		insert_m_v(g1, i);
	insert_m_e(g1, 0, 1);
	insert_m_e(g1, 0, 2);
	insert_m_e(g1, 1, 2);
	insert_m_e(g1, 1, 3);
	insert_m_e(g1, 2, 3);
	insert_m_e(g1, 2, 4);
	insert_m_e(g1, 3, 4);
	insert_m_e(g1, 3, 5);

	//G2
	for (int i = 0;i < 13;i++)
		insert_v(g2, i);
	insert_e(g2, 0, 7);
	insert_e(g2, 0, 6);
	insert_e(g2, 1, 2);
	insert_e(g2, 1, 3);
	insert_e(g2, 1, 4);
	insert_e(g2, 2, 1);
	insert_e(g2, 3, 1);
	insert_e(g2, 3, 4);
	insert_e(g2, 4, 1);
	insert_e(g2, 4, 3);
	insert_e(g2, 4, 5);
	insert_e(g2, 5, 4);
	insert_e(g2, 6, 0);
	insert_e(g2, 7, 0);
	insert_e(g2, 8, 9);
	insert_e(g2, 8, 10);
	insert_e(g2, 8, 12);
	insert_e(g2, 9, 8);
	insert_e(g2, 9, 10);
	insert_e(g2, 10, 8);
	insert_e(g2, 10, 9);
	insert_e(g2, 10, 11);
	insert_e(g2, 11, 10);
	insert_e(g2, 12, 8);

	//G3
	for (int i = 0;i < 9;i++)
		insert_v(g3, i);
	insert_e(g3, 0, 2);
	insert_e(g3, 0, 5);
	insert_e(g3, 1, 6);
	insert_e(g3, 2, 6);
	insert_e(g3, 3, 4);
	insert_e(g3, 4, 5);
	insert_e(g3, 5, 3);
	insert_e(g3, 5, 7);
	insert_e(g3, 7, 2);
	insert_e(g3, 7, 8);

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("===================< G1 >===================\n");
			print_mat(g1);
			break;

		case 2:
			printf("������ ���� : ");
			scanf("%d", &start);
			BFS_mat(g1, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 3:
			printf("������ ���� : ");
			scanf("%d", &start);
			DFS_mat(g1, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 4:
			printf("===================< G2 >===================\n");
			print_list(g2);
			break;

		case 5:
			printf("������ ���� : ");
			scanf("%d", &start);
			BFS_list(g2, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 6:
			printf("������ ���� : ");
			scanf("%d", &start);
			DFS_list(g2, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 7:
			printf("===================< G3 >===================\n");
			print_list(g3);
			break;

		case 8:
			printf("������ ���� : ");
			scanf("%d", &start);
			BFS_list(g3, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 9:
			printf("������ ���� : ");
			scanf("%d", &start);
			DFS_list(g3, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			printf("\n");
			break;

		case 0:
			free(g1);
			free(g2);
			free(g3);
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}