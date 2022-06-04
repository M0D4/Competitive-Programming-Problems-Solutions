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
        int a[n], pos[n + 1] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        vector<int> ans;
        for (int i = n; i >= 1; --i) {
            int steps = (pos[i] + 1) % i;
            ans.push_back(steps);
            for (int j = 1; j < i; ++j) {
                pos[j] -= steps;
                pos[j] %= i;
                pos[j] = (pos[j] + i) % i;
            }
        }
        reverse(all(ans));
        for(auto& i: ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}