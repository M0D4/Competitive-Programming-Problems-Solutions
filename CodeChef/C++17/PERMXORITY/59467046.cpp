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
        if(n == 2){
            cout << "-1\n";
        }else if(n & 1){
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << " ";
            }
            cout << endl;
        }else if(n == 4){
            cout << "4 1 3 2\n";
        }else{
            cout << n - 1 << " ";
            cout << n - 4 << " ";
            cout << n - 3 << " ";
            cout << n << " ";
            cout << n - 2 << " ";
            for (int i = n - 5; i > 0; --i) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}