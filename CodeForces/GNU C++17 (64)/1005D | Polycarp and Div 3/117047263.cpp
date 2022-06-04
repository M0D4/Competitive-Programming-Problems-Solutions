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
 const int N = 2e5 + 5;
 string s;
int n, dp[N][10][3];
 int go(int i, int firstDigit, int rem){
    if(i == n) return rem == 0;
     int& ret = dp[i][firstDigit][rem];
    if(~ret) return ret;
     ret = 0;
    if(firstDigit) ret = go(i + 1, firstDigit, (rem + s[i] - '0') % 3);
    ret = max(ret, !rem + go(i + 1, s[i] - '0', (s[i] - '0') % 3));
     return ret;
}
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     cin >> s;
    n = s.size();
    clr(dp, -1);
    cout << go(1, s[0] - '0', (s[0] - '0') % 3);
    return 0;
}