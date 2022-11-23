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
    int mx;
 
    Vertex(){
        mx = 0;
    }
    Vertex(int x){
        mx = x;
    }
    Vertex(Vertex x, Vertex y){
        mx = max(x.mx, y.mx);
    }
};
 
const int N = 2e5 + 5;
 
Vertex seg[N << 2];
 
void update(int node, int st, int ed, int& index, int& val){
    if(st > index || ed < index) return;
    if(st == ed){
        seg[node] = Vertex(val);
        return;
    }
 
    int mid = (st + ed) >> 1;
    update(node << 1, st, mid, index, val);
    update(node << 1 | 1, mid + 1, ed, index, val);
 
    seg[node] = Vertex(seg[node << 1], seg[node << 1 | 1]);
}
 
Vertex query(int node, int st, int ed, int& l, int& r){
    if(st > r || ed < l) return 0;
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
    update(1, 0, n - 1, index, val);
}
 
int query(int l, int r){
    return query(1, 0, n - 1, l, r).mx;
}
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        ll c, d;
        cin >> n >> c >> d;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n, greater<>());
        auto can = [&](int k) -> bool {
            ll have = 0;
            for (int i = 1, j = 0; i <= d; ++i) {
                if (j < n) have += a[j];
                j = (j + 1) % (k + 1);
            }
            return have >= c;
        };
 
        int l = 0, r = d;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (can(mid)) l = mid + 1;
            else r = mid - 1;
        }
        if (l == 0) cout << "Impossible\n";
        else if (l - 1 == d) cout << "Infinity\n";
        else cout << l - 1 << endl;
    }
    return 0;
}