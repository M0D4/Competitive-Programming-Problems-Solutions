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

    int n;
    cin >> n;
    int pos[n] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int f[n] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            f[(i + j - pos[i] + n) % n]++;
        }
    }
    cout << *max_element(f, f + n);
    return 0;
}