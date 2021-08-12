#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
ll arr[10000];
ll dist[10000];
int k;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    sort(arr,arr+n);

    //for(int i=0;i<n;i++)cout<<arr[i];

    long long tdist=arr[n-1]-arr[0];

    for(int i=0;i<n-1;i++)
    {
        dist[i]=arr[i+1]-arr[i];
    }

    sort(dist,dist+n-1);

    /*for(int i=n-2;i>n-1-k;i--)
    {
        tdist-=dist[i];
    }*/

    ll output=0;
    for(int i=0;i<n-k;i++)output+=dist[i];
    //cout<<tdist;
    cout<<output;
}
