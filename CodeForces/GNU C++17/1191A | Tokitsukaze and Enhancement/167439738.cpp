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
 
    int x; cin >> x;
 
    int y = (x + 1) % 4;
    int z = (x + 2) % 4;
    x %= 4;
    
    int a[] = {0, 3, 1, 2};
    string s = "DACB";
    
    int mx = max({a[x], a[y], a[z]});
    if (mx == a[x]) cout << "0 " << s[x];
    else if (mx == a[y]) cout << "1 " << s[y];
    else if (mx == a[z]) cout << "2 " << s[z];
    
    return 0;
}