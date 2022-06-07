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
#define var auto
#define MOD 1000000007
 
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
int countFactor(ll n, ll factor){
    if(!n) return 1;
    ll cnt = 0;
    while(n%factor==0){
        cnt ++;
        n /=factor;
    }
   return cnt;
}
 
 
const int N = 1e3 + 5;
int n, zeroRow = -1, zeroCol = -1;
int arr[N][N][2];
int dp[N][N][2];
int solve(int r, int c, int ch){
    if(r==n-1 && c==n-1) return arr[r][c][ch];
 
    int &ret = dp[r][c][ch];
    if(~ret) return ret;
 
    ret = 1e8;
    if(r+1<n) ret = arr[r][c][ch] + solve(r+1, c, ch);
    if(c+1<n) ret = min(ret, arr[r][c][ch] + solve(r, c+1, ch));
 
    return ret;
}
 
int mn;
void printZeroPath(){
    for(int i =0; i<zeroCol; i++)
        cout<<"R";
    for(int i =1; i<n; i++)
        cout<<"D";
    for(int i =zeroCol+1; i<n; i++)
        cout<<"R";
 
}
void printPath(int r, int c, int ch){
    if(r==n-1 && c==n-1) return;
 
    int ans  = solve(r, c, ch);
    if(r+1 < n && ans == arr[r][c][ch] + solve(r+1, c, ch)){
        cout<<"D";
        printPath(r+1, c, ch);
    }else if(c+1<n){
        cout<<"R";
        printPath(r, c+1, ch);
    }
}
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j = 0; j<n; j++){
            int tmp; cin>>tmp;
            arr[i][j][0] = countFactor(tmp, 2);
            arr[i][j][1] = countFactor(tmp, 5);
            if(!tmp) zeroCol = j, zeroRow = i;
        }
    mem(dp, -1);
    mn = min(solve(0, 0, 0), solve(0, 0, 1));
    if(mn>1 && zeroRow!=-1){
        cout<<"1\n";
        printZeroPath();
        return 0;
    }
    cout<<mn<<endl;
    printPath(0, 0, solve(0, 0, 1)<solve(0, 0, 0));
 return 0;
}
 
/*
3
1 2 3
2 5 4
5 2 5
 
*/