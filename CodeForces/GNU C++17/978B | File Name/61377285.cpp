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
int BN(int freq[],dd arr[], int n, dd val);
int main()
{
    fast();
    int n; str s; cin>>n>>s;
    s +="..";
    stack<char>st;
    int cnt = 0;
    fori(0,s.size()-2){
       if(s.substr(i,3)=="xxx")
            s.erase(i+2,1), i--, cnt++;
    }
    //cout<<s<<"\n";
    cout<<cnt;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
  int BN(int freq[],dd arr[], int n, dd val){
    int low  = 0;
    int up = n-1;
    int ans = -1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
         if(arr[mid]==val && !freq[mid]) return mid;
        if(arr[mid]<val){
            low = mid+1;
        }else up = mid -1;
    }
    return ans;
}