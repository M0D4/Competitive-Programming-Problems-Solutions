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


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n], dp[n] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i){
            bool x = a[i] < 0, y = a[i + 1] < 0;
           if(x != y) dp[i] = 1 + dp[i + 1];
           else dp[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}