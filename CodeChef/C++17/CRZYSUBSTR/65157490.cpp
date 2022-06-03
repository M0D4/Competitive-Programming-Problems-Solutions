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
        int n; cin >> n;
        string s; cin >> s;
        vector<int> f[26];
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int cnt = 1;
            while (i + 1 < n && s[i + 1] == c)
                ++i, cnt++;
            f[c - 'a'].push_back(cnt);
        }
        for (int i = 0; i < 26; ++i) {
            if(f[i].size())
                sort(all(f[i]), greater<>());
            for (int j = 1; j < f[i].size(); ++j) {
                f[i][j] += f[i][j - 1];
            }
        }

        for (int i = 0; i <= n; ++i) {
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                if(f[j].empty()) continue;
                mx = max(mx, f[j][min(i, (int)f[j].size() - 1)]);
            }
            cout << mx << " ";
        }
        cout << endl;
    }
    return 0;
}