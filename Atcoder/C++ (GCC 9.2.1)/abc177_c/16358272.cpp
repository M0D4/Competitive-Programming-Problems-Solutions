#include "bits/stdc++.h"

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

const int MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    ll a[n], sum = 0, tot = 0;
    for(auto &i: a) cin >> i, sum += i;

    for(int i = 0; i < n; i++){
        sum -= a[i];
        tot += ((a[i] % MOD) * (sum % MOD)) % MOD;
        if(tot >= MOD) tot -= MOD;
    }
    cout << tot;
    return 0;
}
