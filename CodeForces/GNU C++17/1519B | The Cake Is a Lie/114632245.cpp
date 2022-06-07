#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> n >> m >> k;
        cout << (n * m - 1 == k ? "YES" : "NO") << endl;
    }
    return 0;
}