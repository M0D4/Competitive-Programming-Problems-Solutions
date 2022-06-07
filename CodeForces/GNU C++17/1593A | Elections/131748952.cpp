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
 
void solveOne(){
    ll a, b, c; cin >> a >> b >> c;
    cout << max(0LL, max(b, c) - a + 1) << " "
         << max(0LL, max(a, c) - b + 1) << " "
         << max(0LL, max(a, b) - c + 1) << endl;
}
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        solveOne();
    }
    return 0;
}
 