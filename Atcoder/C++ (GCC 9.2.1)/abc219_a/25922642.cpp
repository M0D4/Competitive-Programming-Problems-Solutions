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

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    vector<int> v = {40, 70, 90};
    int x; cin >> x;
    auto it = upper_bound(all(v), x);
    if(it == v.end()) cout << "expert";
    else{
        cout << *it - x;
    }
    return 0;
}

