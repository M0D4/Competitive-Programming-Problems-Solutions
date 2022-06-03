#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
*/
using namespace std;
using namespace __gnu_cxx;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
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
typedef vector<ll> vi;

const int N = 3e3 + 5;
string s, t;
int n, m;
int dp[N][N];
int solve(int i = 0, int j = 0){
    if(i==n || j==m) return 0;

    int &ret = dp[i][j];
    if(~ret) return ret;

    if(s[i]==t[j])
       return ret = 1 + solve(i+1, j+1);

    int cnt = 0;
    cnt = max(solve(i+1, j), solve(i, j+1));

    return ret = cnt;
}

int cnt;
void print(int i = 0, int j = 0){
    if(i==n || j==m) return;

    int ans = solve(i, j);
    if(ans==solve(i+1, j)) print(i+1, j);
    else if(ans== solve(i, j+1))print(i, j+1);
    else{
        cout<<s[i];
        print(i+1, j+1);
        cnt++;
    }


}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
     cin>>s>>t;
     n = sz(s), m = sz(t);
     mem(dp, -1);
     solve(), print();
     if(!cnt)cout<<"";
	return 0;
}
