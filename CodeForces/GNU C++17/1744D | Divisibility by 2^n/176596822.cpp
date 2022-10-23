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
        int zeros = 0;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            zeros += __builtin_ctz(x);
            v.push_back(__builtin_ctz(i + 1));
        }
        int operations = 0;
        sort(all(v));
        while (zeros < n && v.size()){
            zeros += v.back();
            v.pop_back();
            operations++;
        }
        if (zeros < n) operations = -1;
        cout << operations << endl;
    }
    return 0;
}