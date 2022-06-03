#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))



typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> pii;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin >> n >> x;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        int c = (s[i] == 'o' ? 1 : -1);
        x = max(0, x + c);
    }
    cout << x;
    return 0;
}
