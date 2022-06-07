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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if(k >= 25){
            cout << string(n, 'a') << endl;
            continue;
        }
        int to[26], f[26] = {};
        for (int i = 0; i < 26; ++i) {
            to[i] = i;
        }
 
        f[0] = 1;
        for (int i = 0; i < n && k; ++i) {
            if(f[s[i] - 'a']) continue;
            int x = s[i] - 'a';
            while (k && to[x]){
                if(!f[x]) --k;
                f[x]++;
                to[x] = to[x - 1];
                x = to[x];
            }
        }
 
        for (int i = 0; i < n; ++i) {
            int x = s[i] - 'a';
            while (to[x] != x) to[x] = to[to[x]], x = to[x];
            cout << char(x + 'a');
        }
        cout << endl;
    }
    return 0;
}