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
        ll n, m, ri, ci, rd, cd;
        cin >> n >> m >> ri >> ci >> rd >> cd;
        --ri, --ci, --rd, --cd;
        int seconds = 0;
        int rAdd = 1, cAdd = 1;
        while (ri != rd && ci != cd){
            if(ri + rAdd >= n || ri + rAdd < 0){
                rAdd *= -1;
            }
            if(ci + cAdd >= m || ci + cAdd < 0){
                cAdd *= -1;
            }
            ri += rAdd, ci += cAdd;
            seconds++;
        }
        cout << seconds << endl;
    }
    return 0;
}