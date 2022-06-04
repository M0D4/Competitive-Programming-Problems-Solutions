#include "bits/stdc++.h"
 using namespace std;
 #define pb              push_back
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
    int n, m, r, c; cin >> n >> m >> r >> c;
    cout << r << " " << c << endl;
    cout << 1 << " " << c << endl;
    cout << "1 1\n";
    int row = 1;
    while(row <= n){
        for(int col = 1; col <= m; col++){
            if(row == r && col == c || (row == 1 && col == 1) || (row == 1 && col == c)) continue;
            cout << row << " " << col << endl;
        }
        row++;
        if(row > n) break;
        for(int col = m; col > 0; col--){
            if(row == r && col == c || (row == 1 && col == 1) || (row == 1 && col == c)) continue;
            cout << row << " " << col << endl;
        }
        row++;
    }
    return 0;
}