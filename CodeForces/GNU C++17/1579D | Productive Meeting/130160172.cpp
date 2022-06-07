#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        pair<int, int> a[n];
        priority_queue<pii> q;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i + 1;
            if(a[i].first)
                q.push(a[i]);
        }
 
        ll talks = 0;
        vector<vector<int>> ans;
        while (!q.empty()){
            int u, i; tie(u, i) = q.top();
            q.pop();
            if(q.empty()) break;
            int v, j; tie(v, j) = q.top();
            q.pop();
 
            talks++;
            ans.push_back({i, j});
            --v, --u;
            if(u) q.push({u, i});
            if(v) q.push({v, j});
        }
 
        cout << ans.size() << endl;
        for(auto& v: ans){
            for(auto& i: v){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
 