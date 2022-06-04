#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 const int N = 1e3;
int n, m, x, y;
int dots[N]; //to store count of dots in each column
int dp[3][N + 5][N + 5]; //type, index, width of bars
//0:dots; 1:#
 int solve(int ch, int j, int w){
    if(j==m) return (w>=x && w<=y?0:1e7);
     int &ret = dp[ch][j][w];
    if(~ret) return ret;
     int cnt = 1e7;
     if(ch==2 || (ch==0 && w+1<=y) || (ch==1 && w>=x))//first col || last is dots but width < y || last is # but has enough width
        cnt = n - dots[j] + solve(0, j+1, (ch==0? w+1: 1));
     if(ch==2 || (ch==1 && w+1<=y) || (ch==0 && w>=x))//first col || last is # but width < y || last is dots but has enough width
        cnt = min(cnt, dots[j] + solve(1, j+1, (ch==1? w+1: 1)));
      return ret = cnt;
}
  int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    cin>>n>>m>>x>>y;
    for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            char c; cin>>c;
            if(c=='.')
                dots[j]++;
        }
    }
     mem(dp, -1);
    cout<<solve(2, 0, 0);
 return 0;
}
 