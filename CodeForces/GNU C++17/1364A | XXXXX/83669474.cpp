#include <bits/stdc++.h>
 
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        ll l = -1, r = -1;
        int a[n + 1] = {};
        for(int i = 1; i<=n; i++) cin>>a[i];
        ll sum = 0, mx = -1;
        for(ll i = 1; i<=n; i++){
            sum += a[i];
            sum %= x;
            if(sum && l==-1) l = i;
            if(sum) r = i;
            if(sum!=0) mx = max(mx, i);
            else{
                //from left
                if(l==-1) continue;
                mx = max(mx, i - l);
                //from right
                mx = max(mx, r - 1);
            }
        }
        if(!mx) mx = -1;
        cout<<mx<<endl;
    }
 return 0;
}