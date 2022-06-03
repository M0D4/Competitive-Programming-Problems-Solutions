#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

const int N = 3e2 + 5;
int x, y;

int a[N], b[N], dp[N][N][N], n;

int go(int i, int xi, int yi){
    if(i == n){
        return (xi < x || yi < y) * (n + 1);
    }

    int& ret = dp[i][min(xi, 300)][min(yi, 300)];
    if(~ret) return ret;

    ret = go(i + 1, xi, yi);
    ret = min(ret, 1 + go(i + 1, xi + a[i], yi + b[i]));

    return ret;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    clr(dp, -1);

    int ans = go(0, 0, 0);
    cout << (ans <= n ? ans : -1);
    return 0;
}

