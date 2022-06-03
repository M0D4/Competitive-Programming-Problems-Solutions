#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n + 1);
    partial_sum(all(a), b.begin());

    ll x; cin >> x;
    ll cnt = x / b[n - 1];
    ll sum = cnt * b[n - 1];
    cnt *= n;
    ll rem = x % b[n - 1];
    sum = 0;
    for (int i = 0; i < n; ++i) {
        if(sum > rem) break;
        cnt++;
        sum += a[i];
    }
    cout << cnt;
    return 0;
}

