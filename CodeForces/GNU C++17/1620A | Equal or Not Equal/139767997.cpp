#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
 
struct DSU{
    const static int N = 50 + 5; //nodes
 
    int parent[N], groupSize[N];
    int groupCnt;
 
    DSU(int n){
        groupCnt = n;
        for(int i = 0; i < n; ++i){
            parent[i] = i;
            groupSize[i] = 1;
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
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        int n = s.size();
        DSU dsu(n + 3);
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'E'){
                dsu.mergeGroups(i, (i + 1) % n);
            }
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'E' && !dsu.sameGroup(i, (i + 1) % n)) ok = 0;
            else if(s[i] != 'E' && dsu.sameGroup(i, (i + 1) % n)) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}