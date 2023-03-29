#include<iostream>

using namespace std;
#define ll long long
int arr[1<<20];
ll cnt;
int tmp[1<<20];
void func(int start, int end){

    if(start >= end)return;int mid = (start+end)>>1;
    func(start,mid);
    func(mid+1,end);
    
    int lstart = start, lend = mid,rstart = mid+1,rend=end;
    int lidx=0,ridx=0;
    int idx=0;
    while(lstart+lidx<=lend && rstart+ridx<=rend){
        int Lidx = lstart+lidx;
        int Ridx = rstart+ridx;
        if(arr[Lidx]<=arr[Ridx]){
            tmp[idx]=arr[Lidx];
            if(Lidx>start+idx){
                cnt+=Lidx-(start+idx);
            }
            idx++;
            lidx++;
        } else {
            tmp[idx]=arr[Ridx];
            if(Ridx>start+idx){
                cnt+=Ridx-(idx+start);
            }
            idx++;
            ridx++;
        }
    }
    while(lstart+lidx<=lend){
        int Lidx = lstart+lidx;
            tmp[idx]=arr[Lidx];
            if(Lidx>start+idx){
                cnt+=Lidx-(idx+start);
            }
            idx++;
            lidx++;
    }
    while(rstart+ridx<=rend){
         int Ridx = rstart+ridx;
        tmp[idx]=arr[Ridx];
        if(Ridx>start+idx){
            cnt+=Ridx-(idx+start);
        }
        idx++;
        ridx++;
    }
    for(int i=0;i<end-start+1;i++){
        arr[start+i]=tmp[i];
    }


}
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0,n-1);
    cout<<cnt;


}