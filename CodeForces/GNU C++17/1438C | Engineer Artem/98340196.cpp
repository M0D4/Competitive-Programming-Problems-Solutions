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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
 
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool f = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x; cin >> x;
                if(f){
                    if((j & 1) && (x & 1)) x++;
                    else if(!(j & 1) && !(x & 1)) x++;
                }else{
                    if((j & 1) && !(x & 1)) x++;
                    else if(!(j & 1) && (x & 1)) x++;
                }
                cout << x << " " ;
            }
            f = !f;
            cout << endl;
        }
    }
    return 0;
}