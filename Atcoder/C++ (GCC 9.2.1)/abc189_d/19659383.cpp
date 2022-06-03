#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int N = 65;

ll dp[N][2], n;
string a[N];

ll go(int i, bool state){
    if(i == n + 1) return state;

    ll& ret = dp[i][state];
    if(~ret) return ret;

    ret = go(i + 1, (a[i] == "OR" ? state : 0)) //try || 0,  && 0
            + go(i + 1, (a[i] == "OR" ? 1 : state)); //try || 1, && 1

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    clr(dp, -1);
    cout << go(0, 0) + go(0, 1);
    return 0;
}