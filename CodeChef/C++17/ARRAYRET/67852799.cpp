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
        ll b[n];
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        ll x[n] = {0};
        ll sum = 0;
        for (int i = 1; i < n; ++i) {
            x[i] = b[i] - b[0];
            sum += x[i];
        }

        ll a[n];
        a[0] = (b[0] - sum) / (n + 1);
        for (int i = 1; i < n; ++i) {
            a[i] = a[0] + x[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}