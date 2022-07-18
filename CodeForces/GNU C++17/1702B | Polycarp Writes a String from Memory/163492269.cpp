#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
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
        int days = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            set<char> st;
            int j = i;
            for ( ; j < n && st.size() < 3; ++j) {
                st.insert(s[j]);
            }
            while (j < n){
                if (!st.count(s[j]))
                    break;
                ++j;
            }
            i = j - 1;
            days++;
        }
        cout << days << endl;
    }
    return 0;
}