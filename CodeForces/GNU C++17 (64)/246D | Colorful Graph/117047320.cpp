#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m; cin >> n >> m;
    int a[n + 1];
    unordered_map<int, vector<int>> vk;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vk[a[i]].push_back(i);
    }
    vector<vector<int>> ad(n + 1);
    while(m--){
        int u, v; cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    int mx = 0, mxColor = INT_MAX;
    for(auto color : vk){
        unordered_map<int, bool> mp;
        for(auto member: color.second){
            for(auto &neighbour : ad[member]){
                if(a[neighbour] != a[member]) mp[a[neighbour]] = 1;
            }
        }
        if(mp.size() == mx && color.first < mxColor) mxColor = color.first;
        else if(mp.size() > mx){
            mx = mp.size();
            mxColor = color.first;
        }
    }
    cout << mxColor;
    return 0;
}