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
        int ans = 0;
        if(n == 2);
        else if(n <= 4) ans = 1;
        else{
            ans += n - 3;
        }
        while (n >= 8){
            ans--;
            n /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}