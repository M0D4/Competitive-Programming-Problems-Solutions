#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
#define Unique(x)       x.erase(unique(all(x)), x.end())
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        sort(all(s));
        Unique(s);
        a[i] = s;
    }
    sort(all(a));
    Unique(a);
 
    cout << a.size();
    return 0;
}