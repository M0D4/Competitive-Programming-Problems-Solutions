#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;

double dis(int x1, int y1){
    return sqrt(pow(x1, 2) + pow(y1, 2));
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    ll x, y, r; cin >> r >> x >> y;
    double d = dis(x, y);
    if(isless(d, r)) return cout << 2, 0;
    ll steps = d / r;
    if(isless(steps * r, dis(x, y))) steps++;
    cout << steps;
    return 0;
}