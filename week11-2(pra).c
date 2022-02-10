#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
#define MAX_VERTICES 20

typedef struct QNode {
	int data;
	struct QNode *link;
} QNode;

typedef struct LQueueType {
	QNode *front, *rear;
} LQueueType;

typedef struct graphtype {
	int n;
	QNode *list[MAX_VERTICES];
}gtype;

LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		//printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

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

void init_g(gtype *g)
{
	int v;
	g->n = 0;
	for (v = 0;v < MAX_VERTICES;v++)
		g->list[v] = NULL;
}

void insert_v(gtype *g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "���� ���� �ʰ� \n");
		return;
	}
	g->n++;
}

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

void print_list(gtype*g)
{
	for (int i = 0;i < g->n;i++)
	{
		QNode *p = g->list[i];
		printf("���� %d�� ���� ����Ʈ ", i + 1);
		while (p != NULL)
		{
			printf("-> %d", p->data);
			p = p->link;
		}
		printf("\n");
	}
}

void create_list_main(gtype *g)
{
	int v;
	printf("���� ���� �Է� : ");
	scanf("%d", &v);
	for (int i = 0;i < v;i++)
		insert_v(g, i);

	int u;
	int v2;

	/*while (1)
	{
		printf("u �Է� : ");
		scanf("%d", &u);
		printf("v2 �Է� : ");
		scanf("%d", &v2);
		if (u == 0 && v2 == 0) {
			printf("���� ���� \n");
			break;
		}
	}*/
	
	insert_e(g, 0, 3);
	insert_e(g, 0, 1);
	insert_e(g, 1, 3);
	insert_e(g, 1, 2);
	insert_e(g, 1, 0);
	insert_e(g, 2, 3);
	insert_e(g, 2, 1);
	insert_e(g, 3, 2);
	insert_e(g, 2, 1);
	insert_e(g, 3, 0);

	printf("���� �Ϸ� \n");
}

int visited[MAX_VERTICES];
void DFS(gtype *g, int v)
{
	QNode *w;
	visited[v] = 1;
	printf("���� %d -> ", v);
	for (w = g->list[v];w;w = w->link)
		if (!visited[w->data])
			DFS(g, w->data);
	printf("\n");
}

void BFS(gtype *g, int v)
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
	printf("\n");
}

void menu()
{
	printf("===========================================\n");
	printf("1. ��������Ʈ ���� \n");
	printf("2. ��������Ʈ ��� \n");
	printf("3. ���� �켱 Ž�� \n");
	printf("4. �ʺ� �켱 Ž�� \n");
	printf("0. ���� \n");
	printf("===========================================\n");
}

int main(void)
{
	int choice;
	gtype *g;
	g = (gtype*)malloc(sizeof(gtype));
	init_g(g);
	int start;

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			create_list_main(g);
			break;

		case 2:
			print_list(g);
			break;

		case 3:
			printf("������ ���� : ");
			scanf("%d", &start);
			DFS(g, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			break;

		case 4:
			printf("������ ���� : ");
			scanf("%d", &start);
			BFS(g, start);
			for (int i = 0;i < MAX_VERTICES;i++)
				visited[i] = 0;
			break;

		case 0:
			free(g);
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}