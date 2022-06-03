#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define what_is(x)      cerr << #x << " is " << x << endl;


using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;




int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    ll x = 0;
    for(int i = 0; i < n; i++) x += a[i] * b[i];
    cout << (x ? "No" : "Yes");
    return 0;
}