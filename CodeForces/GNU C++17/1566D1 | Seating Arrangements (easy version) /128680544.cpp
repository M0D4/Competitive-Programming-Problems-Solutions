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
 const int N  = 400 + 5;
class FenwickTree {
private:
    vector<int> ft;
public:
    int LSOne(int x){ // least significant bit (1)
        return (x & (-x));
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
    }
    int rsq(int b) {
        int sum = 0;//overflow?
        for( ; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    // updates value of the k-th element by v (v can be +ve/inc or -ve/dec)
    //like freq[x]++ || freq[x]--
    void update(int k, int v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};
 void solve(){
    int n, m; cin >> n >> m;
    pii a[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + m, [](pii& a, pii& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
     for (int i = 0; i < m; ++i) {
        a[i].first = i + 1;
    }
    sort(a, a + m, [](pii& a, pii& b){
       return a.second < b.second;
    });
     FenwickTree ft(m + 2);
    ll cnt = 0;
    for (int i = 0; i < m; ++i) {
        cnt += ft.rsq(a[i].first);
        ft.update(a[i].first, 1);
    }
    cout << cnt << endl;
}
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
      int TC; cin >> TC;
    for (int i = 1; i <= TC; ++i) {
        solve();
    }
    return 0;
}
 