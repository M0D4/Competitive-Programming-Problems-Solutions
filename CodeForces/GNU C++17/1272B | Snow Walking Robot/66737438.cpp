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
#define to_str to_string
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
 int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Snow Walking Robot.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        str s; cin>>s;
        int n = s.size();
        map<char, int> mp;
        fori(0, n) mp[s[i]]++;
        int mnUD = min(mp['U'], mp['D']);
        int mnRL = min(mp['R'], mp['L']);
        ll total = mnUD*2 + mnRL*2;
        /*
        mp[U] must equal to mp[D]
        and mp[R] must equal to mp[L]
        to make closed loop from (0,0) to (0,0)
        so we take min(R, L) and min(U, D)
        */
        if(!total || !mnUD || !mnRL){
            if(!mnUD){
                //if min(U, D)==0 we can't make more LR or RL
                mnRL = min(mnRL, 1);
                cout<<mnRL*2<<endl;
                fori(0, mnRL)cout<<"R";
                fori(0, mnRL)cout<<"L";
            }else if(!mnRL){
                //if min(L, R)==0 we can't make more UD or DU
                mnUD = min(mnUD, 1);
                cout<<mnUD*2<<endl;
                fori(0, mnUD)cout<<"U";
                fori(0, mnUD)cout<<"D";
            }
            cout<<endl;
        }else{
        cout<<total<<endl;
        fori(0, mnRL)cout<<"R";
        fori(0, mnUD)cout<<"U";
        fori(0, mnRL)cout<<"L";
        fori(0, mnUD)cout<<"D";
        cout<<endl;
        }
    }
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