#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 3e6 + 5;

int f[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, w; cin >> n >> w;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }

    set<int> s;
    for (int i = 0; i < n; ++i) {
       if (a[i] <= w) s.insert(a[i]);
        for (int j = i + 1; j < n; ++j) {
            ll sum = a[i] + a[j];
            if(sum <= w) s.insert(sum);
            for (int k = j + 1; k < n; ++k) {
                sum = a[i] + a[j] + a[k];
                if(sum <= w) s.insert(sum);
            }
        }
    }
    cout << s.size();
    return 0;
}