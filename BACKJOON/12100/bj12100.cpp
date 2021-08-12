#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int r;
void print(int **arr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int **push(int **arr, int dir)
{
    int **ret = new int *[r];
    for (int i = 0; i < r; i++)
    {
        ret[i] = new int[r];
        for(int j=0;j<r;j++)
        {
            ret[i][j]=0;
        }
    }
    if (dir == 0) //위
    {

        for (int j = 0; j < r; j++)
        {
            vector<int> vec;
            queue<int> Q;
            for (int i = 0; i < r; i++)
            {
                if (arr[i][j])
                {
                    vec.push_back(arr[i][j]);
                }
            }
            int idx = -1;
            for (int i = 0; i < vec.size(); i++)
            {
                if (i == vec.size() - 1)
                {
                    Q.push(vec[i]);
                }
                else if (vec[i] == vec[i + 1])
                {
                    Q.push(vec[i] * 2);
                    i++;
                }
                else
                {
                    Q.push(vec[i]);
                }
            }
            //cout<<"!!";//TEST
            while (!Q.empty())
            {
                ret[++idx][j] = Q.front();
                //cout<<"Q:"<<Q.front()<<" ";
                Q.pop();
            }
        }
    }
    else if (dir == 1) //아래
    {

        for (int j = 0; j < r; j++)
        {
            vector<int> vec;
            queue<int> Q;
            for (int i = r - 1; i >= 0; i--)
            {
                if (arr[i][j])
                {
                    vec.push_back(arr[i][j]);
                }
            }

            for (int i = 0; i < vec.size(); i++)
            {
                if (i == vec.size() - 1)
                {
                    Q.push(vec[i]);
                }
                else if (vec[i] == vec[i + 1])
                {
                    Q.push(vec[i] * 2);
                    i++;
                }
                else
                {
                    Q.push(vec[i]);
                }
            }
            int idx = r;
            while (!Q.empty())
            {
                ret[--idx][j] = Q.front();
                Q.pop();
            }
        }
    }
    else if (dir == 2) //왼
    {

        for (int j = 0; j < r; j++)
        {
            vector<int> vec;
            queue<int> Q;
            for (int i = 0; i < r; i++)
            {
                if (arr[j][i])
                {
                    vec.push_back(arr[j][i]);
                }
            }

            for (int i = 0; i < vec.size(); i++)
            {
                if (i == vec.size() - 1)
                {
                    Q.push(vec[i]);
                }
                else if (vec[i] == vec[i + 1])
                {
                    Q.push(vec[i] * 2);
                    //cout<<"yesy";
                    i++;
                }
                else
                {
                    Q.push(vec[i]);
                }
            }
            int idx = -1;
            while (!Q.empty())
            {
                ret[j][++idx] = Q.front();
                Q.pop();
            }
        }
    }
    else
    {

        for (int j = 0; j < r; j++)
        {
            vector<int> vec;
            queue<int> Q;
            for (int i = r - 1; i >= 0; i--)
            {
                if (arr[j][i])
                {
                    vec.push_back(arr[j][i]);
                }
            }

            for (int i = 0; i < vec.size(); i++)
            {
                if (i == vec.size() - 1)
                {
                    Q.push(vec[i]);
                }
                else if (vec[i] == vec[i + 1])
                {
                    Q.push(vec[i] * 2);
                    //cout<<"yes";
                    i++;
                }
                else
                {
                    Q.push(vec[i]);
                }
            }
            int idx = r;
            while (!Q.empty())
            {
                ret[j][--idx] = Q.front();
                Q.pop();
            }
        }
    }
    // print(ret);
    return ret;
}

int Max = 0;
void func(int n, int **box)
{
    //cout << n << "\n";//TEST
    //print(box);//TEST
    if (n == 5)
    {
        //맥스 체크
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (box[i][j] > Max)
                    Max = box[i][j];
            }
        }
        //cout << "max:" << Max << "\n";//TEST
        return;
    }

    for (int i = 0; i < 4; i++)
    {

        int **nmap = push(box, i);

        //print(nmap);
        func(n + 1, nmap);
        //i=0 위 i=1 아래 i=2 왼 i=3 오
    }
}
int main()
{
    int **map;
    cin >> r;
    map = new int *[r];

    for (int i = 0; i < r; i++)
    {
        map[i] = new int[r];
        for (int j = 0; j < r; j++)
        {
            cin >> map[i][j];
        }
    }

    func(0, map);
    cout << Max;

    return 0;
}