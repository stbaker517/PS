#include <iostream>

void ReNew(long long **, int, int, int, long long);

long long sum(long long **tree, int l, long long r);
int main()
{
    int h = 0;
    int n, m, k; //n: 맨 및 줄 개수 m:수 변경 k: 구간합
    int tmp, flag = 0;
    long long **tree;

    scanf("%d %d %d", &n, &m, &k);

    tmp = n;

    while (tmp > 0)
    {
        h++;
        if (tmp != 1 && tmp % 2 != 0)
            flag = 1;
        tmp /= 2;
    }
    if (flag == 1)
        h++;

    //printf("H: %d\n", h); //tst

    tree = (long long **)malloc(sizeof(long long *) * h);
    tmp = 1;
    for (int i = h - 1; i >= 0; i--)
    {
        tree[i] = (long long *)malloc(sizeof(long long) * tmp);
        for (int j = 0; j < tmp; j++)
            tree[i][j] = 0;
        tmp *= 2;
    }

    //입력
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &tree[0][i]);
        //printf("input: %lld\n", tree[0][i]); //test
    }
   // printf("\n\n"); //test

    int tempsize = tmp;
    /*//test----------------- test print
    tempsize = 1;
    for (int i = h - 1; i >= 0; i--)
    {
        printf("%d floor: ",i);
        for (int j = 0; j < tempsize; j++)
            printf("%lld ", tree[i][j]);

        printf("\n");
        tempsize *= 2;
    }
    //test--------------*/

    tempsize = tmp/2;
    //트리 우선 계산
    for (int i = 1; i <= h - 1; i++)
    {
        //printf("%d floor\n",i);
        for (int j = 0; j < tempsize/2; j++)
        {
            //printf("%lld+%lld=>",tree[i-1][2*j],tree[i-1][2*j+1]);
            tree[i][j] = tree[i - 1][2 * j] + tree[i - 1][2 * j + 1];
            //printf("%lld+%lld=",tree[i-1][2*j],tree[i-1][2*j+1]);
            //printf("%lld \n",tree[i][j]);//test
        }
        tempsize /= 2;
    }

    /*//test----------------- test print
    tempsize = 1;
    for (int i = h - 1; i >= 0; i--)
    {
        printf("%d floor: ",i);
        for (int j = 0; j < tempsize; j++)
            printf("%lld ", tree[i][j]);

        printf("\n");
        tempsize *= 2;
    }
    //test--------------*/
    int a,b;
    long long c;
    for(int i=0;i<m+k;i++)
    {
        //printf("Insert a b c  ");//test
        scanf("%d %d %lld",&a,&b,&c);

        //printf("%dth input done\n",i);//test

        if(a==1){
            ReNew(tree,h,0,b-1,c-tree[0][b-1]);
        }

        else{
            printf("%lld\n",sum(tree,b-1,c-1));
        }
    }



    return 0;//MAINEND
}

long long sum(long long **tree, int l, long long r)

{

    if(l==r)return tree[0][l];
    //짝수면 왼쪽 홀수면 오른쪽임


    long long SumofLeft = tree[0][l], SumofRight = tree[0][r];

    int h = 0;

    while (l / 2 != r / 2)
    {
        //left
        if (l % 2 == 0) //왼쪽차일드
         {
            SumofLeft += tree[h][l + 1];
        }

        else //오른쪽 차일드
        {          //그냥 지만 올ㄹ감
        }

        //오른쪽 끝 작업

        if (r % 2 == 0) //왼쪽 차일드
        {
            //지만 올라감
        }

        else //오른쪽 차일드
        {
            SumofRight += tree[h][r - 1];
        }

        l /= 2;
        r /= 2;
        h++;
    }

    return SumofLeft + SumofRight;
}
void ReNew(long long **tree, int maxheight, int height, int pos, long long incoming)
{

    if (height >= maxheight)
        return;

    tree[height][pos] += incoming;

    ReNew(tree, maxheight, height + 1, pos / 2, incoming);
}