#include "bits/stdc++.h"
 using namespace std;
 #define pb              push_back
//#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 28, M = 1e4 + 5;
ll a[N][N], n;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isOdd(i)) a[i][j] = 0;
            else a[i][j] = (1LL << (i + j));
            cout << a[i][j] << " ";
        }
        cout << endl;
        fflush(stdout);
    }
    int q; cin >> q;
    while(q--){
        ll k, row = 0, col = 0; cin >> k;
        cout << "1 1" << endl;
        fflush(stdout);
        for (int diag = 0; diag < 2*n - 2; diag++) {
   if(row == n - 1) col++;
   else if(col == n - 1) row++;
   else if (row + 1 < n && a[row+1][col] == (k & (1LL << (diag + 1)))) row++;
   else col++;
   cout << row+1 << " " << col+1 << endl << flush;
  }
    }
    return 0;
}