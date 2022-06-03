#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x



int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    string s, t; cin >> s >> t;
    if(s == t) return cout << "Yes", 0;

    int n = s.size(), op = 0, ok = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] != t[i]){
            if(op) ok = 0;
            if(i + 1 < n && s[i] == t[i + 1] && t[i] == s[i + 1]) op = 1, swap(s[i], s[i + 1]);
            else ok = 0;
        }
    }
    cout << (ok ? "Yes" : "No");
    return 0;
}

	