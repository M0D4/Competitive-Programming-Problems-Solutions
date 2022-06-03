#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

struct DSU{

    const static int N = 2e5 + 5; //nodes

    int parent[N], groupSize[N];
    int groupCnt;

    DSU(int n){
        groupCnt = n;
        for(int i = 0; i < n; i++){
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


struct Kruskal{
    int n, m; //nodes, edges
    ll MSP_cost = 0, total = 0;

    vector<tuple<int, int, int>> edgeList;
    Kruskal(){
        cin >> n >> m;
        DSU dsu(n);
        edgeList.clear(), edgeList.resize(m);
        for(int i = 0; i < m; i++){
            int u, v, w; cin >> u >> v >> w;
            --u, --v; //if 1-indexed
            if(w >= 0) total += w;
            edgeList[i] = tie(w, u, v);
        }
        sort(all(edgeList));//sort by w

        for(int i = 0; i < m; i++){
            int w, u, v; tie(w, u, v) = edgeList[i];
            if(!dsu.sameGroup(u, v)){//will not cause a cycle
                if(w >= 0) MSP_cost += w;
                dsu.mergeGroups(u, v);
            }
        }
    }

    ll getMSP_cost(){
        return total - MSP_cost;
    }
};

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    Kruskal k;
    cout << max(0LL, k.getMSP_cost());
    return 0;
}

