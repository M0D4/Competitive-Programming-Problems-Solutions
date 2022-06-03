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
        double x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        if(isless(y1 / x1, y2 / x2)){
            cout << "-1\n";
        }else if(isgreater(y1 / x1, y2 / x2)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
    return 0;
}