#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    int a[m];
    for(int &i: a) cin >> i;

    if(m == n) return cout << 0, 0;
    if(m == 0) return cout << 1, 0;

    sort(a, a + m);
    int mn = 1e9;
    if(a[0] > 1) mn = a[0];
    for(int i = 1; i < m; i++){
        if(a[i] - a[i - 1] != 1) mn = min(mn, a[i] - a[i - 1]);
    }
    if(a[m - 1] != n) mn = min(mn, n - a[m - 1]);
    mn--;
//    cout << mn; return 0;
    int last = 0;
    ll ans = 0, len;
    for(int i = 0; i < m; i++){
        len = (a[i] - last - 1);
//            cout << len << " ";
        ans += len / mn + !!(len % mn);
        last = a[i];
    }
    len = (n - last);
//            cout << len << " ";
    ans += len / mn + !!(len % mn);

    cout << ans;
    return 0;
}
