#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 1e4;
int pfx[N];

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k; cin >> n >> k;
    int a[n] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            a[i] += x;
        }
        pfx[a[i]]++;
    }
    for (int i = 1; i < N; ++i) {
        pfx[i] += pfx[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << (n - pfx[(a[i] + 300)] < k ? "Yes" : "No") << endl;
    }
    return 0;
}