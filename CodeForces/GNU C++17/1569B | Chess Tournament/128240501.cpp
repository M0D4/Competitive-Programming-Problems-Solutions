#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        string s; cin >> s;
        char a[n][n];
        clr(a, '.');
         for (int i = 0; i < n; ++i) {
            a[i][i] = 'X';
        }
        set<int> win;
        for (int i = 0; i < n; ++i) {
            if(s[i] == '1'){
                for (int j = 0; j < n; ++j) {
                    if(i ^ j) a[i][j] = a[j][i] = '=';
                }
            }else win.insert(i);
        }
         bool valid = 1;
        for (int i = 0; i < n; ++i) {
            if(win.count(i)) {
                if (s[i] == '2') {
                    bool ok = 0;
                    for (int j = 0; j < n; ++j) {
                        if (a[i][j] == '.' && a[j][i] == '.') {
                            if(ok){
                                a[i][j] = '-', a[j][i] = '+';
                                if(win.count(j)) win.erase(j);
                            }
                            else {
                                ok = 1;
                                a[i][j] = '+';
                                a[j][i] = '-';
                            }
                        }
                    }
                    if(ok) win.erase(i);
                    else valid = 0;
                }
            }
        }
        if(!valid) cout << "NO\n";
        else{
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(a[i][j] == '.') a[i][j] = a[j][i] = '=';
                    cout << a[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
 