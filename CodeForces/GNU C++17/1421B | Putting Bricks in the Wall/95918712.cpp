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
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
void flip(char &c){
    if(c == '0') c = '1';
    else c = '0';
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
 
        char a[n][n];
 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        bool a10 = 0, a01 = 0, ax = 0, ay = 0;
 
        int one = 0, zero = 0;
        (a[1][0] == '0' ? zero++ : one++);
        (a[0][1] == '0' ? zero++ : one++);
        (a[n - 1][n - 2] == '0' ? zero++ : one++);
        (a[n - 2][n - 1] == '0' ? zero++ : one++);
 
        if(a[1][0] != a[0][1]){
            if(zero >= one){
                if(a[0][1] == '0' && a[1][0] != '0') a01 = 1, flip(a[0][1]);
                else if(a[0][1] != '0' && a[1][0] == '0') a10 = 1, flip(a[1][0]);
            }else if(one >= zero){
                if(a[0][1] == '0' && a[1][0] != '0') a10 = 1, flip(a[1][0]);
                else if(a[0][1] != '0' && a[1][0] == '0') a01 = 1, flip(a[0][1]);
            }
        }
        if(a[n - 1][n - 2] == a[1][0]) ax = 1, flip(a[n - 1][n - 2]);
        if(a[n - 2][n - 1] == a[1][0]) ay = 1, flip(a[n - 2][n - 1]);
 
 
        cout << a10 + a01 + ax + ay << endl;
        if(a10) cout << "2 1\n";
        if(a01) cout << "1 2\n";
        if(ax) cout << n << " " << n - 1 << endl;
        if(ay) cout << n - 1 << " " << n << endl;
    }
    return 0;
}