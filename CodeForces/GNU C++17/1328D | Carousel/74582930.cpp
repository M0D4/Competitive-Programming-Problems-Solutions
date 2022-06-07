#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((long long)n, (long long)m)
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 
void fast() {
 cin.tie(0); cout.tie(0);
 ios_base::sync_with_stdio(0);
}
 
bool compare(pii &a, pii &b) {
 return a.F > b.F;
}
 
ll numOfDigits(ll n) {
 if (!n) return 1;
 return (ll) (log10(n)) + 1;
}
 
 
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++) cin>>arr[i];
        vecint v(n);
        v[0] = 1;
        set<int> s ;
        for(int i = 1; i<n; i++){
            if(arr[i]==arr[i-1]){
                v[i] = v[i-1];
            }else{
                if(v[i-1]>1)
                    v[i] = 1;
                else v[i] = 2;
            }
        }
        if(arr[n-1]!=arr[0] && v[0]==v[n-1]){
            if(v[n-2]==2)v[n-1]=3;
            else v[n-1]=2;
        }
        for(auto &it:v)s.insert(it);
        if(s.size()<=2){
            cout<<s.size()<<endl;
            for(auto &it: v)cout<<it<<" ";
            cout<<endl;
        }else{
            vecint x(n);
            x[0] = 1;
            set<int> s2;
            bool flag = 1;
           for(int i = 1; i<n; i++){
                if(arr[i]==arr[i-1]){
                   if(flag) x[i] =((x[i-1]>1)?1:2), flag = 0;
                   else x[i] = x[i-1];
                }else{
                    if(x[i-1]>1)
                        x[i] = 1;
                    else x[i] = 2;
                }
          }
          if(arr[n-1]!=arr[0] && x[0]==x[n-1]){
            if(x[n-2]==2)x[n-1]=3;
            else x[n-1]=2;
        }
          for(auto &it:x)s2.insert(it);
          if(s2.size()<3){
              cout<<s2.size()<<endl;
                for(auto &it: x)cout<<it<<" ";
                cout<<endl;
          }else{
            cout<<s.size()<<endl;
            for(auto &it: v)cout<<it<<" ";
            cout<<endl;
          }
        }
    }
    return 0;
}
 
 
 
 
 