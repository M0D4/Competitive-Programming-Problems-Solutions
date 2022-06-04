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
  int step(int cur, int x){
    if(cur - x > 0)
        return cur - x;
    return cur + x;
}
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
        ll n, k, s; cin >> n >> k >> s;
     if (k > s || (n - 1) * k < s)
        return cout << "NO", 0;
     cout << "YES\n";
    int cur = 1;
    for (int i = k; i; --i) {
        ll mn = min(n - 1, s - (i - 1));
        cur = step(cur, mn);
        s -= mn;
        cout << cur << " ";
    }
    return 0;
}