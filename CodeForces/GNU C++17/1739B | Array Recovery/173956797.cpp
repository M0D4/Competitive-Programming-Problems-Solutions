#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int d[n];
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        int a[n] = {d[0]};
        bool multipleSolution = 0;
        for (int i = 1; i < n; ++i) {
            int x = abs(a[i - 1] - d[i]);
            int y = a[i - 1] + d[i];
            if (x == y) a[i] = x;
            else{
                int first = abs(x - a[i - 1]), second = abs(y - a[i - 1]);
                if (first == d[i] && second == d[i]){
                    multipleSolution = 1;
                    break;
                }
                if (first == d[i]) a[i] = x;
                else a[i] = y;
            }
        }
        if (multipleSolution) cout << "-1\n";
        else{
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}