#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

ll convert(string a, int k){
    ll x = 0, p = 1;
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] != '0') x += (a[i] - '0') % 10 * p;
        p *= k;
    }
    return x;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int k; cin >> k;
    string a, b; cin >> a >> b;
    ll aa = (convert(a, k)), bb = (convert(b, k));
    cout << aa * bb;
    return 0;
}

