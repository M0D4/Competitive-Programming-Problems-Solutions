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
        int a[n];
        ll evenSum = 0, evenCnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] & 1 ^ 1) evenSum += a[i], evenCnt++;
        }
        if(evenCnt != n){
            cout << evenCnt << endl;
            continue;
        }
        ll c = 0, mn = 1e9;
        for (int i = 0; i < n; ++i) {
            if(a[i] & 1) continue;
            c = 0;
            while (a[i] % 2 == 0){
                c++;
                a[i] >>= 1;
            }
            mn = min(mn, c);
        }
        cout << mn + n - 1 << endl;
    }
    return 0;
}