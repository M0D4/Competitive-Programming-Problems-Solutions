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
 
struct Vertex{
    int sum, idx;
 
    Vertex(){
        sum = 0;
        idx = 0;
    }
    Vertex(int x, int i){
        sum = x;
        idx = i;
    }
    Vertex(Vertex x, Vertex y){
        sum = max(x.sum, y.sum);
        if (sum == x.sum) idx = x.idx;
        else idx = y.idx;
    }
};
 
const int N = 2e5 + 2;
 
Vertex seg[N << 2];
 
void update(int node, int st, int ed, int& index, int& val){
    if(st > index || ed < index) return;
    if(st == ed){
        seg[node] = Vertex(val, index);
        return;
    }
 
    int mid = (st + ed) >> 1;
    update(node << 1, st, mid, index, val);
    update(node << 1 | 1, mid + 1, ed, index, val);
 
    seg[node] = Vertex(seg[node << 1], seg[node << 1 | 1]);
}
 
Vertex query(int node, int st, int ed, int& l, int& r){
    if(st > r || ed < l) return {0, 0};
    if(st >= l && ed <= r){
        return seg[node];
    }
 
    int mid = (st + ed) >> 1;
    Vertex lq = query(node << 1, st, mid, l, r);
    Vertex rq = query(node << 1 | 1, mid + 1, ed, l, r);
 
    return Vertex(lq, rq);
}
 
int n;
 
void update(int index, int val){
    update(1, 0, n, index, val);
}
 
Vertex query(int l, int r){
    return query(1, 0, n, l, r);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        vector<int> a(n / 2);
        int f[n + 1] = {};
 
        for (int i = 0; i <= 4 * n; ++i) {
            seg[i] = Vertex();
        }
        for (int i = 0; i < n / 2; ++i) {
            cin >> a[i];
            f[a[i]] = 1;
            update(a[i], i + 1);
        }
        bool ok = 1;
        vector<vector<int>> v;
        for (int i = n; i > 0; --i) {
            if (!f[i]){
                auto q = query(i, n);
                int idx = q.sum;
                if (idx == 0){
                    ok = 0;
                    break;
                }
                int mn = i, mx = a[idx - 1];
                if (mn > mx) swap(mn, mx);
                v.push_back({idx - 1, mn, mx});
                update(q.idx, 0);
            }
        }
        if (!ok){
            cout << "-1\n";
            continue;
        }
        sort(all(v));
        for (int i = 0; i < n / 2; ++i) {
            cout << v[i][1] << " " << v[i][2] << " ";
        }
        cout << endl;
    }
    return 0;
}