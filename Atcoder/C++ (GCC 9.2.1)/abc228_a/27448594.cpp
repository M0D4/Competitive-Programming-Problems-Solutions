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

    int s, t, x; cin >> s >> t >> x;

    while (s != t){
        if(s == x)
            return cout << "Yes", 0;

        s = (s + 1) % 24;
    }
    cout << "No";
    return 0;
}