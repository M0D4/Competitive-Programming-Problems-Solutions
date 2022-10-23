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
    while (TC--) {
        ll s[26] = {}, t[26] = {};
        s[0] = t[0] = 1;
        ll sumS = 1, sumT = 1;
        int q;
        cin >> q;
        while (q--) {
            int idx, k;
            string x;
            cin >> idx >> k >> x;
            for (int i = 0; i < x.size(); ++i) {
                if (idx == 1)
                    s[x[i] - 'a'] += k, sumS += k;
                else
                    t[x[i] - 'a'] += k, sumT += k;
            }
 
            bool smaller = 0;
            int idxS = 0, idxT = 0;
            for (int i = 25; i >= 0; --i) {
                if (t[i]){
                    idxT = i;
                    break;
                }
            }
            if (idxT != 0) smaller = 1;
            else{
                if (s[0] < t[0]) smaller = (s[0] == sumS);
                else if (s[0] > t[0]) smaller = 0;
            }
            cout << (smaller ? "YES" : "NO") << endl;
        }
    }
    return 0;
}