#include "bits/stdc++.h"
 #pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     const int N = 1e6 + 5;
    bitset<N> sieve;
    vector<int> primes;
    for(ll i = 2; i < N; i++){
        if(sieve[i]) continue;
        primes.push_back(i);
        for(ll k = i * i; k < N; k += i) sieve[k] = 1;
    }
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        int m = primes.size(), l = 0, r = m - 1, R = 0, L = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(primes[mid] * 1LL * primes[mid] <= n) l = mid + 1;
            else r = mid - 1;
        }
        L = r;
        R =  upper_bound(all(primes), n) - primes.begin();
        cout << R - L << endl;
    }
    return 0;
}