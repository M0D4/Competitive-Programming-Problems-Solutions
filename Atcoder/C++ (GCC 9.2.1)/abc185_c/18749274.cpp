#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;

const int N = 205;

ll dp[N][N], n;

ll go(int c, int rem){
    if(c == 12) return rem == 0;

    ll &ret = dp[c][rem];
    if(~ret) return ret;

    ret = 0;
    for(int i = 1; i < n && i <= rem; i++){
        ret += go(c + 1, rem - i);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    clr(dp, -1);
    cout << go(0, n);
    return 0;
}
