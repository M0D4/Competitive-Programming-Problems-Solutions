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
 
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            s.erase(s.find(a[i]));
            int mx = *s.rbegin();
            cout << a[i] - mx << " ";
            s.insert(a[i]);
        }
        cout << endl;
    }
    return 0;
}