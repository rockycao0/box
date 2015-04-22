#include<stdio.h>
#include<stdlib.h>

void print(struct position man, struct position box);
void move(struct position *man, char act);
int text(struct position box);
void push(struct position man, struct position *box, char act);
void same(struct position man, struct position *turn);

char map[10][20] =
{
	"********************",
	"*  *               *",
	"*  *       *       *",
	"*          *   *****",
	"*          *       *",
	"*          *       *",
	"****     ***********",
	"*                # *",
	"*                  *",
	"********************",
};
struct position
{
	int x;
	int y;
};
int main()
{
	struct position man;
	struct position box;
	struct position turnm;
	struct position turnb;
	char act;
	man.x = 3;
	man.y = 5;
	box.x = 6;
	box.y = 6;
	print(man,box);
	while (1)
	{
		scanf_s("%c", &act);
		same(man, &turnm);
		move(&turnm, act);
		if (text(turnm))
		{
			same(box, &turnb);
			push(turnm, &turnb, act);
			if (text(turnb) == 0)
				continue;
		}
		else
			continue;
		move(&man, act);
		text(man);
		push(man, &box, act);
		text(box);
		system("cls");
		print(man,box);
		if (box.x == 7 && box.y == 17)
		{
			printf("you win\a\n");
			break;
		}
	}
	system("pause");
	return 0;
}
void same(struct position man, struct position *turn)
{
	turn->x = man.x;
	turn->y = man.y;
}
void move(struct position *man, char act)
{
	switch (act)
	{
	case 's':man->x = man->x + 1;
		break;
	case 'a':man->y = man->y - 1;
		break;
	case 'd':man->y = man->y + 1;
		break;
	case 'w':man->x = man->x - 1;
		break;
	default:;
	}
}
void print(struct position man,struct position box)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 20; j++)
		{
			{
				if (i == man.x&&j == man.y)
					printf("T");
				else if (i == box.x&&j == box.y)
					printf("@");
				else
					printf("%c", map[i][j]);
			}
			if (j == 19)
				printf("\n");
		}
	}
}
int text(struct position box)
{
	if (map[box.x][box.y] =='*')
		return 0;
	else
		return 1;
}
void push(struct position man, struct position *box,char act)
{
	if (man.x == box->x && act == 's'&&man.y == box->y)
		box->x = box->x + 1;
	else if (man.x == box->x && act == 'w'&&man.y == box->y)
		box->x = box->x - 1;
	else if (man.y == box->y && act == 'd'&&man.x == box->x)
		box->y = box->y + 1;
	else if (man.y == box->y && act == 'a'&&man.x == box->x)
		box->y = box->y - 1;
}