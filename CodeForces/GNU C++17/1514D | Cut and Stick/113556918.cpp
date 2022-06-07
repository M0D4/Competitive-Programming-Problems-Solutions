#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;
 
const int N = 3e5 + 5;
int seg[N << 2], a[N];
vector<int> pos[N];
 
int cnt(int l, int r, int x){
    return upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
}
 
void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = a[st];
        return;
    }
 
    int mid = (st + ed) >> 1;
    build(node << 1, st, mid);
    build(node << 1 | 1, mid + 1, ed);
 
    seg[node] = (cnt(st, ed, seg[node << 1]) > cnt(st, ed, seg[node << 1 | 1])
                ? seg[node << 1] : seg[node << 1 | 1]);
}
 
int query(int node, int st, int ed, int& l, int& r){
    if(st > r || ed < l) return 0;
 
    if(st >= l && ed <= r){
        return cnt(l, r, seg[node]);
    }
 
    int mid = (st + ed) >> 1;
    int lq = query(node << 1, st, mid, l, r);
    int rq = query(node << 1 | 1, mid + 1, ed, l, r);
 
    return max(lq, rq);
}
 
int n, q;
 
int query(int l, int r){
    return query(1, 0, n - 1, l, r);
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
 
    build(1, 0, n - 1);
 
    while (q--){
        int l, r; cin >> l >> r;
        --l, --r;
        int len = r - l + 1, mx = query(l, r);
        cout << max(1, 2 * mx - len) << endl;
    }
    return 0;
}