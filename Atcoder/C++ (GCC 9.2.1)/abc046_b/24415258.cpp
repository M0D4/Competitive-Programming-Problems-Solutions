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

const int N = 1e3 + 5;

ll dp[N][N], n, k;

ll go(int i, int last){
    if(i == n) return 1;

    ll& ret = dp[i][last];
    if(~ret) return ret;

    ret = 0;
    for (int j = 1; j <= k; ++j) {
        if(j != last) ret += go(i + 1, j);
    }

    return ret;
}

int main()
{


    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k + 1; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << go(0, 0);
    return 0;
}