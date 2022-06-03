#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define what_is(x)      cerr << #x << " is " << x << endl;


using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> a(1 << n);
    for(auto &i: a) cin >> i;
    for(int i = 0; i < (1 << n); i++)
        mp[a[i]] = i + 1;
    for(int i = n; i > 1; i--){
        vector<int> b;
        for(int j = 0; j < (1 << i); j += 2)
            b.push_back(max(a[j], a[j + 1]));
        a = b;
    }
    cout << mp[min(a[0], a[1])];
    return 0;
}