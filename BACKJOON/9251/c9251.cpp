#include<iostream>
#include<string>

using namespace std;
string a;
string b;
int arr[1000];

int p,q;
int main(){
    cin>>a;
    cin>>b;

    for(int i=0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            if(!arr[j]&&a[i]==b[j])
            {
                arr[j]=i;
                break;
            }
        }
    }

    int pivot=1000;
    string tmp="";
    for(int i=999;i>=0;i--)
    {
        if(arr[i]==0)continue;
        if(pivot>arr[i])
        {
            tmp.push_back(b[i]);
            pivot=arr[i];
        }
    }
    
    cout<<tmp.length();
    
    return 0;
}