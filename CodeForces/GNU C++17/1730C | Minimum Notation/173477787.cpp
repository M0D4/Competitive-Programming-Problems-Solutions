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
        string s;
        cin >> s;
        int n = s.size();
        char mn = '9';
        int f[10] = {};
        for (int i = n - 1; i >= 0; --i) {
            mn = min(mn, s[i]);
            if (s[i] > mn){
                s[i] == '9' ? f[9]++ : f[s[i] + 1 - '0']++;
            }else{
                f[s[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            if(f[i])
                cout << string(f[i], char(i + '0'));
        }
        cout << endl;
    }
    return 0;
}