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
        int x; cin >> x;
        int cnt = x / 10;
        x -= cnt * 10;
        if(x % 5 != 0){
            cout << "-1\n";
        }else{
            cout << cnt + x / 5 << endl;
        }
    }
    return 0;
}