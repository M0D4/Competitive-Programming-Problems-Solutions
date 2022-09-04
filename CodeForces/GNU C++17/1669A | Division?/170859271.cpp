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
        int x; cin >> x;
        cout << "Division ";
        if (x <= 1399) cout << 4;
        else if (x <= 1599) cout << 3;
        else if (x <= 1899) cout << 2;
        else cout << 1;
        cout << endl;
    }
    return 0;
}