#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct element {
	int x1;
	int y1;
}element;

/*typedef struct Listnode {
	element data;
	struct Listnode *link;
}Listnode;*/

element *UseFor(element *coor)
{

}

int Recursive()
{

}

int main(void)
{
	int random;

	printf("좌표 10개 무작위 입력");
	element coor[10] = { {0,}, };

	for (int i = 0;i < 10;i++)
	{
		random = rand() % 11;
		coor[i].x1 = random;
		coor[i].y1 = random;
		printf("[ %d, %d ] ", coor[i].x1, coor[i].y1);
	}
	printf("\n");

	UseFor(coor);

}