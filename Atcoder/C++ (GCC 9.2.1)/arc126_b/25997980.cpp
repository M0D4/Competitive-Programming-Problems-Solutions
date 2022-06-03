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

const int N  = 2e5 + 1;
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
        int mx = 0;//overflow?
        for( ; b; b -= LSOne(b)) mx = max(mx, ft[b]);
        return mx;
    }

    void update(int k, int v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] = max(ft[k], v);
    }
};

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        a.push_back({x, -y});
    }
    sort(all(a));

    FenwickTree ft(n);
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        mx = ft.rsq(-a[i].second - 1);
        ft.update(-a[i].second, mx + 1);
    }
    cout << ft.rsq(n);
    return 0;
}

