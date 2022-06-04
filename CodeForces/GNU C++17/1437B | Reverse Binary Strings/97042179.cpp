#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
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
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
       int n; cin >> n;
       string s; cin >> s;
       int c = 0;
       for(int i = 1; i < n; i++)
            c += (s[i] == s[i - 1]);
        c++;
       cout << (c >> 1) << endl;
    }
    return 0;
}