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
 
    int tc; cin >> tc;
    while(tc--){
        ll a, s; cin >> a >> s;
        string ans = "";
        bool ok = 1;
        while (s > 0){
            int x = a % 10;
            int y = s % 10;
            int diff = (y - x + 10) % 10;
            if(x + diff == y){
                ans = to_string(diff) + ans;
                a /= 10;
                s /= 10;
            }else if(x + diff == s % 100){
                ans = to_string(diff) + ans;
                a /= 10;
                s /= 100;
            }else{
                ok = 0;
                break;
            }
        }
        if(a > 0) ok = 0;
        if(!ok) cout << "-1\n";
        else{
            while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
            cout << ans << endl;
        }
    }
    return 0;
}