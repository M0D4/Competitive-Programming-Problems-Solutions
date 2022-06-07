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
        string s; cin >> s;
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(i < 3) a += s[i] - '0';
            else b += s[i] - '0';
        }
        cout << (a == b ? "YES" : "NO") << endl;
    }
    return 0;
}