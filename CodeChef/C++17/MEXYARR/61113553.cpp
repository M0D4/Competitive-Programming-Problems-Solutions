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
        set<int> free;
        map<int, int> f;
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
            if(a[i] - 1 > i)
                ok = 0;
        }
        if(!ok){
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i <= n; ++i) {
            free.insert(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            if(a[i] >= 0){
                if(free.count(a[i])){
                    free.erase(a[i]);
                }
            }
        }
        int ans[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = *free.begin();
            free.erase(free.begin());
            if(a[i] >= 0){
                f[a[i]]--;
                if(!f[a[i]])free.insert(a[i]);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}