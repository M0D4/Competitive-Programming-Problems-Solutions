#include "bits/stdc++.h"


#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")


using namespace std;

#define endl            "\n"
#define all(x)          (x).begin(), (x).end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(x.begin(), x.end()), x.end())
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
    int clz = __builtin_clzll(n);
    ll sum = 0;
    for (int i = 0; i < 64 - clz; ++i) {
        sum += (1LL << i);
    }
    cout << sum;
    return 0;
}