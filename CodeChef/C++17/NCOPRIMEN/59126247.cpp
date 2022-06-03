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
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            if(i % 3 == 0) continue;
            if(i % 3 == 1){
                a[i] = 2 * a[i - 1];
            }else{
                a[i] = (i + 1 == n ? a[i - 1] : 2 * a[i + 1]);
            }
        }
        for(auto& it: a)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
