#include <bits/stdc++.h>
using namespace std;
 
#define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE; fast();
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 
void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
 
ll numOfDigits(ll n);
ll BN (ll arr[], ll j, ll val);
bool compare(int &a, int &b){
    return a>b;
}
 
bool is_prime(ll n){
    for(int i =1; i*i<n; i++)
        if(!(n%i)) return 0;
    return 1;
}
str dv[125] = {"0", "8", "16", "24", "32", "40",
 "48", "56", "64", "72", "80", "88", "96", "104",
  "112", "120", "128", "136", "144", "152", "160",
   "168", "176", "184", "192", "200", "208", "216",
    "224", "232", "240", "248", "256", "264", "272",
     "280", "288", "296", "304", "312", "320", "328",
      "336", "344", "352", "360", "368", "376", "384",
       "392", "400", "408", "416", "424", "432", "440",
        "448", "456", "464", "472", "480", "488", "496",
         "504", "512", "520", "528", "536", "544", "552",
          "560", "568", "576", "584", "592", "600", "608",
           "616", "624", "632", "640", "648", "656", "664",
           "672", "680", "688", "696", "704", "712", "720",
           "728", "736", "744", "752", "760", "768", "776",
           "784", "792", "800", "808", "816", "824", "832",
           "840", "848", "856", "864", "872", "880", "888",
           "896", "904", "912", "920", "928", "936", "944",
           "952", "960", "968", "976", "984", "992"};
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Divisibility by Eight.txt", "r", stdin);
    str s; cin>>s;
    int n  = s.size();
    bool flag = 0;
    fori(0, 125){
        flag = 0;
       str ss = dv[i];
       int m = ss.size(), cnt =0;
       forj(0, n)
        if(s[j]==ss[cnt])cnt++;
 
        if(cnt==m){
            flag = 1;
            cout<<"YES\n"<<ss;
            break;
        }
    }
    if(!flag)cout<<"NO";
    return 0;
}
/*
ll BN (ll arr[], ll j, ll val){
int low = j;
int up = n-1;
ll ans = -1;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(abs(arr[mid]-val)<=d){
        ans = mid;
        low = mid+1;
    }else up = mid-1;
}
return ans;
}*/
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}