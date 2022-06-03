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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n; cin >> n;
    ll cnt = 0;
    for (int i = 1; i < n && i < 1000'000; ++i) {
        ll x = i;
        x *= pow(10, numOfDigits(x));
        x += i;
        if(x <= n) cnt++;
    }
    cout << cnt;
    return 0;
}