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
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int &i: a)cin>>i;
        int l = 0, r = n-1, alice = 0, bob = 0, cnt = 0, last = 0;
        while(l<=r){
            int sum = 0;
            if(!last || !isOdd(cnt)){
                if(!last) sum += a[l++];
                while(l<=r && sum<=last) sum += a[l++];
                alice += sum;
            }else {
                while(r>=l && sum<=last) sum += a[r--];
                bob += sum;
            }
            cnt++;
            last = sum;
        }
        cout<<cnt<<" "<<alice<<" "<<bob<<endl;
    }
 return 0;
}
 