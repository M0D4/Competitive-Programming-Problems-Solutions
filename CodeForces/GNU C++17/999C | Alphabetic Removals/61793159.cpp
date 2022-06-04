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
int BN(ll arr[], int n, ll val);
bool sortSecondInRev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
}
bool isPowerOf2(ll tmp);
//int freq[101];
int main()
{
    fast();
    int n, kk, cnt = 0; cin>>n>>kk;
    str s; cin>>s;
    for(char i  = 'a'; i<='z'; i++){
        forj(0,n){
                if(s[j]==i){
                    s[j]=' ';
                    cnt++;
                    if(cnt==kk){
                        fork(0,n)
                            if(s[k]!=' ')
                                cout<<s[k];
                        return 0;
                    }
                }
        }
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
bool isPowerOf2(ll tmp){
    fori(0,32){
        ll power = pow(2,i);
            if(power==tmp) return 1;
    }
    return 0;
}
 int BN(ll arr[], int n, ll val){
    int low  = 1;
    int up = n;
    int ans = 1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
        if(arr[mid]<val){
            low = mid+1;
        }else ans = mid, up = mid -1;
    }
    return ans;
}