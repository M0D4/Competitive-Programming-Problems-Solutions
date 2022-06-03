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
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int andd = (1 << 30) - 1, want = andd;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            want &= a[i];
        }
        int partitions = 0;
        for (int i = 0; i < n; ++i) {
            andd &= a[i];
            if(andd == want){
                partitions++;
                andd = (1 << 30) - 1;
            }
        }
        cout << n - partitions << endl;
    }
    return 0;
}