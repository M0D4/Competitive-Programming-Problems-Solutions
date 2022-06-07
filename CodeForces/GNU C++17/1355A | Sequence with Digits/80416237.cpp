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
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
ll mul(ll n){
    string s = to_string(n);
    sort(all(s));
    return (s[0]-'0') * (s.back() - '0');
}
bool hasZero(ll n){
    string s = to_string(n);
    sort(all(s));
    return s[0]=='0';
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        ll a, k; cin>>a>>k;
        for(int i = 1; i<k; i++){
            if(hasZero(a)) break;
            a += mul(a);
        }
        cout<<a<<endl;
    }
 return 0;
}