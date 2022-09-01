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
        string s;
        cin >> n >> s;
        vector<int> delta;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') delta.push_back(n - i - 1 - i), sum += i;
            else delta.push_back(i - (n - i - 1)), sum += n - i - 1;
        }
        sort(all(delta), greater<>());
        for (int i = 0; i < n; ++i) {
            if (delta[i] > 0)
                sum += delta[i];
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}