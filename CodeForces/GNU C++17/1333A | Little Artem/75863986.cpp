#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        char arr[n][m];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                arr[i][j] = '.';
        arr[0][0]='W', arr[0][1]='B', arr[1][0] = 'B';
        for(int i =0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(arr[i][j]=='.') arr[i][j] = 'B';
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++)
                cout<<arr[i][j];
            cout<<endl;
        }
    }
 return 0;
 
}