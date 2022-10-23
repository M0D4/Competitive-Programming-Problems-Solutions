#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        multiset<ll> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s.insert(x);
        }
        auto can = [&](int k){
            multiset<ll> a = s;
            for (int i = 1; i <= k; ++i) {
                int atMost = k - i + 1;
                auto it = a.upper_bound(atMost);
                if (it == a.begin()) return false;
                --it;
                a.erase(a.find(*it));
                if (a.empty()) continue;
                it = a.begin();
                ll newValue = *it + atMost;
                a.erase(a.begin());
                a.insert(newValue);
            }
            return true;
        };
        int l = 0, r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (can(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}