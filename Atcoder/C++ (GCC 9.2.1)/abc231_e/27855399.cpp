#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 60 + 5;
ll x, n, a[N];
map<pair<int, ll>, ll> dp;

ll go(int i, ll rem){
    if(rem % a[i] == 0)
        return rem / a[i];

    if(dp.count({i, rem}))
        return dp[{i, rem}];

    ll& ret = dp[{i, rem}];
    ll want = rem / a[i];
    ret = want + go(i - 1, rem - want * a[i]);
    ret = min(ret, want + 1 + go(i - 1, (want + 1) * a[i] - rem));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << go(n - 1, x);
    return 0;
}