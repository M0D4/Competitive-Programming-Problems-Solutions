#include <bits/stdc++.h>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
   int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        bool a[n][m];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                cin>>a[i][j];
        bool vis[n][m] = {};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                    if(a[i][j]){//claimed
                        for(int x = 0; x<m; x++)
                            vis[i][x] = 1;
                        for(int x = 0; x<n; x++)
                            vis[x][j] = 1;
                    }
                }
        }
        int cnt = 0;
        bool f = 1;
        while(f){
            f = 0;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!a[i][j] && !vis[i][j]){
                        cnt++;
                        f = 1;
                        for(int x = 0; x<m; x++)
                            a[i][x] = 1;
                        for(int x = 0; x<n; x++)
                            a[x][j] = 1;
                        goto zone;
                    }
                }
            }
            zone:;
        }
        cout<<(!isOdd(cnt)?"Vivek":"Ashish")<<endl;
    }
 return 0;
}