#include<iostream>

 

void ReNew(long long**, int,int,int, long long);

long long sum(long long**tree,int l,int r)

{

	//짝수면 왼쪽 홀수면 오른쪽임

	long long SumofLeft=tree[0][l], SumofRight=tree[0][r];

	int h = 0;

	while (l/2 != r/2) {

		//left

		if (l % 2 == 0)//왼쪽차일드

		{

			SumofLeft +=tree[h][l+1];

		}

		else//오른쪽 차일드

		{

			//그냥 지만 올ㄹ감

 

		}

 

		//오른쪽 끝 작업

		if (r % 2 == 0)//왼쪽 차일드

		{

			//지만 올라감

		}

		else//오른쪽 차일드

		{

			SumofRight+=tree[h][r-1];

		}

 

 

 

		l /= 2; r /= 2; h++;

	}

 

	return SumofLeft + SumofRight;

 

}

int main() {

	long long n;

	int  m, k;//n<=100만 , m<=1만,k<=1만

	scanf("%lld %d %d", &n, &m, &k);

 

	long long t = n;

	int row = 0;

    int flag=0;
	while (t > 0)

	{

		row++;
        if(t!=1&&t%2!=0) flag=1;


		t /= 2;
	}

    if(flag==1)   
        row+=1;

	

 

	long long** tree = (long long**)malloc(sizeof(long long*) * row);
    if (tree == NULL) {	printf("ERROR1");return 1;}//ERROR CATCH

    t=1;
	for (int i = row-1;i >= 0;i--)
	{
		tree[i] = (long long*)malloc(sizeof(long long) * t);
        if (tree[i] == NULL) {printf("ERROR2");	return 1;}
        
        for(int k=0;k<t;k++)tree[i][k]=0;

		printf("%d floor: %lld\n", i, t);//tst

		t *=2;

	}

 

	for (int i = 0;i < n;i++)

	{

		scanf("%lld", &tree[0][i]);

	}

    t=1;
	for(int i=0;i<row;i++)
    {
        t*=2;
    }

	//최초 트리 갱신

	for (int i = 1;i < row;i++)

	{

		printf("%dfloor updating --",i);//tst

		for (int k = 0;k < t;k++)
		{

			tree[i][k] = tree[i -1][2 * k] + tree[i -1][2 * k + 1];
		}

		t /= 2;

		printf("done\n");//tst

	}

 

	int tstN = 0;

	for (int i = row - 1;i >= 0;i--)

	{

		printf("%d floor: ", i);

		for (int ww = 0;ww <= tstN;ww++)

		{

			printf("%lld ",tree[i][ww]);

		}

		printf("\n");

		if (tstN == 0)tstN++;

		else

		tstN *= 2;

	}

 

	int term = k + m;

	int cmd;

	long long a, b;

	for (int i = 0;i < term;i++)

	{

		scanf("%d %lld %lld", &cmd,&a,&b);

		if (cmd == 1) {//수 변경

			ReNew(tree, row, 0, a, b - tree[0][a]);

		}

		else//cmd==2

		{

			printf("%lld\n", sum(tree, a, b));

		}

	}

 

 

	return 0;

}

 

 

 

void ReNew(long long** tree, int maxheight,int height,int pos, long long incoming) {

	if (height > maxheight)return;

 

	tree[height][pos] += incoming;

	ReNew(tree, maxheight, height + 1, pos/2, incoming);

 

}