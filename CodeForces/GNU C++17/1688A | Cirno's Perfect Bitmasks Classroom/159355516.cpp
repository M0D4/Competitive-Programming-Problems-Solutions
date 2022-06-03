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
        ll n; cin >> n;
        ll y = 0;
        for (int bit = 0; bit <= 30; ++bit) {
            if((n >> bit) & 1){
                y |= (1LL << bit);
                break;
            }
        }
        ll ones = __builtin_popcountll(n);
        for (int bit = 0; bit <= 30 && ones <= 1; ++bit) {
            if((n >> bit) & 1 ^ 1){
                y |= (1LL << bit);
                break;
            }
        }
        cout << y << endl;
    }
    return 0;
}