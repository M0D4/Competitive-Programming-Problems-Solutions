#include <bits/stdc++.h>
using namespace std;
 #define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
#define pow POW
 typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast() {
 cin.tie(0);
 cout.tie(0);
 cin.sync_with_stdio(0);
}
 bool compare(int &a, int &b) {
 return a > b;
}
 ll numOfDigits(ll n) {
 if (!n)
  return 1;
 return (ll) (log10(n)) + 1;
}
 ull POW(ll a, ll b);
 /*
  */
 ll BN();
bool ends_with(const str & a, const str & b) {
    if(a.size()<b.size()) return 0;
    for(int i=a.size()-1; i>=0; i--){
        if(a.substr(i)==b)return 1;
    }
    return 0;
}
int main() {
 JULEE_DO_THE_THING;
 //freopen("test cases\\.txt", "r", stdin) ;
    map<str, vector<str>> mp;
    int n; cin>>n;
    while(n--){
        str name; cin>>name;
        int numbers; cin>>numbers;
        while(numbers--){
            str num; cin>>num;
            bool flag = 1;
            for(auto &it: mp[name]){
                if(ends_with(it, num)){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                mp[name].pb(num);
            }
        }
    }
    for(auto &it: mp){
        for(int i = 0; i<it.S.size(); i++){
            bool flag = 0;
            for(int j=0; j<it.S.size(); j++){
                if(i==j)continue;
                if(ends_with(it.S[j],it.S[i])){
                    flag = 1;
                    break;
                }
            }
            if(flag)it.S.erase(it.S.begin()+i), i--;
        }
    }
    cout<<mp.size()<<endl;
    for(auto &it: mp){
        cout<<it.F<<" "<<it.S.size()<<" ";
        for(auto &j: it.S){
            cout<<j<<" ";
        }
        cout<<endl;
    }
 return 0;
}
 ll BN() {
 ll low = 0;
 ll up = 0;
 ll ans = 0;
 while (low <= up) {
  ll mid = ((low + up) / 2);
  if (mid) {
   ans = mid;
   low = mid + 1;
  } else
   up = mid - 1;
 }
 return ans;
}
 ull POW(ll a, ll b) {
 ull res = 1;
 while (b > 0) {
  if (b & 1)
   res = res * a;
  a = a * a;
  b >>= 1;
 }
 return res;
}