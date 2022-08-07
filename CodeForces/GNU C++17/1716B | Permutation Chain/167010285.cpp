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
        int n; cin >> n;
        int a[n];
        vector<int> fixed, nonFixed;
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
            fixed.push_back(i);
        }
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i + 1 < n; ++i) {
            if (i == 0){
                int x = fixed.back();
                nonFixed.push_back(fixed.back());
                fixed.pop_back();
                int y = fixed.back();
                nonFixed.push_back(fixed.back());
                fixed.pop_back();
                swap(a[x], a[y]);
            }else{
                int x = fixed.back();
                int y = nonFixed.back();
                swap(x, y);
                swap(a[x], a[y]);
                nonFixed.back() = y;
                nonFixed.push_back(x);
                fixed.pop_back();
            }
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}