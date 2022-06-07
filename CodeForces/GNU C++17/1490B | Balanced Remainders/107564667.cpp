#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
int calc(int a, int b){
    if(a == 0){
        if(b == 1) return 1;
        return 2;
    }else if(a == 1){
        if(b == 0)
            return 2;
        return 1;
    }
    if(b == 0)
        return 1;
    return 2;
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int c[3] = {};
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            c[x % 3]++;
        }
        vector<pii> v = {{c[0], 0}, {c[1], 1}, {c[2], 2}};
        sort(all(v));
 
        int cnt = 0, div = n / 3;
 
        int m = max(v[2].first - div, 0);
        if(m + v[0].first > div) m = div - v[0].first;
        v[2].first -= m;
        v[0].first += m;
        cnt += m * calc(v[2].second, v[0].second);
 
        m = max(0, v[1].first - div);
        if(m + v[0].first > div) m = div - v[0].first;
        v[1].first -= m;
        v[0].first += m;
        cnt += m * calc(v[1].second, v[0].second);
 
        m = max(0, v[2].first - div);
        if(m + v[1].first > div) m = div - v[1].first;
        v[2].first -= m;
        v[1].first += m;
        cnt += m * calc(v[2].second, v[1].second);
 
        cout << cnt << endl;
    }
    return 0;
}