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

    ll a, b, c; cin >> a >> b >> c;
    ll l = 1, r = 1e9, ans = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if(isless(1.0 * mid / c, 1.0 * b / a)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}