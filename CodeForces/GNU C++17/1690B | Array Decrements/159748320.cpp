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
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int mxDiff = 0, invalid = 0;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            int diff = a[i] - b[i];
            if(diff < 0) invalid = 1;
            mxDiff = max(mxDiff, diff);
        }
        for (int i = 0; i < n && !invalid; ++i) {
            a[i] = max(0, a[i] - mxDiff);
            invalid |= (a[i] != b[i]);
        }
        cout << (invalid ? "NO" : "YES") << endl;
    }
    return 0;
}