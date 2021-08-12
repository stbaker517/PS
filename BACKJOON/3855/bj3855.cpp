#include <iostream>
#include <vector>
using namespace std;

vector<pair<float, float>> point;

float f(float);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s;
    float inx, iny;
    while (1)
    {
        cin >> s;
        if (!s)
            return;
        point.clear();
        for (int i = 0; i < s; i++)
        {
            cin >> inx >> iny;
            point.push_back(inx, iny);

            float L=-200000;
            float R=200000;

        }
    }

    return 0;
}

float f(float x)
{
    float max=0;
    float result;
    for(pair<float,float>p:point)
    {
        result=(x-p.first)*(x-p.first)+p.second*p.second;
        if(max<result)max=result;
    }
    return max;
    
}