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

const int N = 105;
vector<int> sieve(N), primes;

int f[105], n;
ll dp[N][1000][1000];

ll go(int i, int p, int mul){
    if(mul > 75) return 0;
    if(i == primes.size()) return mul == 75;

    ll &ret = dp[i][p][mul];
    if(~ret) return ret;

    ret = 0;
    for(int j = 0; j <= f[primes[i]]; j++){
        ret += go(i + 1, j, mul * (j + 1));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    sieve[0] = sieve[1] = 1;
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i){
                if (!sieve[j])
                    sieve[j] = i;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        int x = i;
        while (sieve[x]){
            f[sieve[x]]++;
            x /= sieve[x];
        }
        if(!sieve[x]) f[x]++;
    }
    
    clr(dp, -1);

    cout << go(0, 0, 1);
    return 0;
}