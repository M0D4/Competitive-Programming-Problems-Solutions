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

const int N = 1e5 + 5;
unordered_map<int, int> mp;
ll pfx[N];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll n, x, m, a1; cin >> n >> x >> m;

    ll t1 = 0, t2 = n, s = 0;
    a1 = x;
    pfx[1] = a1;
    mp[a1] = 1;
    for(int i = 2; i <= n; i++){
        ll r = (a1 * a1) % m;
        if(mp.count(r)){
            t1 = mp[r];
            t2 = i;
            break;
        }
        mp[r] = i;
        a1 = r;
        pfx[i] = r;
    }
    for(int i = 0; i < t1; i++) s += pfx[i], pfx[i] = 0;
    for(int i = 1; i <= t2; i++) pfx[i] += pfx[i - 1];

    if(t1 == 0) return cout << pfx[n], 0;

    ll p = t2 - t1;
    ll pt = (n + 1 - t1) / p;
    ll sum = pt * (pfx[t2 - 1] - pfx[t1 - 1]);
    if((n + 1 - t1) % p){
        ll sp = (n - t1) % p;
        sum += pfx[t1 + sp] - pfx[t1 - 1];
    }
    cout << sum + s;
    return 0;
}
