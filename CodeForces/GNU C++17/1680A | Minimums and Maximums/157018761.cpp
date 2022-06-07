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
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2)
            swap(l1, l2), swap(r1, r2);
        if (l2 > r1)
            cout << l1 + l2 << endl;
        else
            cout << max(l1, l2) << endl;
    }
    return 0;
}