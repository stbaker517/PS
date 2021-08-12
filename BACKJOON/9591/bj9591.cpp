#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<stack>
#include<cmath>

using namespace std;

vector<tuple<int,int,int>>Vec;
double dist[200];
bool visit[200];
int pprev[200];
int n,m,q;


typedef struct Vertice{
    vector<tuple<double,int,int>>E;
}Vertice;

Vertice V[200];



struct comp{
    bool operator()(tuple<double,int,int>&a, tuple<double,int,int>&b){
       return get<0>(a)>get<0>(b);
    }
};

void djikstra(int s,int end)
{
    for(int i=0;i<200;i++)
        {
            dist[i]=1.7976931348623157E308;
            visit[i]=false;
        }
    
    dist[s]=0;
    //visit[s]=true;

    priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,comp>PQ;
    PQ.push({0.0,s,s});
    pprev[s]=s;

    //cout<<"여기까지 되나?";
    while(!PQ.empty())
    {

        int curV=get<1>(PQ.top());
        int preV=get<2>(PQ.top());
        double curD=get<0>(PQ.top());
        PQ.pop();

        if(visit[curV])continue;
        //cout<<"curV: "<<curV<<" preV: "<<preV<<"\n";//TEST
        

        pprev[curV]=preV;
        visit[curV]=true;
        
        /*
        for(int i=0;i<n;i++)//TEST
        {
            cout<<dist[i]<<" ";
        }
        cout<<"\n";
        */

        if(curV==end)break;

        for(tuple<double,int,int>e:V[curV].E)
        {
            double eD=get<0>(e);
            int u=get<1>(e);
            int v=get<2>(e);

            if(dist[v]>dist[u]+eD)
            {
                dist[v]=dist[u]+eD;
                PQ.push(make_tuple(dist[v],v,u));
                
            }
        }
    }

    //cout<<"here1\n";
    int tmp=end;
    //S.push(tmp);
    stack<int>S;
    while(tmp!=pprev[tmp])
    {
        S.push(tmp);
        tmp=pprev[tmp];
    }
    if(S.top()!=tmp)S.push(tmp);
    //cout<<"here2\n";

    //cout<<"ANS: ";
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
    //cout<<"here3\n";
    cout<<"\n";
    
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    cin>>n>>m;
    int z,x,y;

   
    for(int i=0;i<n;i++)
    {
        cin>>z>>x>>y;
        Vec.push_back(make_tuple(z,x,y));
    }

    string str;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>str;
        /*if(str.compare("walking")==0)
        {
            double dist=sqrt(x*x+y*y);
            V[x].E.push_back(make_tuple(sqrt(x*x+y*y),x,y));
            V[y].E.push_back(make_tuple(sqrt(x*x+y*y),y,x));
        }
        else*/
        if(str.compare("lift")==0)
        {

            V[x].E.push_back(make_tuple(1,x,y));
            V[y].E.push_back(make_tuple(1,y,x));
        }
        else if(str.compare("escalator")==0)
        {
            int X=get<1>(Vec[x])-get<1>(Vec[y]);
            int Y=get<2>(Vec[x])-get<2>(Vec[y]);
            int Z=5*(get<0>(Vec[x])-get<0>(Vec[y]));

            V[x].E.push_back(make_tuple(1,x,y));
            V[y].E.push_back(make_tuple(sqrt(X*X+Y*Y+Z*Z)*3,y,x));
        }
        else{
            
            int X=get<1>(Vec[x])-get<1>(Vec[y]);
            int Y=get<2>(Vec[x])-get<2>(Vec[y]);
            int Z=5*(get<0>(Vec[x])-get<0>(Vec[y]));
            V[x].E.push_back(make_tuple(sqrt(X*X+Y*Y+Z*Z),x,y));
            V[y].E.push_back(make_tuple(sqrt(X*X+Y*Y+Z*Z),y,x));
        }
    }

    //다익
    
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        djikstra(x,y);
    }


}