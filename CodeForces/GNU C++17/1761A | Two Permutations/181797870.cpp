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
        int n, a, b; cin >> n >> a >> b;
        if(a == n && b == n){
            cout << "YES\n";
            continue;
        }
 
        cout << (n - a - b > 1 ? "YES" : "NO") << endl;
    }
    return 0;
}