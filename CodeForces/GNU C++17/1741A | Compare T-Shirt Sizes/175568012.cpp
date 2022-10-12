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
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
 
        string x = "";
        if (s == t) x = "=";
        else if (s.back() == t.back() && s.back() == 'L') x = (n > m ? ">" : "<");
        else if (s.back() == t.back() && s.back() == 'S') x = (n < m ? ">" : "<");
        else if (s.back() == 'L') x = ">";
        else if (s.back() == 'M') x = (t.back() == 'L' ? "<" : ">");
        else if (s.back() == 'S') x = "<";
 
        cout << x << endl;
    }
    return 0;
}