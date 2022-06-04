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
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i + 1);
        }
        vector<int> rem;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(s.count(a[i])) s.erase(a[i]);
            else rem.push_back(a[i]);
        }
        sort(all(rem));
        bool ok = 1;
        for(auto& x: rem){
            int next = *s.begin();
            if(next < (x + 1) / 2){
                s.erase(s.begin());
            }else{
                ok = 0;
                break;
            }
        }
        cout << (ok ? (int)rem.size() : -1) << endl;
    }
    return 0;
}