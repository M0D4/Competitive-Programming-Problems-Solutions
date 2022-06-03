#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;



const int N  = 2e5 + 8, M = 1e8 + 8;
int mp[M];

class FenwickTree {
private:
    vector<int> ft;
    vector<ll> s;
public:
    int LSOne(int x){ // least significant bit (1)
        return (x & (-x));
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
        s.assign(n + 2, 0);
    }
    ll rsq(int b, bool wantSum) {
        ll sum = 0;//overflow?
        if(wantSum)
            for( ; b; b -= LSOne(b)) sum += s[b];
        else
            for( ; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    ll rsq(int a, int b, bool wantSum) {
        return rsq(b, wantSum) - (a == 1 ? 0 : rsq(a - 1, wantSum));
    }

    void update(int k, int v) { // int v overflow?
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }

    void updateSum(int k, int v){
        for (; k < (int)s.size(); k += LSOne(k)) s[k] += v;
    }
};

ll value(ll x){
    return x - 2;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    FenwickTree ft1(N), ft2(N);

    int n, m, q; cin >> n >> m >> q;
    int a[n + 1] = {}, b[m + 1] = {};

    fill(a + 1, a + n + 1, 2);
    fill(b + 1, b + m + 1, 2);


    ll sum = 0, idx = 1;
    vector<vector<int>> queries;
    vector<int> values;
    while (q--) {
        int t, i, v;
        cin >> t >> i >> v;
        values.push_back(v);
        queries.push_back({t, i, v});
    }
    values.push_back(0);

    sort(all(values));
    Unique(values);
    for (int i = 0; i < values.size(); ++i) {
        mp[values[i] + 2] = idx++;
    }


    ft1.update(mp[2], n);
    ft2.update(mp[2], m);

    ft1.updateSum(mp[2], 2 * n);
    ft2.updateSum(mp[2], 2 * m);


    q = queries.size();
    for (int j = 0; j < queries.size(); ++j) {
        int t, i, v;
        t = queries[j][0], i = queries[j][1], v = queries[j][2];
        if(t == 1){
            ll cnt = ft2.rsq(mp[a[i]], false);
            sum -= cnt * value(a[i]);
            sum -= ft2.rsq(mp[a[i]] + 1, N - 1, true) - 2 * (m - cnt);
            v += 2;

            ft1.updateSum(mp[a[i]], -a[i]);
            ft1.update(mp[a[i]], -1);

            a[i] = v;
            ft1.updateSum(mp[a[i]], v);
            ft1.update(mp[a[i]], 1);

            cnt = ft2.rsq(mp[a[i]], false);
            sum += cnt * value(a[i]);
            sum += ft2.rsq(mp[a[i]] + 1, N - 1, true) - 2 * (m - cnt);
        }else{
            ll cnt = ft1.rsq(mp[b[i]], false);
            sum -= cnt * value(b[i]);
            sum -= ft1.rsq(mp[b[i]] + 1, N - 1, true) - 2 * (n - cnt);
            v += 2;

            ft2.updateSum(mp[b[i]], -b[i]);
            ft2.update(mp[b[i]], -1);

            b[i] = v;
            ft2.updateSum(mp[v], v);
            ft2.update(mp[v],1);
            cnt = ft1.rsq(mp[b[i]], false);
            sum += cnt * value(b[i]);
            sum += ft1.rsq(mp[b[i]] + 1, N - 1, true) - 2 * (n - cnt);
        }
        cout << sum << endl;
    }
    return 0;
}