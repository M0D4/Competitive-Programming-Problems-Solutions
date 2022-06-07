#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
const int N = 15;
 
int dp[N][N][N], n;
string s;
 
int go(int i, int carry, int carryNext){
    if(i == n) return (!carry && !carryNext);
 
    int& ret = dp[i][carry][carryNext];
    if(~ret) return ret;
 
    ret = 0;
    for (int j = 0; j <= 9; ++j) {
        for (int k = 0; k <= 9; ++k) {
            int cur = j + k + carry;
            if(cur % 10 == s[i] - '0')
                ret += go(i + 1, carryNext, cur / 10);
        }
    }
    return ret;
}
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while (t--){
        clr(dp, -1);
        cin >> s;
        reverse(all(s));
 
        n = s.size();
        cout << go(0, 0, 0) - 2 << endl;
    }
    return 0;
}