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
        int n = 7;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        auto b = a;
        do{
            vector<ll> c;
            for (int i = 1; i < 8; ++i) {
                ll sum = 0;
                for (int j = 0; j < 3; ++j) {
                    if((i >> j) & 1) sum += a[j];
                }
                c.push_back(sum);
            }
            sort(all(c));
            if(c == b){
                for (int i = 0; i < 3; ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;
            }
        } while (next_permutation(all(a)));
    }
    return 0;
}