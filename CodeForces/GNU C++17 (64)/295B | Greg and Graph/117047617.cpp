#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
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
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    int dp[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> dp[i][j];
 
    bool vis[n] = {};
    vector<int> query(n);
    for(auto &i: query) cin >> i, i--;
    reverse(all(query));
 
    vector<ll> sums;
    for(auto &k: query){
        ll sum = 0;
        vis[k] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                if(vis[i] && vis[j]) sum += dp[i][j];
            }
        }
        sums.push_back(sum);
    }
    reverse(all(sums));
    for(auto &i: sums) cout << i << " ";
    return 0;
}