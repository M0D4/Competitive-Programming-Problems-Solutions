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
 
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 
int n, m;
 
bool ok(int r, int c){
    return ~r && ~c && r < n && c < m;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n >> m;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'W'){
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(ok(x, y) && a[x][y] == '.')
                        a[x][y] = 'D';
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'S'){
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(ok(x, y) && a[x][y] == 'W')
                        return cout << "No", 0;
                }
            }
        }
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}