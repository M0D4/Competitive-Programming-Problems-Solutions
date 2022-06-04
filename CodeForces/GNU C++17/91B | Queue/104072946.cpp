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
 int seg[4 * N], a[N];
map<int, int> mp;
 int query(int node, int st, int ed, int &l, int &r){
    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r){
        return seg[node];
    }
     int left = query(node * 2, st, (st + ed) / 2, l, r);
    int right = query(node * 2 + 1, (st + ed) / 2 + 1, ed, l, r);
     return max(left, right);
}
 void update(int node, int st, int ed, int &index, int &value){
    if(st > index || ed < index) return;
    if(st == ed){
        seg[node] = max(seg[node], value);
        return;
    }
     update(node * 2, st, (st + ed) / 2, index, value);
    update(node * 2 + 1, (st + ed) / 2 + 1, ed, index, value);
     seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}
  int n;
 int query(int l, int r){
    return query(1, 1, n, l, r);
}
 void update(int index, int value){
    update(1, 1, n, index, value);
}
int idx = 0;
int main()
{
//    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     scanf("%d", &n);
     for(int i = 0; i < n; i++) scanf("%d", &a[i]), mp[a[i]];
     for(auto &i: mp) i.second = ++idx;
     vector<int> v(n);
    for(int i = n - 1; ~i; i--){
        v[i] = max(query(1, mp[a[i]] - 1) - i - 2, -1);
        update(mp[a[i]], i + 1);
    }
     for(auto &i: v) printf("%d ", i);
    return 0;
}