#include<iostream>
#include<queue>

using namespace std;

//10000만개짜리 배열 DFS100번해도 시간 한참 남음.


int r, c;
int map[100][100];
bool visit[100][100];
queue<pair<int, int>>Q;
queue<pair<int, int>>tQ;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int numC = 0;

bool willBeRot(int x, int y)
{
	int count=0;
	for (int i = 0;i < 4;i++)
	{
		int X = x + dx[i], Y = y + dy[i];
		if (map[X][Y] ==0&&visit[X][Y])count++;
	}
	if (count >= 1)return true;
	else return false;
}
void DFS() {
	int x = Q.front().first;
	int y = Q.front().second;
	Q.pop();
    //cout<<"DFS";
	for (int i = 0;i < 4;i++)
	{
		int X = x + dx[i], Y = y + dy[i];

		if (X < 0 || Y < 0 || X >= r || Y >= c)continue;
		if (visit[X][Y])continue;

		if (map[X][Y] !=1)
		{
			visit[X][Y] = true;
			Q.push({ X,Y });
		}
		else
		{
			visit[X][Y] = true;
            tQ.push({ X, Y });
			
		}
	}
}

void refresh() {
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			visit[i][j] = false;
            if(map[i][j]>1)map[i][j]=0;
		}
	}
}


void print() {
    cout<<"\n\nmap\n";
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
    /*cout<<"visit\n";
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/
}
int main() {
	cin >> r >> c;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> map[i][j];
			if (map[i][j])numC++;
		}
	}
	int day = 0;
    int daybefore=numC;
	while (numC>0) {
		Q.push({ 0, 0 });
		day++;
		while(!Q.empty())DFS();

		
		while (!tQ.empty())
		{
            //cout<<"tQ";
			int x = tQ.front().first;
			int y = tQ.front().second;
			tQ.pop();
            if(willBeRot(x,y))
			{map[x][y] = day+1;
			numC--;}
			//print();
		}
       
        if(numC)daybefore=numC;
		refresh();
		 //print();

	}
	cout << day<<"\n"<<daybefore;
}