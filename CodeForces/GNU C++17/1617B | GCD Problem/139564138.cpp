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
        ll n; cin >> n;
        if(n & 1){
            ll half = n / 2;
            if(half & 1 ^ 1) cout << half - 1 << " " << half + 1 << " 1\n";
            else cout << half - 2 << " " << half + 2 << " 1\n";
        }else{
            cout << "2 " << n - 3 << " 1\n";
        }
    }
    return 0;
}