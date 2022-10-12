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
 
const int N = 4e5 + 5;
 
int seg[4 * N], lazy[4 * N], n, idx;
 
void push(int node, int start, int end){
    if (!lazy[node]) return;
 
    seg[node] += lazy[node] * (end - start + 1);
 
    if(start != end){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
 
    lazy[node] = 0;
}
 
void update(int node, int start, int end, int &l, int &r, int &val){
    push(node, start, end);
 
    if(start > r || end < l) return;
 
    if(start >= l && end <= r){
        lazy[node] = val;
        push(node, start, end);
        return;
    }
 
    update(node * 2, start, (start + end) / 2, l, r, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, l, r, val);
 
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
 
void update(int l, int r, int val){
    update(1, 0, idx - 1, l, r, val);
}
 
int query(int node, int start, int end, int &l, int &r){
    push(node, start, end);
 
    if(start > r || end < l) return 0;
    if(start >= l && end <= r) return seg[node];
 
    return query(node * 2, start, (start + end) / 2, l, r) +
           query(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
}
 
int query(int l, int r){
    return query(1, 0, idx - 1, l, r);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        cin >> n;
        for (int i = 0; i <= 4 * 2 * n; ++i) {
            seg[i] = lazy[i] = 0;
        }
 
        map<int, int> mp;
        idx = 0;
        vector<vector<int>> groups[n + 1];
        multiset<int> lefts, rights;
        for (int i = 0; i < n; ++i) {
            int l, r, c;
            cin >> l >> r >> c;
            lefts.insert(l);
            rights.insert(r);
            mp[l];
            mp[r];
            groups[c].push_back({l, r, i});
        }
 
        for (auto& it: mp){
            it.second = idx++;
        }
 
        for (int i = 1; i <= n; ++i) {
            if (groups[i].empty()) continue;
            for(auto& v: groups[i]){
                int l = mp[v[0]], r = mp[v[1]];
                update(l, r, 1);
            }
        }
 
        vector<int> ans(n, -1);
        for (int i = 1; i <= n; ++i) {
            if (groups[i].empty()) continue;
            for(auto& v: groups[i]){
                int l = mp[v[0]], r = mp[v[1]];
                update(l, r, -1);
            }
            for(auto& v: groups[i]){
                int l = mp[v[0]], r = mp[v[1]], ii = v[2];
                if (query(l, r)) ans[ii] = 0;
            }
            for(auto& v: groups[i]){
                int l = mp[v[0]], r = mp[v[1]];
                update(l, r, 1);
            }
        }
 
        for (int i = 1; i <= n; ++i) {
            for(auto& v: groups[i]){
                lefts.erase(lefts.find(v[0]));
                rights.erase(rights.find(v[1]));
            }
            for(auto& v: groups[i]){
                if (ans[v[2]] != -1) continue;
                int l = v[0], r = v[1], ii = v[2];
 
                auto it = lefts.lower_bound(r);
                ll mnL = (it != lefts.end() ? *it : 1e15);
 
                ll mxR = -1e15;
                it = rights.upper_bound(l);
                if (it != rights.begin()){
                    --it;
                    mxR = *it;
                }
                ans[ii] = min(mnL - r, l - mxR);
            }
            for(auto& v: groups[i]){
                lefts.insert((v[0]));
                rights.insert((v[1]));
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}