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
typedef vector<int> vi;
 struct compare{
    bool operator()(const pii &p1, const pii &p2) const
    {
        if(p1.S-p1.F==p2.S-p2.F) return p1.F < p2.F;
        return p1.S - p1.F > p2.S - p2.F;
    }
};
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
       int n; cin>>n;
       set<pii, compare> s;
       s.insert({1, n});
       int a[n+1] = {0};
       for(int i = 1; i<=n; i++){
            pii p = *s.begin();
            int l = p.F, r = p.S, mid = (l+r)>>1;
            a[mid] = i;
            s.erase(s.begin());
            s.insert({l, mid-1}), s.insert({mid+1, r});
       }
       for(int i = 1; i<=n; i++)
        cout<<a[i]<<" ";
       cout<<endl;
    }
 return 0;
}