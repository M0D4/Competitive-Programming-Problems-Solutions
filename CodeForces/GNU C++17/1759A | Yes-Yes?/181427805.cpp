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
 
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        string t = "Yes";
        int i = -1;
        for (int j = 0; j < 3; ++j) {
            if (s[0] == t[j]){
                i = j;
                break;
            }
        }
        bool ok = ~i;
        if (~i){
            for (int j = 0; j < s.size(); ++j) {
                ok &= s[j] == t[i];
                i = (i + 1) % 3;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}