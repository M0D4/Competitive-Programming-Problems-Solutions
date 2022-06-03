#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x; cin >> x;
            a[i] += x;
        }
    }
    auto b = a;
    sort(all(b));
    for (int i = 0; i < n; ++i) {
        int x = a[i] + 300;
        int rank = n - (upper_bound(all(b), x) - b.begin()) + 1;
        cout << (rank <= k ? "Yes" : "No") << endl;
    }
    return 0;
}