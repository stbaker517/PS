#include <iostream>

int **I, **A;

int **MultipleMatrix(int, int);
int **multi(int **a, int **b, int n);

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    I = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        I[i] = (int *)malloc(sizeof(int) * n);

    A = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    //Create E Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    int **ptrMatix = MultipleMatrix(p, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", ptrMatix[i][j]);
        }
        printf("\n");
    }
    free(A);
    free(I);
    free(ptrMatix);

    return 0;
}

int **MultipleMatrix(int p, int n)
{
    if (p == 0)
        return I;
    if (p == 1)
        return A;
    else
    {
        int **a, **b;
        a = MultipleMatrix(p / 2, n);
        b = MultipleMatrix(p - p / 2, n);
        int**temp=multi(a, b, n);
     if (a != I && a != A)
    {
        free(a);
        //printf("free done\n");
    }
    if (b != I && b != A)
    {
        free(b);
        //printf("free done\n");
    }
        return temp;
    }
}

int **multi(int **a, int **b, int n)
{
    int **temp = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        temp[i] = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] = temp[i][j] % 1000;
        }
    }
   
    return temp;
}
