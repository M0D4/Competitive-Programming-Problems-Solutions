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
 int a[N], n;
  struct segTreeGCD{
     int seg[N * 4];
     void build(int node, int st, int ed){
        if(st == ed){
            seg[node] = a[st];
            return;
        }
         build(node * 2, st, (st + ed) / 2);
        build(node * 2 + 1, (st + ed) / 2 + 1, ed);
         seg[node] = __gcd(seg[node * 2], seg[node * 2 + 1]);
    }
     int query(int node, int st, int ed, int &l, int &r){
        if(st >  r || ed < l) return 0;
         if(st >= l && ed <= r) return seg[node];
         return __gcd(query(node * 2, st, (st + ed) / 2, l, r),
                     query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r));
    }
     int query(int l, int r){
       return query(1, 0, n - 1, l, r);
    }
};
 struct segTreeCount{
     vector<int> seg[N * 4];
     void build(int node, int st, int ed){
        if(st == ed){
            seg[node] = vector<int> (1, a[st]);
            return;
        }
         build(node * 2, st, (st + ed) / 2);
        build(node * 2 + 1, (st + ed) / 2 + 1, ed);
         merge(all(seg[node * 2]), all(seg[node * 2 + 1]), back_inserter(seg[node]));
    }
     int query(int node, int st, int ed, int &l, int &r, int &val){
        if(st >  r || ed < l) return 0;
         if(st >= l && ed <= r){
            auto it = lower_bound(all(seg[node]), val);
             int left = it - seg[node].begin();
             it = upper_bound(all(seg[node]), val);
            it--;
             int right = it - seg[node].begin();
             return (ed - st) - (right - left);
        }
         return (query(node * 2, st, (st + ed) / 2, l, r, val) +
                     query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r, val));
    }
     int query(int l, int r, int val){
       return query(1, 0, n - 1, l, r, val);
    }
};
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     cin >> n;
     for(int i = 0; i < n; i++) cin >> a[i];
     segTreeGCD gt;
    gt.build(1, 0, n - 1);
     segTreeCount ct;
    ct.build(1, 0, n - 1);
     int q; cin >> q;
     while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        int val = gt.query(l, r);
        cout << ct.query(l, r, val) << endl;
    }
    return 0;
}