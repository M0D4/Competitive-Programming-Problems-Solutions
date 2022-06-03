#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

string a[] = {"EVEN", "ODD"};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        ll n, k; cin >> n >> k;
        if (k == 1) cout << a[n & 1] << endl;
        else if (k == 2) cout << "ODD\n";
        else {
            cout << "EVEN\n";
        }
    }
    return 0;
}