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

    string p; cin >> p;
    map<char, int> mp;

    for (int i = 0; i < 26; ++i) {
       mp[p[i]] = i;
    }

    int n; cin >> n;
    string a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n, [&](string& x, string& y){
        for (int i = 0; i < min(x.size(), y.size()); ++i) {
            if(x[i] == y[i]) continue;
            return mp[x[i]] < mp[y[i]];
        }
        return x.size() < y.size();
    });

    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}

