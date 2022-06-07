#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
const int N = 2e5 + 5, MOD = 1e9 + 7;
 
ll modPow(ll x, ll n, ll m = MOD) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
 
ll dp[N][2], n, k;
 
ll go(int bit, bool greater){
    if(bit == k) return 1;
 
    ll& ret = dp[bit][greater];
    if(~ret) return ret;
 
    if(!greater){
        if(n & 1){
            //and > xor : impossible
 
            ///and == xor : (and = 0, xor = 0), (and = 1, xor = 1);
            ///even number of ones : nC0 + nC2 + nC3 + .... + nC(n - 1)
            
            ret = go(bit + 1, greater) % MOD;
            ret += go(bit + 1, greater) % MOD * modPow(2, n - 1);
            if(ret >= MOD) ret %= MOD;
        }else{
            /// and > xor : all ones
            ret = go(bit + 1, true) % MOD;
            if(ret >= MOD) ret %= MOD;
 
            ///and == xor : at least one bit 0, even number of ones except n
            ret += go(bit + 1, greater) % MOD * (modPow(2, n - 1) - 1 + MOD) % MOD;
            if(ret >= MOD) ret %= MOD;
        }
    }else{
        ret = go(bit + 1, greater) % MOD * modPow(2, n);
        if(ret >= MOD) ret %= MOD;
    }
    return ret;
}
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        clr(dp, -1);
        cout << go(0, 0) << endl;
    }
    return 0;
}