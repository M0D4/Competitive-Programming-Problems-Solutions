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
 
void solve(){
    int n; cin >> n;
    string s = "";
    int len = 1;
    int c = 0;
    for (int i = 1; ; ++i) {
        s = string(len, i + '0');
        if(stoll(s) > n){
            break;
        }
        c++;
        if(i == 9) i = 0, len++;
    }
    cout << c << endl;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int tc; cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}