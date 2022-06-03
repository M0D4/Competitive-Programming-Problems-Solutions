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

    string a[3];
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    string t; cin >> t;
    string x = "";
    for (int i = 0; i < t.size(); ++i) {
        x += a[t[i] - '0' - 1];
    }
    cout << x;
    return 0;
}

	