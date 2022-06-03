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

const int N = 1e3 + 5;

int n, m, dp[N][N];
vector<int> a, b;

int go(int i, int j){
    if(i == n || j == m)
        return n - i + m - j;

    int &ret = dp[i][j];
    if(~ret) return ret;

    ret = min(go(i + 1, j), go(i, j + 1)) + 1;

    ret = min(ret, go(i + 1, j + 1) + (a[i] != b[j]));

    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a = vector<int> (n);
    b = vector<int> (m);

    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    clr(dp, -1);

    cout << go(0, 0);
    return 0;
}
