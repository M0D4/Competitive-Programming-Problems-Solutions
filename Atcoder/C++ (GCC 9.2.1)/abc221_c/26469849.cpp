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

    string s; cin >> s;
    sort(all(s));
    ll mx = 0;
    do{
        if(s[0] == '0') continue;
        string t = "";
        t += s[0];
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] != '0'){
                mx = max(mx, stoll(t) * stoll(s.substr(i)));
            }
            t += s[i];
        }
    } while (next_permutation(all(s)));

    cout << mx;
    return 0;
}

