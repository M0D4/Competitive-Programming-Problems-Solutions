#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)

using ll = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

ll calc(ll n){
    return n * (n + 1) >> 1;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, k; cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<>());

    ll l = 0, r = 2e9;
    while (l <= r){
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max(0LL, a[i] - mid);
        }
        if(cnt <= k) r = mid - 1;
        else l = mid + 1;
    }
    ll reach = r + 1, sum = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i] > reach) sum += calc(a[i]) -  calc(reach), k -= (a[i] - reach), a[i] = reach;
    }

    priority_queue<ll> q;
    for (int i = 0; i < n; ++i) {
        if(a[i]) q.push(a[i]);
    }

    while (q.size() && k){
        ll p = q.top(); q.pop();
        sum += p;
        --k, --p;
        if(p > 0) q.push(p);
    }

    cout << sum;
    return 0;
}