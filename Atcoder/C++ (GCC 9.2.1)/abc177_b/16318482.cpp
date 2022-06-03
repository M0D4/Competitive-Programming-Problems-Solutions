#include "bits/stdc++.h"

using namespace std;

#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size(), mn = m;
    for(int i = 0; i + m <= n; i++){
        int c = 0;
        for(int j = 0, k = i; j < m; j++, k++){
            c += (s[k] != t[j]);
        }
        mn = min(mn, c);
    }
    cout << mn;
    return 0;
}
