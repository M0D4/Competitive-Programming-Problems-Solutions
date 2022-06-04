#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define fore(v)           for(auto &it: v)
#define rep(i, v)         for(int i=0; i<v.size(); i++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define sc scanf
#define print printf
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
   ull pow (ll a, ll b);
 dd BN (vector<pii> &v, ll n, ll m);
   /*
 */
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
     int t; cin>>t;
    while(t--) {
        str s; cin>>s;
        int n = s.size();
        int freq[26]={0};
        str ans =""; ans+=s[0]; freq[s[0]-'a']++;
        str ans2= ans;
        bool f = 1;
        for(int i = 1; i<n; i++){
            char cur = s[i], prev = s[i-1];
            str sub = s.substr(i-1,2), rev = sub;
            reverse(all(rev));
            bool flag = 0;
            if(ans.size()>1) {
                for (int j = 0; j < ans.size() - 1; j++) {
                    if (ans.substr(j, 2) == sub || ans.substr(j, 2) == rev) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) continue;
            if(freq[cur-'a']){
                f = 0;
                break;
            }
            if(ans[0]==prev){
                 str tm ="";
                tm += cur;
                ans  = tm+ans;
                if(ans.size()==2) ans2 +=tm;
                freq[cur-'a']++;
            }else if(ans[ans.size()-1]==prev){
                str tm = "";
                tm += cur;
                ans += tm;
                freq[cur-'a']++;
            }else{
                f = 0;
                break;
            }
        }
        if(!f) {
            //cout<<ans<<endl;
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            for(int i=0; i<26; i++){
                if(!freq[i])ans+=(i+'a');
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
  dd BN (vector<pii> &v, ll n, ll m){
    dd low = 0;
    dd up = 1e21;
    dd ans = 0;
    while(low<=up){
        dd mid = trunc((low+ up)/2);
        dd fx = 0;
        fori(0, n){
            fx += max(0.0, mid-v[i].F)*v[i].S;
        }
        if(fx<=m) {
            ans = mid;
            low = mid+1;
        }else up = mid-1;
    }
    return ans;
}
  ull pow (ll a, ll b){
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}