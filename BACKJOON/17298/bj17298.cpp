#include<iostream>
#include<stack>

using namespace std;

int arr[1000000];
int NGE[1000000];
int n;
stack<int>S;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int input;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        arr[i]=input;
    }
//새로 들어오는 애들보다 작은 애들은 스택안에 있을 필요가 없다.
    int target;
    for(int i=n-1;i>=0;i--)
    {
        target=arr[i];
        while(!S.empty()&&S.top()<=target)
        {
            S.pop();
        }
        
        if(S.empty())NGE[i]=-1;
        else NGE[i]=S.top();
        
        S.push(target);
    }

    
    for(int i=0;i<n;i++)
    {
        cout<<NGE[i]<<" ";
    }


}