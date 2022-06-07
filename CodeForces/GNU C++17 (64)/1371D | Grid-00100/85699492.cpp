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
        ll n, k; cin >> n >> k;
        int a[n][n];
        memset(a, 0, n*n*sizeof(int));
        int x = 0, y = 0, start = 0, c = 0;
        while(k){
            if(c%n == 0) x = 0, y = start++;
            a[x][y] = 1;
            k--;
            x++, y++;
            x %= n, y %= n, c++;
        }
        int mnR = n*n, mxR = 0, mnC = n*n, mxC = 0;
        int sumR = 0, sumC = 0;
        for(int i = 0; i < n; i++){
            sumR = sumC = 0;
            for(int j = 0; j < n; j++){
                sumR += a[i][j];
                sumC += a[j][i];
            }
            mnC = min(mnC, sumC);
            mxC = max(mxC, sumC);
            mnR = min(mnR, sumR);
            mxR = max(mxR, sumR);
        }
        cout << pow(mxR - mnR, 2) + pow(mxC - mnC, 2) << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << a[i][j];
            cout << endl;
        }
    }
 
    return 0;
}