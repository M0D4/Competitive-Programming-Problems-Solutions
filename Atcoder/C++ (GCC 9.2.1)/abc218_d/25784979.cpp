#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    vector<pii> v;
    pii a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(a[i].second == a[j].second){
                int mn = min(a[i].first, a[j].first);
                int mx = max(a[i].first, a[j].first);
                v.push_back({mn, mx});
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        int mn1 = min(v[i].first, v[i].second);
        int mx1 = max(v[i].first, v[i].second);
        for (int j = i + 1; j < v.size(); ++j) {
            int mn2 = min(v[j].first, v[j].second);
            int mx2 = max(v[j].first, v[j].second);
            if(mn1 == mn2 && mx1 == mx2) cnt++;
        }
    }
    cout << cnt;
    return 0;
}

