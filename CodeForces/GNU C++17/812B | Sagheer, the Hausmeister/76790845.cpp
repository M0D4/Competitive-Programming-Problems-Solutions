#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define Th third
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
 
const int N = 15, M = 110;
int n, m;
pii stairs[N];
 
int solve(int i, int side){
    if(i==n-1) return (side? m - stairs[i].F - 1: stairs[i].S);//in last floor: just turn off all lights and stop there!
 
    int ret = 1e9;
 
    if(!side) ret = 2 * stairs[i].S + solve(i+1, 0); //on left side and will take left stair
    else  ret = 2 * (m - stairs[i].F - 1) + solve(i+1, 1);// on right side and will take right stair
 
    ret = min(ret, m - 1 + solve(i+1, !side));//will go from one side to the other side
 
    return ret + (ret != 0);
}
int main()
{
    START
    //freopen("test cases\\.txt", "r", stdin) ;
    cin>>n>>m;
    m += 2;
 
    for(int i = 0; i<n; i++){
        bool b, flag = 1;
        int k = n - i -1;
        stairs[k].F = m - 1;
        for(int j = 0; j<m; j++){
            char c; cin>>c; b = c=='1';
            if(b && flag) stairs[k].F = j, flag = 0; //leftmost
            if(b) stairs[k].S = j; //rightmost
        }
    }
 
    int i = n-1;
    while(i>=0 && stairs[i].F == m-1 && stairs[i].S == 0) i--, n--;//while last floor is empty
 
    cout<<(n? solve(0, 0): 0);
 return 0;
}