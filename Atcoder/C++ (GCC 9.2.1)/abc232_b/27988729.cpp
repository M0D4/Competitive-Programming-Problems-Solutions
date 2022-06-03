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

    string s, t; cin >> s >> t;
    int diff = (s[0] - t[0] + 26) % 26;
    for (int i = 1; i < s.size(); ++i) {
        if((s[i] - t[i] + 26) % 26 != diff){
            return cout << "No", 0;
        }
    }
    cout << "Yes";
    return 0;
}