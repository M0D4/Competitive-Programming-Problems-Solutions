#include "bits/stdc++.h"
 
#pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
 
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
        int a[n], mx = 0, mxIndex = -1;
        for(int &i: a) cin >> i;
        if(count(a, a + n, a[0]) == n){
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < n; i++){
            if(a[i] > mx) mx = a[i];
        }
        for(int i = 0; i < n; i++){
            if(a[i] == mx){
                if(i + 1 < n && a[i + 1] < a[i]){
                    mxIndex = i;
                    break;
                }
                if(i - 1 >= 0 && a[i - 1] < mx){
                    mxIndex = i;
                    break;
                }
            }
        }
        cout << mxIndex + 1 << endl;
    }
    return 0;
}