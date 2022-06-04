#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    string s; cin >> s;
    int c = 0, a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') a++;
        else b++;
         if(isOdd(i)){
            if(a < b){
                s[i] = 'a';
                b--, a++;
                c++;
            }else if(b < a){
                s[i] = 'b';
                b++, a--;
                c++;
            }
        }
    }
    cout << c << endl << s;
    return 0;
}