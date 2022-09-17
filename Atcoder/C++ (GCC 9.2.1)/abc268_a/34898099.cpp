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
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = *max_element(a, a + n);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        --x;
        if(a[x] == mx)
            return cout << "Yes", 0;
    }
    cout << "No";
    return 0;
}