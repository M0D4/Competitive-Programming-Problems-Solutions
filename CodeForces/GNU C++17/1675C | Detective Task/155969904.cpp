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
        int n = s.size();
        int cnt = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            if(s[i] == '0'){
                for (int j = i + 1; j < n; ++j) {
                    s[j] = '0';
                }
                cnt++;
                for (int j = i - 1; j >= 0 && s[j] == '?'; --j) {
                    cnt++;
                    vis[j] = 1;
                }
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(s[i] == '1'){
                for (int j = n - 1; s[j] != '1'; --j) {
                    cnt += (s[j] == '?' && !vis[j]);
                }
                cnt++;
                break;
            }
        }
        if(s == string(n, '?')) cnt = n;
        cout << cnt << endl;
    }
    return 0;
}