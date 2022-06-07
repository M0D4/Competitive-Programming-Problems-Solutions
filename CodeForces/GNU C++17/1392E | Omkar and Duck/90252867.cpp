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
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
    ll a[n][n] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isOdd(i)) a[i][j] = (1LL << (i + j));
            cout << a[i][j] << " ";
        }
        cout << endl << flush;
    }
    int q; cin >> q;
    while(q--){
        ll k, row = 0, col = 0; cin >> k;
        cout << "1 1" << endl << flush;
        for(int step = 0; step + 2 <= 2*n - 1; step++) {
            if(row + 1 == n) col++;
            else if(col + 1 == n) row++;
            else if(!isOdd(row)){
                if((k ^ a[row + 1][col]) < k) row++;
                else col++;
            }else{
                if((k ^ a[row][col + 1]) < k) col++;
                else row++;
            }
            cout << row + 1 << " " << col + 1 << endl << flush;
        }
    }
    return 0;
}