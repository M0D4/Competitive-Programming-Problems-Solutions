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
 const int N = 2e5 + 5;
ll a[N], dp[N][3][2], n;
ll solve(int i, int stage, int one){
    if(i == n) return (stage == 1) * -1e15;
     ll &ret = dp[i][stage][one];
    if(~ret) return ret;
     ret = 0;
     if(stage == 0){
        ret = !isOdd(i) * a[i] + solve(i + 1, stage, one);
        ret = max(ret, isOdd(i) * a[i] + solve(i+1, 1, i % 2));
    }else if(stage == 1){
        ret = isOdd(i) * a[i] + solve(i+1, stage, one);
        if(one != isOdd(i)) //to reverse even sub-array only
            ret = max(ret, isOdd(i) * a[i] + solve(i + 1, 2, i % 2));
    }else{
        ret = !isOdd(i) * a[i] + solve(i+1, stage, one);
    }
     return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int t; cin >> t;
    while(t--){
       cin >> n;
         for(int i = 0; i < n; i++) cin >> a[i];
         for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 2; k++)
                    dp[i][j][k] = -1;
         cout << solve(0, 0, 0) << endl;
    }
    return 0;
}