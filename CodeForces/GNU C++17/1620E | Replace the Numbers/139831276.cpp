#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 const int N = 5e5 + 5;
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int q; cin >> q;
    int to[N];
    vector<int> query[q];
     iota(to, to + N, 0);
     for (int i = 0; i < q; ++i) {
        int t, x; cin >> t >> x;
        int y = 0;
        if(t == 2) cin >> y;
        query[i] = {t, x, y};
    }
     vector<int> v;
    for (int i = q - 1; i >= 0; --i) {
        if(query[i][0] == 1) v.push_back(to[query[i][1]]);
        else to[query[i][1]] = to[query[i][2]];
    }
    reverse(all(v));
    for (const auto &item : v)
        cout << item << " ";
    return 0;
}