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
 
const int N = 2e5 + 5;
int a[N], n, H;
 
int go(int i, ll h, int two, int three){
    if (i == n) return 0;
 
    if (h > a[i]) return 1 + go(i + 1, h + a[i] / 2, two, three);
 
    int ret = 0;
    if (two) ret = go(i, 2 * h, two - 1, three);
    if (three) ret = max(ret, go(i, 3 * h, two, three - 1));
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n >> H;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << go(0, H, 2, 1) << endl;
    }
    return 0;
}