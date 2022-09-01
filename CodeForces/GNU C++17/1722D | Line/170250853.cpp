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
        int n; cin >> n;
        string s; cin >> s;
        vector<int> l, r;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R')
                r.push_back(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'L')
                l.push_back(i);
        }
        ll mx = 0;
        for (int i = 0; i < n; ++i) {
            mx += (s[i] == 'L' ? i : n - i - 1);
        }
        for (int i = 0; i < n; ++i) {
            ll sum = mx;
            ll mx1 = 0, mx2 = 0;
            if (l.size()){
                int idx = l.back();
                mx1 = sum - idx + n - idx - 1;
            }
            if (r.size()){
                int idx = r.back();
                mx2 = sum - (n - idx - 1) + idx;
            }
            if (mx1 > mx2){
                l.pop_back();
            }else if (r.size()){
                r.pop_back();
            }
            mx = max({mx, mx1, mx2});
            cout << mx << " ";
        }
        cout << endl;
    }
    return 0;
}