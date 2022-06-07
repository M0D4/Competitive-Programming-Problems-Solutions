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
    while (tc--){
        int n; cin >> n;
        int pos = 0, neg = 0, len = 1, ok = 1;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(x == 1){
                if(pos) len += 5;
                else len++;
                pos++;
                neg = 0;
            }else{
                if(neg) ok = 0;
                pos = 0;
                neg++;
            }
        }
        if(!ok) len = -1;
        cout << len << endl;
    }
    return 0;
}