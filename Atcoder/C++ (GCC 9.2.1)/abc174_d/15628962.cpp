#include "bits/stdc++.h"

using namespace std;

#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define EPS 1e-7

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    int r = count(all(s), 'R');
    if(r == n || !r) return cout << 0, 0;
    int w = n - r, c = 0;
    string x = string(r, 'R') + string(w, 'W');
    for(int i = 0; i < n; i++){
        if(s[i] != x[i]) c++;
    }
    cout << c/2;
    return 0;
}
