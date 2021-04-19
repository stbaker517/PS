#include<iostream>
#include<cmath>
int main(){
    long long min,max;
    int arr_size;
    scanf("%lld %lld",&min,&max);
    arr_size=max-min+1;
    long long pivot[1000002];
    for(int i=0;i<=1000001;i++){
        pivot[i]=i;
    }
    long long* arr=(long long*)malloc(sizeof(long long)*(arr_size));
    for(int i=0;i<arr_size;i++)
    {
        arr[i]=min+i;
    }
    int flag=0;
    long long squared;
    int count=arr_size;

    long long P;

    for(long long i=2;i*i<=max;i++)
    {
        if(pivot[i]=-1)continue;
        P=i*i;
        for(int j=1;j*P<=1000001;j++)pivot[j]=-1;


        for(int j=0;j<arr_size;j++)
        {
            if(arr[j]==-1)continue;
            if(arr[j]%squared==0)
            {
                arr[j]=-1;
                count--;
            }
        }
    }

    printf("%d",count);



}