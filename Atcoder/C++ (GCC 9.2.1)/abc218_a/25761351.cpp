#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    cout << (s[n - 1] == 'o' ? "Yes" : "No");
    return 0;
}

