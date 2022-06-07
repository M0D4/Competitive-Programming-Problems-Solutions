#include "bits/stdc++.h"
 
 
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, val)    memset(x, val, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 30; ~i; --i){
            if(1 & (n >> i)){
                cout << (1LL << i) - 1 << endl;
                break;
            }
        }
    }
    return 0;
}