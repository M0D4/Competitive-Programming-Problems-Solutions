#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;

const int N = 1e5 + 5;

int n, a[N], dp[N][2];

int go(int i, bool pos){
    if(i == n) return 0;

    int&ret = dp[i][pos];
    if (~ret) return ret;

    ret = 0;
    if (pos && a[i] > 0) ret = 1 + go(i + 1, 0);
    else if(!pos && a[i] < 0) ret = 1 + go(i + 1, 1);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << 1 + go(i + 1, a[i] < 0) << " ";
        }
        cout << endl;
    }
    return 0;
}