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
  const int N = 3e5 + 5;
 int seg[4 * N], lazy[4 * N];
 void push(int node, int st, int ed){
    if(!lazy[node]) return;
     seg[node] = lazy[node];
    if(st != ed){
        lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
    }
     lazy[node] = 0;
}
 void update(int node, int st, int ed, int &l, int &r, int &val){
    push(node, st, ed);
    if(st > r || ed < l) return;
    if(st >= l && ed <= r){
        lazy[node] = val;
        push(node, st, ed);
        return;
    }
     int mid = (st + ed) >> 1;
    update(node * 2, st, mid, l, r, val);
    update(node * 2 + 1, mid + 1, ed, l, r, val);
}
 int query(int node, int st, int ed, int &index){
    push(node, st, ed);
    if(st > index || ed < index) return 0;
    if(st == ed) return seg[node];
     int mid = (st + ed) >> 1;
    if(index <= mid) return query(node * 2, st, mid, index);
    return query(node * 2 + 1, mid + 1, ed, index);
}
 int n;
 void update(int l, int r, int val){
    update(1, 1, n, l, r, val);
}
 int query(int index){
    return query(1, 1, n, index);
}
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int m; cin >> n >> m;
    vector<vector<int>> a(m);
     for(auto &i: a){
        int l, r, winner; cin >> l >> r >> winner;
        i = {l, r, winner};
    }
    reverse(all(a));
    for(auto &v: a){
        int l = v[0], r = v[1], winner = v[2];
        if(l != winner) update(l, winner - 1, winner);
        if(r != winner) update(winner + 1, r, winner);
    }
    for(int i = 1; i <= n; i++)
        cout << query(i) << " ";
    return 0;
}