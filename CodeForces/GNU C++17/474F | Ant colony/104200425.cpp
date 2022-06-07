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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
 
const int N = 1e5 + 5;
 
int a[N], n, g[4 * N];
vector<int> cnt[4 * N];
 
void build(int node, int st, int ed){
    if(st == ed){
        g[node] = a[st];
        cnt[node].push_back(a[st]);
        return;
    }
 
    build(node * 2, st, (st + ed) / 2);
    build(node * 2 + 1, (st + ed) / 2 + 1, ed);
 
    g[node] = __gcd(g[node * 2], g[node * 2 + 1]);
    merge(all(cnt[node * 2]), all(cnt[node * 2 + 1]), back_inserter(cnt[node]));
}
 
int getGcd(int node, int st, int ed, int &l, int &r){
    if(st >  r || ed < l) return 0;
 
    if(st >= l && ed <= r) return g[node];
 
    return __gcd(getGcd(node * 2, st, (st + ed) / 2, l, r),
                 getGcd(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r));
}
 
int getGcd(int l, int r){
    return getGcd(1, 0, n - 1, l, r);
}
 
int query(int node, int st, int ed, int &l, int &r, int &val){
    if(st >  r || ed < l) return 0;
 
    if(st >= l && ed <= r){
        auto it = lower_bound(all(cnt[node]), val);
 
        int left = it - cnt[node].begin();
 
        it = upper_bound(all(cnt[node]), val);
        it--;
 
        int right = it - cnt[node].begin();
 
        return (ed - st) - (right - left);
    }
 
    return (query(node * 2, st, (st + ed) / 2, l, r, val) +
            query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r, val));
}
 
int query(int l, int r, int val){
    return query(1, 0, n - 1, l, r, val);
}
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n;
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
   build(1, 0, n - 1);
 
    int q; cin >> q;
 
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        int val = getGcd(l, r);
        cout << query(l, r, val) << endl;
    }
    return 0;
}