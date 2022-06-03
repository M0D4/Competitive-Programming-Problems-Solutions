#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using pic = pair<int, char>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    string a; cin >> a;
    int x = stoi(a.substr(0, a.find('.')));
    int y = stoi(a.substr(a.find('.') + 1));
    if(y <= 2) cout << x << "-";
    else if(y <= 6) cout << x;
    else cout << x << "+";
    return 0;
}