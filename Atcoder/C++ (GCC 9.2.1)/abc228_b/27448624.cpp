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

    int n, x; cin >> n >> x;
    int a[n];
    --x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(x);
        x = a[x];
    }
    cout << s.size();
    return 0;
}