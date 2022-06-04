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
        multiset<int> rep;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
            if(mp[a[i]] > 1)
                rep.insert(-a[i]);
        }
         cout << mp[0] << " ";
        ll increment = 0;
        bool valid = 1;
        for (int i = 1; i <= n; ++i) {
            if(!valid){
                cout << "-1 ";
                continue;
            }
            bool missBefore = (mp[i - 1] == 0);
            if(missBefore){
                if(rep.empty()) cout << "-1 ", valid = 0;
                else{
                    auto it = rep.lower_bound(-(i - 1));
                    if(it == rep.end()){
                        cout << "-1 ";
                        valid = 0;
                    }else{
                        int current = -*it;
                        increment += (i - 1) - current;
                        cout << increment + mp[i] << " ";
                        rep.erase(it);
                        mp[i - 1]++;
                    }
                }
            }else{
                cout << increment + mp[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}