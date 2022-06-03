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
    int mx = 0;
    string s;
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        mp[x]++;
        if(mp[x] > mx){
            mx = mp[x];
            s = x;
        }
    }
    cout << s;
    return 0;
}