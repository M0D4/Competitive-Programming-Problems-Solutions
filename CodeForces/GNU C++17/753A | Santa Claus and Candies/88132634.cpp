#include <bits/stdc++.h>
 using namespace std;
 #define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 int n;
const int N = 1e3 + 5;
int dp[N][N];
int solve(int i, int rem){
    if(!rem) return 0;
    if(i > rem) return -N;
     int &ret = dp[i][rem];
    if(~ret) return ret;
     ret = solve(i + 1, rem);
    if(rem >= i) ret = max(ret, 1 + solve(i + 1, rem - i));
     return ret;
}
void build(int i, int rem){
    if(!rem) return;
    if(i > rem) return;
     int ret = solve(i, rem);
    if(ret == solve(i + 1, rem)){
        build(i + 1, rem);
    }else if(rem >= i && ret == 1 + solve(i + 1, rem - i)){
        cout << i << " ";
        build(i + 1, rem - i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
    clr(dp, -1);
    cout << solve(1, n)<< endl;
    build(1, n);
    return 0;
}