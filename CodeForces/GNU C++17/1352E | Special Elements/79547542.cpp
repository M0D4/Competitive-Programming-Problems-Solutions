#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
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
typedef vector<int> vi;
  int main()
{
    START
    //freopen("test cases\\out.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n], cnt = 0;
        for(int &i: a) cin>>i;
        int solved[n+1];
        mem(solved, -1);
        for(int i = 0; i<n; i++){
            if(~solved[a[i]]){
                    cnt += solved[a[i]];
                    continue;
            }
            int l = 0, r = 0, flag = 0, sum = 0;
            while(l<n){
                while(r<n && sum<a[i]){
                    sum += a[r++];
                }
                if(r-l>1 && sum==a[i]){
                    flag = 1;
                    break;
                }
                sum -= a[l++];
                if(l>r) r = l;
            }
            cnt += flag, solved[a[i]] = flag;
        }
        cout<<cnt<<endl;
    }
 return 0;
}
 