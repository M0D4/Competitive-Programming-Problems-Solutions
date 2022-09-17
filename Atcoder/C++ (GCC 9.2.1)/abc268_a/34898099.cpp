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

    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    cout << set<int>(all(a)).size();
    return 0;
}
