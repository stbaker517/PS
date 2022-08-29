#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define ll long long
#define tlll tuple<ll, ll, ll>
#define pll pair<ll, ll>

int n;

typedef struct cmpX
{
    bool operator()(tlll a, tlll b)
    {
        return get<0>(a) < get<0>(b);
    }
} cmpX;
typedef struct cmpY
{
    bool operator()(tlll a, tlll b)
    {
        return get<1>(a) < get<1>(b);
    }
} cmpY;
typedef struct cmpZ
{
    bool operator()(tlll a, tlll b)
    {
        return get<2>(a) < get<2>(b);
    }
} cmpZ;
set<tlll, cmpX> setX;
set<tlll, cmpY> setY;
set<tlll, cmpZ> setZ;
void printTuple(tlll t)
{
    printf("%ld %ld %ld", get<0>(t), get<1>(t), get<2>(t));
    printf("\n");
}
ll getCost(tlll a, tlll b);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll x, y, z;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        setX.insert(make_tuple(x, y, z));
        setY.insert(make_tuple(x, y, z));
        setZ.insert(make_tuple(x, y, z));
    }
    for (auto i : setX)
    {

        printTuple(i);
    }
    printf("\n\n");
    for (auto i : setY)
    {
        printTuple(i);
    }
    printf("\n\n");
    for (auto i : setZ)
    {
        printTuple(i);
    }
    printf("\n\n");
}

ll getCost(tlll a, tlll b)
{
    return min(abs(get<0>(a) - get<0>(b)), min(abs(get<1>(a) - get<1>(b)), abs(get<2>(a) - get<2>(b))));
}