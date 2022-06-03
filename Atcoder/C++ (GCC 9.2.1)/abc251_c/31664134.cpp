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
    int n; cin >> n;
    map<string, int> mp;
    int index = 0, best = -1;
    for (int i = 0; i < n; ++i) {
        string s; int score;
        cin >> s >> score;
        if(mp[s]) continue;
        mp[s]++;
        if (score > best)
            index = i + 1, best = score;
    }
    cout << index;
    return 0;
}