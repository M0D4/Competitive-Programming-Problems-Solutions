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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll cnt = 0;
        for (int i = n - 2; i >= 0; --i) {
            while (a[i] && a[i] >= a[i + 1])
                a[i] >>= 1, cnt++;
            if(a[i] >= a[i + 1]){
                cnt = -1;
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}