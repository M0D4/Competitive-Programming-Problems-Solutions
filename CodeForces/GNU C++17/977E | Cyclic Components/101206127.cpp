#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
const int N = 2e5 + 5; //nodes
 
bool isConnectedCycle[N];
int degree[N];
 
struct DSU{
 
 
    int parent[N], groupSize[N];
    int groupCnt;
 
    DSU(int n){
        groupCnt = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSize[i] = 1;
            isConnectedCycle[i] = 1;
            degree[i] = 0;
        }
    }
 
    int findLeader(int i){
        if(parent[i] == i) return i;
 
        return parent[i] = findLeader(parent[i]);
    }
 
    bool sameGroup(int x, int y){
        return findLeader(x) == findLeader(y);
    }
 
    void mergeGroups(int x, int y){//merge to one component
        int leaderX = findLeader(x);
        int leaderY = findLeader(y);
 
        if(leaderX == leaderY) return;
 
        groupCnt--;
 
        if(groupSize[leaderX] > groupSize[leaderY]){
            parent[leaderY] = leaderX;
            groupSize[leaderX] += groupSize[leaderY];
        }else{
            parent[leaderX] = leaderY;
            groupSize[leaderY] += groupSize[leaderX];
        }
    }
 
    int getSize(int x){//size of group
        return groupSize[findLeader(x)];
    }
};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int u, v; cin >> u >> v;
        --u, --v;
        dsu.mergeGroups(u, v);
        degree[u]++, degree[v]++;
    }
 
    for(int i = 0; i < n; i++){
        if(degree[i] != 2)
            isConnectedCycle[dsu.findLeader(i)] = 0;
    }
 
    int cc = 0;
    for(int i = 0; i < n; i++){
        if(isConnectedCycle[dsu.findLeader(i)])
            cc++, isConnectedCycle[dsu.findLeader(i)] = 0;
    }
 
    cout << cc;
    return 0;
}