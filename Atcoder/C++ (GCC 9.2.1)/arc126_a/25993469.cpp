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

    int tc; cin >> tc;
    while (tc--){
        ll a, b, c; cin >> a >> b >> c;

        ll three = b / 2;

        ll mn = min(three, c);
        ll sticks = mn;

        b -= 2 * mn;
        c -= mn;

        ll four = c / 2;
        mn = min(four, a);
        sticks += mn;
        c -= 2 * mn;
        a -= mn;

        ll two = a / 2;
        three = b / 2;

        mn = min(two, three);
        sticks += mn;
        a -= 2 * mn;
        b -= 2 * mn;

        two = a / 3;
        mn = min(two, c);
        sticks += mn;
        a -= 3 * mn;
        c -= mn;

        sticks += a / 5;

        cout << sticks << endl;
    }
    return 0;
}

