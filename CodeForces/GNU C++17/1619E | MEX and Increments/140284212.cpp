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
        int a[n];
        int mp[n + 3] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }
         vector<ll> ans(n + 1, -1);
        vector<int> extra;
        ll increment = 0;
        ans[0] = mp[0];
        for (int i = 0; i < mp[0] - 1; ++i) {
            extra.push_back(0);
        }
        for (int i = 1; i <= n; ++i) {
            bool missBefore = (mp[i - 1] == 0);
            if(missBefore){
                if(extra.empty()) break;
                else{
                    int current = extra.back();
                    increment += (i - 1) - current;
                    extra.pop_back();
                    mp[i - 1]++;
                }
            }
            ans[i] = increment + mp[i];
            for (int j = 0; j < mp[i] - 1; ++j)
                extra.push_back(i);
        }
        for (const auto &item : ans)
            cout << item << " ";
        cout << endl;
    }
    return 0;
}