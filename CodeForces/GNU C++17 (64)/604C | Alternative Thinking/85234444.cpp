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
 const int N = 100000 + 5, inf = 1e7;
string s;
int n;
int dp[N][3][2];
int solve(int i, int stage, int last){
    if(i == n) return 0;
     int &ret = dp[i][stage][last];
    if(~ret) return ret;
     int cur = s[i] - '0';
     ret = solve(i+1, stage, last); // leave
     if(stage == 0 && cur != last) ret = max(ret, 1 + solve(i+1, 0, !last));
    else if(stage <= 1 && cur == last) ret = max(ret, 1 + solve(i+1, 1, !last));
    else if(stage >= 1 && cur != last) ret = max(ret, 1 + solve(i+1, 2, !last));
     return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n >> s;
    clr(dp, -1);
    cout << solve(0, 0, !(s[0] - '0'));
    return 0;
}