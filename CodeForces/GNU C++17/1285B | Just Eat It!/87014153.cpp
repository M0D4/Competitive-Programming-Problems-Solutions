#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        ll y = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool yasser = 1;
        for(int i = 0; i < n; i++){
            y += a[i];
            if(y <= 0){
                yasser = 0;
                break;
            }
        }
        y = 0;
        for(int i = n - 1; ~i; i--){
            y += a[i];
            if(y <= 0){
                yasser = 0;
                break;
            }
        }
        cout << (yasser ? "YES" : "NO") << endl;
    }
    return 0;
}