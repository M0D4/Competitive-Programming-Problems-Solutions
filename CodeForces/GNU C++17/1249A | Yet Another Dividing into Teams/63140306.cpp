#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   (v.begin(), v.end())
#define endl "\n";
#define pb push_back
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
void fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll pow (ll a, ll b);
ll numOfDigits(ll n);
int main()
{
    fast();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        vector<int> freq(101,1);
        fori(0,n) cin>>arr[i], freq[arr[i]] = 0;
        int cnt = 0;
        fori(1,101){
           stack<int>s;
           if(!freq[i]){
            cnt++;
            s.push(i);
            freq[i]++;
            forj(i+1,101)
                if(!freq[j]){
                    if(j!=s.top()+1){
                        freq[j]++;
                        s.push(j);
                    }
                }
           }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
 ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}