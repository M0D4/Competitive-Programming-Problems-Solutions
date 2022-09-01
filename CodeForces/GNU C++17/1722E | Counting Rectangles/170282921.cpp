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
 
const int N = 1e3 + 5;
class FenwickTree {
private:
    vector<ll> ft;
public:
    int LSOne(int x){ // least significant bit (1)
        return (x & (-x));
    }
    FenwickTree(){
 
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
    }
    ll rsq(int b) {
        ll sum = 0;//overflow?
        for( ; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    ll rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
    //like freq[x]++ || freq[x]--
    void update(int k, ll v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, q;
        cin >> n >> q;
 
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(all(a));
 
        FenwickTree ft[N];
 
        for (int i = 0; i < N; ++i) {
            ft[i] = FenwickTree(N);
        }
 
        for (int i = 0; i < n; ++i) {
            ft[a[i].first].update(a[i].second, a[i].first * a[i].second);
        }
 
        while (q--){
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
 
            int l = 0, r = n - 1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (a[mid].first <= hs) l = mid + 1;
                else r = mid - 1;
            }
 
            if (l == n){
                cout << "0\n";
                continue;
            }
 
            int lower = l;
            l = 0, r = n - 1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (a[mid].first >= hb) r = mid - 1;
                else l = mid + 1;
            }
            if (r < lower){
                cout << "0\n";
                continue;
            }
            int upper = r;
 
            ll ans = 0;
            for (int i = a[lower].first; i <= a[upper].first; ++i) {
                if (ws == wb + 1) continue;
                ans += ft[i].rsq(ws + 1, wb - 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}