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




int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    map<int, int> f;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        f[x]++;
    }
    ll sum = 0;
    for (int i = -200; i <= 200; ++i) {
        for (int j = i + 1; j <= 200; ++j) {
            sum += 1LL * f[i] * f[j] * (i - j) * (i - j);
        }
    }
    cout << sum;
    return 0;
}