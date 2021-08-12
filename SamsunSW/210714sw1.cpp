#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 4
#define MAX_QUERYCOUNT 1000000

static int digits[N];
static int digits_c[10];

static int T;

//extern void doUserImplementation(int guess[]);

static int querycount;

// the value of limit_query will be changed in evaluation
static const int limit_query = 234;

typedef struct
{
	int hit;
	int miss;
} Result;

static bool isValid(int guess[])
{
	int guess_c[10];

	for (int count = 0; count < 10; ++count)
		guess_c[count] = 0;
	for (int idx = 0; idx < N; ++idx)
	{
		if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0)
			return false;
		guess_c[guess[idx]]++;
	}
	return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[])
{
	Result result;

	if (querycount >= MAX_QUERYCOUNT)
	{
		result.hit = -1;
		result.miss = -1;
		return result;
	}

	querycount++;

	if (!isValid(guess))
	{
		result.hit = -1;
		result.miss = -1;
		return result;
	}

	result.hit = 0;
	result.miss = 0;

	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] == digits[idx])
			result.hit++;
		else if (digits_c[guess[idx]] > 0)
			result.miss++;

	return result;
}

static void initialize()
{
	for (int count = 0; count < 10; ++count)
		digits_c[count] = 0;
	for (int idx = 0; idx < N; ++idx)
	{
		char c;
		do
			scanf("%c", &c);
		while (c < '0' || c > '9');
		digits[idx] = c - '0';
		digits_c[digits[idx]]++;
	}

	querycount = 0;
}

static bool check(int guess[])
{
	for (int idx = 0; idx < N; ++idx)
		if (guess[idx] != digits[idx])
			return false;
	return true;
}



//--------------------------------------------from here
Result test(int origin[],int testee[])
{
	int dig[10];
	for(int i=0;i<10;i++)dig[i]=0;
	for(int i=0;i<4;i++)dig[origin[i]]++;

	Result result;
	result.hit=0;
	result.miss=0;

	for (int idx = 0; idx < N; ++idx)
	if (origin[idx] == testee[idx])
		result.hit++;
	else if (dig[testee[idx]] > 0)
		result.miss++;

	return result;
}
void makeCand(int& size, int cand[][4],int origin[],Result DAT,bool visit[])
{
	Result result;
	size=0;
	


	int temp[4];

	for (int i = 0; i < 10; i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		for (int j = 0; j < 10; j++)
		{
			if (visit[j])
				continue;

			visit[j] = true;
			for (int k = 0; k < 10; k++)
			{
				if (visit[k])
					continue;

				visit[k] = true;
				for (int l = 0; l < 10; l++)
				{
					if (visit[l])
						continue;
					visit[l] = true;

					temp[0]=i;
					temp[1]=j;
					temp[2]=k;
					temp[3]=l;

					result=test(origin,temp);
					if(result.hit==DAT.hit&&result.miss==DAT.miss)
					{
						for(int qq=0;qq<4;qq++)
							cand[size][qq]=temp[qq];
						size++;
					}

					visit[l] = false;
				}
				visit[k] = false;
			}
			visit[j] = false;
		}
		visit[i] = false;
	}




}

void doUserImplementation(int guess[])
{
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.
	Result result1,result2,result3,result;

	int temp[4];
	int cnted = 0;

	//test1

	bool visit[10];
	for(int i=0;i<10;i++)visit[i]=false;
	int test1[4]={0,1,2,3};
	int test2[4]={3,4,5,6};
	int test3[4]={6,7,8,9};
	int size=0;
	int cand[5040][4];
	result1=query(test1);
	if(result1.hit==0&&result1.miss==0)
	{
		for(int i=0;i<4;i++)visit[i]=true;
	}
	
	result2=query(test2);
	if(result2.hit==0&&result2.miss==0)
	{
		for(int i=3;i<7;i++)visit[i]=true;
	}
	result3=query(test3);
	if(result3.hit==0&&result3.miss==0)
	{
		for(int i=6;i<10;i++)visit[i]=true;
	}

	int cnt1,cnt2,cnt3;
	cnt1=result1.hit+result1.miss;
	cnt2=result2.hit+result2.miss;
	cnt3=result3.hit+result3.miss;
	
	if(cnt1<cnt2)
	{
		if(cnt2>cnt3) makeCand(size,cand,test2,result2,visit);
		else makeCand(size,cand,test3,result3,visit);
	}
	else
	{
		if(cnt1>cnt3)
			makeCand(size,cand,test1,result1,visit);
		else
			makeCand(size,cand,test3,result3,visit);
	}

	int lsize=0;
	int Fcand[5000][4];
	Result tres1,tres2,tres3;
	for(int i=0;i<size;i++)
	{
		tres1=test(test1,cand[i]);
		if(tres1.hit!=result1.hit||tres1.miss!=result1.miss)continue;
		tres2=test(test2,cand[i]);
		if(tres2.hit!=result2.hit||tres2.miss!=result2.miss)continue;
		tres3=test(test3,cand[i]);
		if(tres3.hit!=result3.hit||tres3.miss!=result3.miss)continue;

		for(int q=0;q<4;q++)Fcand[lsize][q]=cand[i][q];
		lsize++;
	}
	//printf("Lsize: %d\n",lsize);
	/*for(int i=0;i<lsize;i++)
	{
		printf("FCAND");
		for(int j=0;j<4;j++)
		{
			printf("%d",Fcand[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<lsize;i++)
	{
		result=query(Fcand[i]);
		if(result.hit==4)
		{
			for(int j=0;j<4;j++)
				guess[j]=Fcand[i][j];
			return;}
	}



	return;
}

//-------------------------- to here

int main()
{
	int total_score = 0;
	int total_querycount = 0;
	;

	// freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; ++testcase)
	{
		initialize();

		int guess[N];
		doUserImplementation(guess);

		if (!check(guess))
			querycount = MAX_QUERYCOUNT;
		if (querycount <= limit_query)
			total_score++;
		printf("#%d %d\n", testcase, querycount);
		total_querycount += querycount;
	}
	if (total_querycount > MAX_QUERYCOUNT)
		total_querycount = MAX_QUERYCOUNT;
	printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
	return 0;
}