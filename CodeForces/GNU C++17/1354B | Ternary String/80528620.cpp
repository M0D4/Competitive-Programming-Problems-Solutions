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
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
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
        string s; cin>>s;
        int n = sz(s);
        int l = 0, r = 0, cnt = 0, mn = n+1;
        map<char, int> mp;
        while(l<n){
            while(r<n && cnt<3){
                if(!mp[s[r]]) cnt++;
                mp[s[r]]++;
                r++;
            }
            //cout<<cnt<<" "<<l<<" "<<r<<endl;
            if(cnt==3) mn = min(mn, r-l);
            if(mp[s[l]]==1) cnt--;
            mp[s[l]]--;
            l++;
            if(l>r) r = l;
        }
        cout<<(mn==n+1?0:mn)<<endl;
    }
 return 0;
}