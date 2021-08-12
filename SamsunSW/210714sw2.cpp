#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <malloc.h>
#define MAXR 99
#define MAXC 26

#define MAXL 100

int map[100][100];
typedef struct
{

	int ON;
	int r1, r2, c1, c2;
} order;

typedef struct Node
{

	int r, c;
	struct Node *next, *prev;
} Node;

typedef struct Queue
{
	Node *H;
	Node *T;
} Queue;

Queue *Q;
order Omap[100][100];

Node *createNode()
{
	Node *ret = (Node *)malloc(sizeof(Node));

	ret->next = NULL;
	ret->prev = NULL;
	return ret;
}
Queue* CreateQ()
{
	Queue* q = (Queue *)malloc(sizeof(Queue));
	q->H = createNode();
	q->T = createNode();

	q->H->next = q->T;
	q->T->prev = q->H;

	return q;
}
void pushQ(Queue *q, int r, int c)
{
	Node *node = createNode();
	//node->DAT = odata;
	node->r = r;
	node->c = c;
	node->next = q->T;
	node->prev = q->T->prev;

	node->next->prev = node;
	node->prev->next = node;
}
Node* topQ(Queue *q)
{
	Node *ret = q->H->next;
	return ret;
}
void popQ(Queue *q)
{
	Node *ret = q->H->next;
	q->H->next = ret->next;
	ret->next->prev = q->H;

	free(ret);
}
bool isEmpty(Queue *q)
{
	if (q->H->next == q->T)
		return true;
	else
		return false;
}
void init(int C, int R)
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			map[i][j] = 0;
			Omap[i][j].ON = 0;
		}
	}
	Q=CreateQ();
	//printf("Queue check H: %d T: %d\n",Q->H==NULL,Q->T==NULL);
}

void set(int col, int row, char input[])
{
	//문자열부터 나눠줘야함.
	row--;
	col--;
	int c1 = input[4] - 'A';
	int r1 = input[5] - '0' - 1;
	int c2 = input[7] - 'A';
	int r2 = input[8] - '0' - 1;
	//ON 1 sum 2 sub 3 mul 4 add

	switch (input[0])
	{
	case 'S':
	{
		if (input[2] == 'M') //sum
		{
			Omap[row][col].ON = 7;
			if(r1==r2&&c1>c2)
			{
				int temp=c1;
				c1=c2;
				c2=temp;
			}
			if(c1==c2&&r1>r2)
			{
				int temp=r1;
				r1=r2;
				r2=temp;
			}


		}
		else //sub
			Omap[row][col].ON = 2;
		Omap[row][col].r1 = r1;
		Omap[row][col].r2 = r2;
		Omap[row][col].c1 = c1;
		Omap[row][col].c2 = c2;
	}
	break;
	case 'M':				 //MUL
		if (input[1] == 'U') //mul
			Omap[row][col].ON = 3;
		else if (input[1] == 'A') //max
			{Omap[row][col].ON = 5;
			if(r1==r2&&c1>c2)
			{
				int temp=c1;
				c1=c2;
				c2=temp;
			}
			if(c1==c2&&r1>r2)
			{
				int temp=r1;
				r1=r2;
				r2=temp;
			}}
		else //min
			{Omap[row][col].ON = 6;
				if(r1==r2&&c1>c2)
			{
				int temp=c1;
				c1=c2;
				c2=temp;
			}
			if(c1==c2&&r1>r2)
			{
				int temp=r1;
				r1=r2;
				r2=temp;
			}

			}
		Omap[row][col].r1 = r1;
		Omap[row][col].r2 = r2;
		Omap[row][col].c1 = c1;
		Omap[row][col].c2 = c2;
		break;

	case 'A': //ADD
	{
		Omap[row][col].ON = 1;
		Omap[row][col].r1 = r1;
		Omap[row][col].r2 = r2;
		Omap[row][col].c1 = c1;
		Omap[row][col].c2 = c2;
	}
	break;
	case 'D': //Div
		Omap[row][col].ON = 4;
		Omap[row][col].r1 = r1;
		Omap[row][col].r2 = r2;
		Omap[row][col].c1 = c1;
		Omap[row][col].c2 = c2;
	default:
		int n = 0;
		int sign = 0;
		if (input[0] == '-')
			sign = 1;
		else
			n += input[0] - '0';
		for (int i = 1; input[i] != 0; i++)
		{
			n *= 10;
			n += input[i] - '0';
		}

		if (sign)
			n *= -1;

		map[row][col] = n;
		break;
	}
	if (Omap[row][col].ON)
		pushQ(Q, row, col);
}

