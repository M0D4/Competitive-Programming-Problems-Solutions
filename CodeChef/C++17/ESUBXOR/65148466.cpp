#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = (1 << 17), M = N / 2, inf = 3e5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        set<int> sa, sb;
        for (int i = 0; i < n; ++i) {
            a[i] = i + 2;
            sa.insert(a[i]);
        }
        ll x = 0;
        for (int i = 0; i < n; ++i) {
            b[i] = n + i + 2 + (n & 1);
            assert(!sa.count(b[i]));
            assert(b[i] > 0 && b[i] <= inf);
            sb.insert(b[i]);
        }
        ll xa = 0, xb = 0;
        for (int i = 0; i < n; ++i) {
            xa ^= a[i], xb ^= b[i];
            if(i & 1)
                assert(xa == xb);
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}