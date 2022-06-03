#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N  = 1e6 + 5;
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
    void update(int k, int v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);


    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    map<int, int> mp;
    map<pair<int, int>, ll> f;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
        mp[a[i].second];
        f[a[i]]++;
    }
//    sort(a, a + n, [](pair<int, int>& a, pair<int, int>& b){
//        return a.second < b.second;
//    });

    int id = 1;
    for(auto& it: mp)
        it.second = id++;

    for (int i = 0; i < n; ++i) {
        a[i].second = mp[a[i].second];
    }

    sort(a, a + n, [](pair<int, int>& a, pair<int, int>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    FenwickTree ft(n + 2);

    ll cnt = 0;

    for (int i = n - 1; i >= 0; --i) {
        cnt += ft.rsq(a[i].second);
        ft.update(a[i].second, 1);
    }

    for(auto& it: f){
        ll x = it.second;
        cnt += x * (x - 1) >> 1;
    }

    cout << cnt + n;
    return 0;
}