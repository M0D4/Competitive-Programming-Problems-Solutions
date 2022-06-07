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
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> ans(3, 1e9);
        for (int i = 3; i < n; ++i) {
            int h1 = i;
            int h2 = min(n - i, i - 1);
            int h3;
            if(n - h1 - h2 > 0) h3 = n - h1 - h2;
            else h3 = 1, h2--;
            if(h1 && h2 && h3 && h1 + h2 + h3 == n && h1 > h2 && h2 > h3){
                if(h1 < ans[1])
                    ans = {h2, h1, h3};
            }
        }
        for (int i = 0; i < 3; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}