#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = (1 << 20);

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    ll a[N], n = N;
    clr(a, -1);

    set<int> indices;
    for (int i = 0; i < (1 << 20); ++i) {
        indices.insert(i);
    }

    int q; cin >> q;
    while (q--){
        ll t, x; cin >> t >> x;
        if(t == 1) {
            ll h = x % n;
            auto it = indices.lower_bound(h);
            if (it == indices.end()) {
                h = 0;
                it = indices.lower_bound(h);
            }
            int index = *it;
            a[index] = x;
            indices.erase(it);
        }else{
            cout << a[x % n] << endl;
        }
    }
    return 0;
}