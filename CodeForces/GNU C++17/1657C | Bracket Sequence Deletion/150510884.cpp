#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
const int MOD = 1000000007, p = 101;
 
int n;
string s;
 
void computePowers(ll power[]) {
    power[0] = 1;
 
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] % MOD * p % MOD) % MOD;
 
    return;
}
 
void computePrefixHash(ll prefix[], ll power[]) {
    prefix[0] = 0;
    prefix[1] = s[0];
 
    for (int i = 2; i <= n; i++) {
        prefix[i] = (prefix[i - 1] % MOD + (s[i - 1] % MOD * power[i - 1] % MOD) % MOD) % MOD;
    }
 
    return;
}
 
void computeSuffixHash(ll suffix[], ll power[]) {
    suffix[0] = 0;
    suffix[1] = s[n - 1];
 
    for (int i = n - 2, j = 2; i >= 0 && j <= n; i--, j++)
        suffix[j] = (suffix[j - 1] % MOD + (s[i] % MOD * power[j - 1] % MOD) % MOD) % MOD;
    return;
}
 
ll power(ll x, ll y, int MOD)
{
    ll res = 1;
 
    x = x % MOD;
 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
 
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
 
ll modInverse(ll n)
{
    return power(n, MOD - 2, MOD);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> s;
        ll power[n + 1];
 
        computePowers(power);
 
        ll prefix[n + 1], suffix[n + 1];
 
        computePrefixHash(prefix, power);
        computeSuffixHash(suffix, power);
 
        int l = 0, r = 0, cnt = 0, balanced = 1, steps = 0;
        while (r < n){
            if(s[r] == ')') cnt--;
            else cnt++;
            if(cnt < 0) balanced = 0;
            if(cnt == 0 && balanced){
                r++;
                l = r;
                steps++;
                continue;
            }
            ll hash = ((prefix[r + 1] - prefix[l] + MOD) % MOD * modInverse(power[l]) % MOD) % MOD;
            ll reverseHash = ((suffix[n - l] - suffix[n - r - 1] + MOD) % MOD * modInverse(power[n - r - 1]) % MOD) % MOD;
 
            if (r > l && hash == reverseHash) {
                r++;
                l = r;
                steps++;
                cnt = 0;
                balanced = 1;
                continue;
            }
            ++r;
        }
        cout << steps << " " << n - l << endl;
    }
    return 0;
}