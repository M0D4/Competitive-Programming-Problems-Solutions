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

    string s, t;
    cin >> s >> t;
    cout << (s.size() <= t.size() && t.substr(0, s.size()) == s ? "Yes" : "No");
    return 0;
}