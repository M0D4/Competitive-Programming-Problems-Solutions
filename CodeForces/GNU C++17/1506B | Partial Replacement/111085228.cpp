#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int first = s.find('*'), last = s.find_last_of('*');
         int cnt = 0, len = 0;
        s[last] = s[first] = 'x';
        for (int i = first; i <= last; ++i) {
            if(s[i] == 'x'){
                for (int j = i + k; j < n && j > i; --j) {
                    if(s[j] == 'x') break;
                    if(s[j] == '*'){
                        s[j] = 'x';
                        cnt++;
                        i = j - 1;
                        break;
                    }
                }
            }
        }
        cout << cnt + 1 + (first != last) << endl;
    }
    return 0;
}