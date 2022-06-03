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

    ll t1 = 1, t2 = n + 1;
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

    for(int i = 1; i <= t2; i++) pfx[i] += pfx[i - 1];

    ll period_len = t2 - t1;
    ll period_counts = (n + 1 - t1) / period_len;
    ll sum = period_counts * (pfx[t2 - 1] - pfx[t1 - 1]);
    if((n + 1 - t1) % period_len){
        ll sub_period = (n - t1) % period_len;
        sum += pfx[t1 + sub_period] - pfx[t1 - 1];
    }
    cout << sum + pfx[t1 - 1];
    return 0;
}
