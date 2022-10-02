#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
struct DSU{
    const static int N = 26 + 5; //nodes
 
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
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        string t;
        cin >> n >> t;
        map<char, char> mp;
        string s = t;
        vector<bool> used(26);
        DSU dsu(26);
 
        int last = 0, usedCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mp.count(t[i])) s[i] = mp[t[i]];
            else{
                char c = '?';
                for (int j = 0; ; j = (j + 1) % 26) {
                    if (!used[j]){
                        char x = char (j + 'a');
                        if (x != t[i]
                            && ((mp.count(x) == 0 || mp[x] != t[i])
                                && (!dsu.sameGroup(x - 'a', t[i] - 'a') || usedCnt == 25))){
                            c = x;
                            last = j;
                            usedCnt++;
                            dsu.mergeGroups(x - 'a', t[i] - 'a');
                            break;
                        }
                    }
                }
//                cout << i << " " << t[i] << " char is " << c << endl << flush;
                used[c - 'a'] = 1;
                s[i] = c;
                mp[t[i]] = c;
            }
        }
        cout << s << endl;
    }
    return 0;
}
 
   