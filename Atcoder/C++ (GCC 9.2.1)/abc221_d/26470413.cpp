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
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        mp[a]++;
        mp[a + b]--;
    }
    mp[3e9] = 0;

    ll last = 0, lastVal = 0;
    int idx = 0;
    for(auto& it: mp){
        if(idx)
            it.second += last;
        last = it.second;
        idx++;
    }

    last = idx = 0;
    map<ll, ll> f;
    for(auto& it: mp){
        if(idx)
             f[lastVal] += it.first - last;
        last = it.first;
        lastVal = it.second;
        idx++;
    }
    for (int i = 0; i < n; ++i) {
        cout << f[i + 1] << " ";
    }
    return 0;
}

