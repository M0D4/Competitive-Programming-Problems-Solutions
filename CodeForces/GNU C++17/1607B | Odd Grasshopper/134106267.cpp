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
using vi = vector<int>;
 
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        ll x, n; cin >> x >> n;
        ll extra = 0;
        ll m = n / 2;
        ll pos = m / 2, neg = m / 2;
        if(m & 1){
            if(abs(x) & 1) neg++;
            else pos++;
        }
        if(n & 1){
            if(neg > pos) extra = -n;
            else if(pos > neg) extra = n;
            else{
                if(abs(x) & 1) extra = n;
                else extra = -n;
            }
        }
        cout << x + pos - neg + extra << endl;
    }
    return 0;
}