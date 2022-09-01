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
 
    string t = "Timur";
    sort(all(t));
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        string s; cin >> s;
        sort(all(s));
        cout << (s == t ? "YES" : "NO") << endl;
    }
    return 0;
}