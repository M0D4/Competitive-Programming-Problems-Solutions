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
        int n, q;
        cin >> n >> q;
        ll sum = 0, even = 0, odd = 0;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            sum += x;
            even += x & 1 ^ 1;
            odd += x & 1;
        }
        while (q--){
            int t, x;
            cin >> t >> x;
            if (t == 0){ //add to even
                sum += x * even;
                if (x & 1) odd += even, even = 0;
            }else{
                sum += x * odd;
                if (x & 1) even += odd, odd = 0;
            }
            cout << sum << endl;
        }
    }
    return 0;
}