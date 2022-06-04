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
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  const int N = 1e2 + 5;
 struct exam{
    int s, d, c, i;
    exam(): s(s), d(d), c(c), i(i){
     }
}a[N];
 int b[N];
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].s >> a[i].d >> a[i].c;
        b[a[i].d] = m + 1;
        a[i].i = i;
    }
    sort(a + 1, a + m + 1, [](exam& a, exam& b){
        return a.d < b.d;
    });
     for (int i = 1; i <= m; ++i) {
        int need = a[i].c, cur = 0;
        for (int j = a[i].s; j < a[i].d && cur < need; ++j) {
            if(!b[j])
                b[j] = a[i].i, cur++;
        }
        if(cur < need)
            return cout << -1, 0;
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " ";
    }
    return 0;
}