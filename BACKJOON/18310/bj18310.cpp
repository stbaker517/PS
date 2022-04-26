#include<iostream>
#include<algorithm>

using namespace std;
#define ll long long
int arr[200001];
int n;

ll f(int idx){
    int t=arr[idx];
    ll sumR=0;
    ll sumL=0;
    for(int i=0;i<idx;i++)
    {
        if(arr[i]==t)break;
        sumL+=arr[i];
    }
    for(int i=n-1;i>idx;i--)
    {
        if(arr[i]==t)break;
        sumR+=arr[i];
    }

    return sumL+sumR;


}




int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin>>n;
    int a;

    for(int i=0;i<n;i++)cin>>arr[i];

    sort(arr,arr+n);

    int med=arr[n/2];
    int nummed=1;
    int Ridx=med+1;
    int Lidx=med-1;

    while(arr[med]==arr[Lidx])
    {
        if(Lidx==0)break;

        Lidx--;
    }
    int L=0,R=0;
    if(Lidx!=med)L=Lidx+1;
    while(arr[med]==arr[Ridx])
    {
        if(Ridx==n-1)break;
        Ridx++;
    }
    if(Ridx!=med)R=n-Ridx;
    nummed=n-L-R;

    








    return 0;
}