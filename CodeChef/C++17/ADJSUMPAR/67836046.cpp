#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int b[n];
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int a[n] = {b[0]};
        for (int i = 0; i < n; ++i) {
            if(b[i]) a[(i + 1) % n] = a[i] ^ 1;
            else a[(i + 1) % n] = a[i];
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            ok &= ((a[i] + a[(i + 1) % n]) % 2) == b[i];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}