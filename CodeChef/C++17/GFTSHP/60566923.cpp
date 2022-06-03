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

    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        int l = 0, r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            ll sum = 0;
            for (int i = 0; i < mid; ++i) {
                if(i + 1 == mid) sum += (a[i] + 1) / 2;
                else sum += a[i];
            }
            if(sum <= k) l = mid + 1;
            else r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}