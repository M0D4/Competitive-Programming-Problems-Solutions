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
 
 
int main()
{
    START
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> bullet(n), bomb(n);
        for(int i =0; i<n; i++) cin>>bullet[i]>>bomb[i];
        ll extraBullets = 0;
        for(int i = 0; i<n; i++){
            //suppose each monster exploded. it will affect next monster and we may need some extra bullets to kill it
            extraBullets += max(0ll, bullet[i] - bomb[i==0? n-1: i-1]);
        }
        ll mn = LLMAX;
        for(int i = 0; i<n; i++){
            //try to start by each monster: exclude him from extraBullets and add actual bullets
            ll need = extraBullets - max(0ll, bullet[i] - bomb[i==0? n-1: i-1]) + bullet[i];
            mn = min(mn, need);
        }
        cout<<mn<<endl;
    }
 return 0;
}
 