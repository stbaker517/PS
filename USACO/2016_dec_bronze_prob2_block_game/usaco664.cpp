// https://usaco.org/index.php?page=viewproblem2&cpid=664
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;

int alphabet[26];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        // s1
        int arr1[26] = {0};
        int arr2[26] = {0};

        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
        }
         for(int i=0;i<s2.size();i++){
            arr2[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            alphabet[i] += max(arr1[i],arr2[i]);
        }
    }


    for(int i=0;i<26;i++){
        cout<<alphabet[i]<<'\n';
    }
    return 0;
}