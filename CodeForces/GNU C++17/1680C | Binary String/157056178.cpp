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
        string s; cin >> s;
        int n = s.size();
        int ones[n + 3] = {};
        vector<int> zeros;
        int l = 0, r = n - 1;
        while (l < n && s[l] == '0') ++l;
        while (r > l && s[r] == '0') --r;
        for (int i = l; i <= r; ++i) {
            if(s[i] == '0')
                zeros.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            ones[i + 1] = ones[i] + (s[i] == '1');
        }
        l = 1, r = zeros.size();
        int ans = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            int mnOnes = n;
            for (int i = 0; i + mid <= zeros.size(); ++i) {
                int lx = zeros[i], rx = zeros[i + mid - 1];
                int one = 0;
                if (i + mid < zeros.size()) one += ones[n] - ones[zeros[i + mid]];
                if (i) one += ones[zeros[i - 1]];
                mnOnes = min(mnOnes, one);
            }
            if(mnOnes <= mid)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}