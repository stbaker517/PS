#include<iostream>
#include<stack>

using namespace std;

stack<pair<int,int>>S;


//왼쪽은 value 오른쪽은 하나의 수가 몇번 연속됐는지.
//구간(현재 스택 안의 원소)의 max를 갱신시킨다.
//max가 갱신 되면 가장 큰 원소가 새로 들어온다는 뜻
// 그러면 전에 있던 스택 원소들은 쓸모가 없어짐 
//왜? 새로 들어온 시끼가 전에 있던 원소들을 다 가려버림
//그니까 max가 갱신되면 전에 있던 원소들을 싸그리 쌍 계산 해버리면 됨

//그러면 쌍 계산 알고리즘 구현이 필요함
//그리고 새로 들어오는 놈은 전에 있던 모든 놈들과 쌍을 이루게 돼있음.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    long long count=0;
    int input;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        
        
        if(!S.empty()&&S.top().first<input)
        {
            while(!S.empty()&&S.top().first<input)
            {
                 pair<int,int> tmp=S.top();
                  S.pop();
                    
                    
                    long long t_count=tmp.second;
                    t_count=t_count*(t_count-1)/2;

                    if(S.empty())count+=t_count+tmp.second;
                    else count+=t_count+tmp.second*2;
                }
            }
         
         if(!S.empty()&&S.top().first==input)
            S.top().second++;
         
         
        else S.push({input,1});
        

    }


   /* while(!S.empty())
    {
        cout<<S.top().first<<" "<<S.top().second<<'\n';
        S.pop();
    }*/

    
   while(!S.empty())
    {
        pair<int,int> tmp=S.top();
        S.pop();

        long long t_count=tmp.second;
       t_count=t_count*(t_count-1)/2;

        if(S.empty())count+=t_count;
        else count+=t_count+tmp.second;



    }
    //cout<<"ANS: ";
    cout<<count;
}