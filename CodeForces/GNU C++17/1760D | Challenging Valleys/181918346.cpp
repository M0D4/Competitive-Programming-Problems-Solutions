#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 0; i < n && cnt < 2; ++i) {
            int x = a[i], j = i;
            while (i + 1 < n && a[i + 1] == x) ++i;
            bool before = j == 0 || a[j - 1] > x;
            bool after = i == n  - 1 || a[i + 1] > a[i];
            cnt += before && after;
        }
        cout << (cnt == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}