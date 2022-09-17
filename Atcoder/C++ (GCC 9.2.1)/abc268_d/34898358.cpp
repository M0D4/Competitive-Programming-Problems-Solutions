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

map<string, bool> mp;
int totalLength = 0;

string go(int i, int underscores, string s, vector<string>& a){
    if (i == a.size()){
        return (s.back() != '_' && s.size() <= 16 && mp.count(s) == 0 ? s : "");
    }

    if (i + 1 == a.size()) return go(i + 1, underscores, s + a[i], a);

    string t = "";
    for (int j = 1; i < a.size() && s.size() + j + a[i].size() <= 16; ++j) {
        t += "_";
        string x = go(i + 1, underscores + j, s + a[i] + t, a);
        if (x.size() >= 3) return x;
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totalLength += a[i].size();
    }

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        mp[s] = 1;
    }
    sort(all(a));

    do{
        string ans = go(0, 0, "", a);
        if (ans.size() >= 3)
            return cout << ans, 0;
    } while (next_permutation(all(a)));

    cout << -1;
    return 0;
}