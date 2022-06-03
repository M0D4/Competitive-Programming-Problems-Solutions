#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s; cin >> s;
    sort(all(s));
    cout << (s[0] == s[2] ? "Won" : "Lost");
    return 0;
}