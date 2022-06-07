#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
const int N = 100 + 5;
 
int a[N], b[N], seg[4 * N], ans[N];
 
void build(int node, int st, int ed){
    if(st == ed){
        seg[node] = a[st];
        return;
    }
 
    int mid = (st + ed) >> 1;
    build(node * 2, st, mid);
    build(node * 2 + 1, mid + 1, ed);
 
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
 
int query(int node, int st, int ed, int& l, int& r){
    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r){
        return seg[node];
    }
    int mid = (st + ed) >> 1;
    return max(
        query(node * 2, st, mid, l, r),
        query(node * 2 + 1, mid + 1, ed, l, r)
    );
}
 
int n;
int query(int l, int r){
    return query(1, 1, n, l, r);
}
 
void solve(int l, int r){
    if(l > r)
        return;
    int mx = query(l, r);
    int pos = b[mx];
    ans[l]++;
    ans[pos]--;
    ans[pos + 1]++;
    ans[r + 1]--;
    solve(l, pos - 1);
    solve(pos + 1, r);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ans[i] = 0;
            b[a[i]] = i;
        }
        build(1, 1, n);
        solve(1, n);
        for (int i = 1; i <= n; ++i) {
            ans[i] += ans[i - 1];
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}