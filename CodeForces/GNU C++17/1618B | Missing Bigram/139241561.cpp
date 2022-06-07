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
        int n; cin >> n;
        int m = n - 2;
        string a[m];
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        cout << a[0];
        bool found = 0;
        for (int i = 1; i < m; ++i) {
            if(a[i][0] != a[i - 1][1]){
                found = 1;
                cout << a[i][0];
            }
            cout << a[i][1];
        }
        if(!found){
            cout << "a";
        }
        cout << endl;
    }
    return 0;
}