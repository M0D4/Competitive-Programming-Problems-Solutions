#include "bits/stdc++.h"

#pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

#define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
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

    int n; cin >> n;
    ll sum = 0, mx = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        sum += abs(x);
        sum2 += x * x;
        mx = max(mx, abs(x));
    }
    cout <<  sum << endl;
    cout << fixed << setprecision(9);
    cout << sqrt(sum2) << endl;
    cout << fixed << setprecision(0);
    cout << mx;
    return 0;
}
