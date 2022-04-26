#include<iostream>

using namespace std;


long long count;
void mergeSort(int*arr,int s,int e);
void merge(int*arr,int s1,int e1,int s2,int e2);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[1000000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    cout<<count;

 


    return 0;
}

void mergeSort(int*arr,int s,int e){
    if(s>=e)return;
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,mid+1,e);

}
void merge(int*arr,int s1,int e1,int s2,int e2){
    int* tmp= new int[e2-s1+1];
    int i=s1,j=s2;
    int t=0;
    long long tmpC=0;
    while(i<=e1&&j<=e2)
    {
        if(arr[i]<=arr[j])
        {
            tmp[t++]=arr[i++];
        }
        else{
            tmpC+=e1-i+1;
            tmp[t++]=arr[j++];
        }
    }

    while(i<=e1)
    {
        tmp[t++]=arr[i++];
    }
    while(j<=e2)
    {
        tmp[t++]=arr[j++];
    }
    for(int i=0;i<t;i++)
    {
        arr[s1+i]=tmp[i];
    }
    delete tmp;
    count+=tmpC;
    return;
}