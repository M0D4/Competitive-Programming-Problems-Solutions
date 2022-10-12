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
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        cin >> n;
 
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
 
        int requiredSum = 0, mn = n;
        for (int i = 0; i < n; ++i) {
            requiredSum += a[i];
            bool ok = 1;
            int currentSum = 0, cnt = 0, mxCnt = i + 1;
            for (int j = i + 1; j < n; ++j) {
                currentSum += a[j];
                ++cnt;
                if (currentSum > requiredSum){
                    ok = 0;
                    break;
                }
                if (currentSum == requiredSum){
                    mxCnt = max(mxCnt, cnt);
                    cnt = 0;
                    currentSum = 0;
                }
            }
            if (currentSum && currentSum != requiredSum) ok = 0;
            if (ok){
                mn = min(mn, mxCnt);
            }
        }
        cout << mn << endl;
    }
    return 0;
}