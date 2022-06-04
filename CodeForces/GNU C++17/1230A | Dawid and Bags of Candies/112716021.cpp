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
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int a[4], n = 4, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        int first = 0;
        for (int j = 0; j < n; ++j) {
            if((i >> j) & 1)
                first += a[j];
        }
        if(2 * first == sum)
            return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}