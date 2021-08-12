#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define ll long long
#define TP tuple<ll, int, int> //정점 ,거리 리프트 이용값

struct compare{
    bool operator()(TP a, TP b){
        return get<0>(a)<get<0>(b);
    }
};
typedef struct Vertex
{
    vector<tuple<int, int, int>> E;
    vector<tuple<int, int, int>> L;
    ll dist[11];
    int visit[11];
} Vertex;
class Graph
{
public:
    Vertex V[100001];
};
int N, M, K, S, T; //s가 스타트 t가 도착 지점.
Graph G;

void getG()
{
    int a, b, c;

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=K;j++)
        {
            G.V[i].dist[j]=-1;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        G.V[a].E.push_back(make_tuple(a, b, c));
        G.V[b].L.push_back(make_tuple(b, a, 0));
    }
}

void Dj()
{
    priority_queue<TP, vector<TP>, compare> PQ;
    G.V[S].visit[0] = 1;
    PQ.push(make_tuple(0, S, 0));

    while (!PQ.empty())
    {
        //cout << "!!!\n";
        TP curTP = PQ.top();
        PQ.pop();

        ll curD = get<0>(curTP);
        int curV = get<1>(curTP);
        int curK = get<2>(curTP);
        
        //cout << "curD: " << curD << " curV: " << curV << " curK: " << curK << "\n";

        for (tuple<int, int, int> e : G.V[curV].E) //슬로프
        {
            int tarV = get<1>(e);
            if (G.V[tarV].dist[curK] < curD + get<2>(e))
            {
                G.V[tarV].dist[curK] = curD + get<2>(e);
                PQ.push(make_tuple(G.V[tarV].dist[curK], tarV, curK));
                //cout<<"OOO!!\n";
            }
        }
        if (curK < 10)
        {
            for (tuple<int, int, int> e : G.V[curV].L) //리프트
            {
                int tarV = get<1>(e);
                if (G.V[tarV].dist[curK]<curD&&G.V[tarV].dist[curK + 1] < curD)
                {
                    G.V[tarV].dist[curK + 1] = curD;
                    PQ.push(make_tuple(curD, tarV, curK + 1));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K >> S >> T;

    getG();
    Dj();
    int MMAx = -1;

    for (int i = 0; i <= K; i++)
    {
        if (G.V[T].dist[i] > MMAx)
            MMAx = G.V[T].dist[i];
    }
    
        cout << MMAx;
  

    return 0;
}



{
    char str[];
    char *p,*q;
    for(p=str;*p!=0;p++)
    {
        for(q=p;*q!=0;q++)
        {
            if(*q==' '||*q==0)
            {
                

                //actions


                p=q;
                break;
            }
        }
    }







}









/*#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define ll long long
#define TP tuple<ll, int, int> //정점 ,거리 리프트 이용값

typedef struct Vertex
{
    vector<tuple<int, int, int>> E;
    vector<tuple<int, int, int>> L;
    ll dist[11];
    int visit[11];
} Vertex;
class Graph
{
public:
    Vertex V[100001];
};
int N, M, K, S, T; //s가 스타트 t가 도착 지점.
Graph G;

void getG()
{
    int a, b, c;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        G.V[a].E.push_back(make_tuple(a, b, c));
        G.V[a].L.push_back(make_tuple(b, a, 0));
    }
}

void Dj()
{
    priority_queue<TP, vector<TP>, less<TP>> PQ;
    G.V[S].visit[0] = 1;
    PQ.push(make_tuple(0, S, 0));
    while (!PQ.empty())
    {
        cout << "!!!\n";
        TP curTP = PQ.top();
        PQ.pop();

        ll curD = get<0>(curTP);
        int curV = get<1>(curTP);
        int curK = get<2>(curTP);

        cout << "curD: " << curD << " curV: " << curV << " curK: " << curK << "\n";

        for (tuple<int, int, int> e : G.V[curV].E) //슬로프
        {
            int tarV = get<1>(e);
            if (G.V[tarV].dist[curK] < G.V[curV].dist[curK] + get<2>(e))
            {
                G.V[tarV].dist[curK] = G.V[curV].dist[curK] + get<2>(e);
                PQ.push(make_tuple(G.V[tarV].dist[curK], tarV, curK));
                //cout<<"OOO!!\n";
            }
        }
        if (curK < 10)
        {
            for (tuple<int, int, int> e : G.V[curV].L) //리프트
            {
                int tarV = get<1>(e);
                if (G.V[tarV].dist[curK + 1] < G.V[curV].dist[curK])
                {
                    G.V[tarV].dist[curK + 1] = G.V[curV].dist[curK];
                    PQ.push(make_tuple(G.V[tarV].dist[curK + 1], tarV, curK + 1));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K >> S >> T;

    getG();
    Dj();
    int MMAx = 0;

    for (int i = 0; i <= K; i++)
    {
        if (G.V[T].dist[i] > MMAx)
            MMAx = G.V[T].dist[i];
    }
    if (MMAx)
        cout << MMAx;
    else
        cout << -1;

    return 0;
}*/