void update(int value[MAXR][MAXC])
{
	//printf("upup ");
	//printf("updating!! %d\n",isEmpty(Q)?1:0);
		for(int i=0;i<MAXR;i++)
	{
		for(int j=0;j<MAXC;j++)
		{
			value[i][j]=map[i][j];
		}
	}
	while (!isEmpty(Q))
	{
		Node *Ndata = topQ(Q);
		int i = Ndata->r;
		int j = Ndata->c;

		//printf("func: %d r: %d c: %d\n",Omap[i][j].ON,i,j);
		popQ(Q);
		if (Omap[Omap[i][j].r1][Omap[i][j].c1].ON || Omap[Omap[i][j].r2][Omap[i][j].c2].ON)
		{
			
			pushQ(Q, i, j);
			continue;
		}

		int flag = 1;
		switch (Omap[i][j].ON)
		{
		case 0:
			break;
		case 1: //add
			map[i][j] = map[Omap[i][j].r1][Omap[i][j].c1] + map[Omap[i][j].r2][Omap[i][j].c2];

			break;
		case 2: //sub
			map[i][j] = map[Omap[i][j].r1][Omap[i][j].c1] - map[Omap[i][j].r2][Omap[i][j].c2];

			break;
		case 3: //mul
			map[i][j] = map[Omap[i][j].r1][Omap[i][j].c1] * map[Omap[i][j].r2][Omap[i][j].c2];

			break;
		case 4: //div
			map[i][j] = map[Omap[i][j].r1][Omap[i][j].c1] / map[Omap[i][j].r2][Omap[i][j].c2];

			break;
		case 5: //max
		{
			int MAX1 = 0;

			if (Omap[i][j].r1 == Omap[i][j].r2)
			{
				for (int q = Omap[i][j].c1; q <= Omap[i][j].c2; q++)
				{
					if (Omap[Omap[i][j].r1][q].ON)
					{
						flag=0;
						break;
					}
					if (map[Omap[i][j].r1][q] > MAX1)
						MAX1 = map[Omap[i][j].r1][q];
				}
			}
			else
			{
				for (int q = Omap[i][j].r1; q <= Omap[i][j].r2; q++)
				{
					if (Omap[q][Omap[i][j].c1].ON)
					{
						flag=0;
						break;
					}
					if (map[q][Omap[i][j].c1] > MAX1)
						MAX1 = map[q][Omap[i][j].c1];
				}
			}
			if (flag)
				map[i][j] = MAX1;
		}
		break;
		case 6: //min
		{
			int MAX1 = 0x7fffffff;
			if (Omap[i][j].r1 == Omap[i][j].r2)
			{
				for (int q = Omap[i][j].c1; q <= Omap[i][j].c2; q++)
				{
					if (Omap[Omap[i][j].r1][q].ON)
					{
						flag=0;
						break;
					}
					if (map[Omap[i][j].r1][q] < MAX1)
						MAX1 = map[Omap[i][j].r1][q];
				}
			}
			else
			{
				for (int q = Omap[i][j].r1; q <= Omap[i][j].r2; q++)
				{
					if (Omap[q][Omap[i][j].c1].ON)
					{
						flag=0;
						break;
					}
					if (map[q][Omap[i][j].c1] < MAX1)
						MAX1 = map[q][Omap[i][j].c1];
				}
			}
			if(flag)map[i][j] = MAX1;
		}
		break;
		case 7: //sum
		{
			int sum = 0;
			if (Omap[i][j].r1 == Omap[i][j].r2)
			{
				for (int q = Omap[i][j].c1; q <= Omap[i][j].c2; q++)
				{
					if (Omap[Omap[i][j].r1][q].ON)
					{
						//printf("prob r:%d c:%d\n",q,Omap[i][j].c1);
						flag=0;
						break;
					}
					sum += map[Omap[i][j].r1][q];
				}
			}
			else
			{
				for (int q = Omap[i][j].r1; q <= Omap[i][j].r2; q++)
				{
					if (Omap[q][Omap[i][j].c1].ON)
					{
						//printf("prob r:%d c:%d\n",Omap[i][j].c1,q);
						flag=0;
						break;
					}
					sum += map[q][Omap[i][j].c1];
				}
			}
			if(flag)map[i][j] = sum;
			break;
		}
		
		}
		if(flag){
			value[i][j] = map[i][j];
			Omap[i][j].ON=0;
			}
		else
		{
				pushQ(Q, i, j);
			
		}
	}

	for(int i=0;i<MAXR;i++)
	{
		for(int j=0;j<MAXC;j++)
		{
			value[i][j]=map[i][j];
		}
	}
}

#define INIT 100
#define SET 200
#define UPDATE 300

static int R;
static int C;

static int gethash(int value[MAXR][MAXC])
{
	int ret = 0;

	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c)
			ret = (ret * 7 + value[r][c]) & 0x7fffffff;

	return ret;
}
void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}
static bool run()
{
	int Q;
	bool okay = true;

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		int cmd, row, col;
		int userhash, answerhash;

		char input[MAXL];
		int value[MAXR][MAXC];

		scanf("%d", &cmd);

		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &C, &R);
			if (okay)
				init(C, R);
			break;
		case SET:
			scanf("%d %d %s", &col, &row, input);
			if (okay)
				set(col, row, input);
			break;
		case UPDATE:
			scanf("%d", &answerhash);
			if (okay)
			{
				update(value);
				userhash = gethash(value);
				if (answerhash != userhash)
					okay = false;
			}
			break;
		default:
			break;
		}
		if(okay)
		print();
	}

	return okay && Q > 0;
}

int main()
{
	int TC;

	//freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &TC);

	int totalscore = 0;
	for (int testcase = 1; testcase <= TC; ++testcase)
	{
		int score = run() ? 100 : 0;
		printf("#%d %d\n", testcase, score);
		totalscore += score;
	}
	printf("total score = %d\n", totalscore / TC);
	return 0;
}