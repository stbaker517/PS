#include<iostream>
#include<string.h>
char A[2001];
char B[2001];
int dp[2000];
int score[26]={
    3, 2, 1, 2, 3, 
    3, 2, 3, 3, 2, 
    2, 1, 2, 2, 1, 
    2, 2, 2, 1, 2, 
    1, 1, 1, 2, 2, 
    1};

int main(){
    scanf("%s",A);
    getchar();
    scanf("%s",B);
    int len=strlen(A);

    for(int i=0;i<len;i++)
    {
       dp[i]=(score[A[i]-'A']+score[B[i]-'A'])%10;
    }
    len--;
    while(len>=2)
    {
        for(int i=0;i<len;i++)
            dp[i]=(dp[i]+dp[i+1])%10;
        len--;
    }
    printf("%d%d",dp[0],dp[1]);




    return 0;
}