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
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
   int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n = 8, c = 0;
    string a[n];
    for(int i = 0; i < n; i++){
        a[i] = string(8, ' ');
        for(int j = 0; j < n; j++)
         cin >> a[i][j];
         if(a[i] == string(8, 'B')){
            c++;
            for(int j = 0; j < n; j++)
                a[i][j] = 'W';
        }
    }
     for(int col = 0; col < n; col++){
        int x = 0;
        for(int row = 0; row < n; row++)
            x += (a[row][col] == 'B');
        c += !!x;
    }
     cout << c;
    return 0;
}