#include<iostream>
#include<stack>
#include<vector>
#include<utility>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin>>n;
    //cout<<n;
    pair<int,int> p;
    stack<pair<int,int>> S;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        //cout<<i<<'\n';
        int input;
        
        cin>>input;
        vec.push_back(0);
        if(S.empty())
            
            S.push(make_pair(input,i));
        else{
            int count=0;
                while(S.size()>1&&input>=S.top().first){//자기보다 큰 녀석이 온다면?
                    //cout<<"dkdkdkdk   ";
                p=S.top();
                //cout<<"p:"<<p.first<<" "<<p.second<<'\n';
                S.pop();
                if(p.first<S.top().first)
                    vec[S.top().second]+=++count;
                //else count++;
                }
                
                S.push(make_pair(input,i));

                cout<<"input: "<<input<<'\n';
                for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
    cout<<'\n';
           
        }

    
    }



    //남은 녀석들 전부 계산하기.
    int cnt=0;
    while(S.size()>1)
    {
        p=S.top();
        S.pop();

        if(S.size()&&p.first<S.top().first)//&&p.first==S.top().first)
        {
            vec[S.top().second]+=++cnt;
        }
        else cnt=0;

    }
    //cout<<vec.size()<<'\n';
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
    cout<<'\n';
    long long count=0;
    for(int i=0;i<vec.size();i++)
    {
        count+=vec[i];
    }
    cout<<count;
    //cout<<'\n';

    return 0;
}