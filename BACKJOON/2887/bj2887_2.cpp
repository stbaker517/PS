#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;
#define tiii tuple<int,int,int>
#define pii pair<int,int>

map<int,vector<int>>Mx;
map<int,vector<int>>My;

vector<tiii>V[100000];

//좌표를 저장한 벡터.
//맵으로 처음에 좌표가 있는지 알게함.
//양 옆도 0이 되면 삭제.

