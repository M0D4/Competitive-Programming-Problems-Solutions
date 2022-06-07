#include <bits/stdc++.h>
 
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        bool vis[n + 1] = {};
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                int l = i-1;
                while(l >= 0 && abs(l - i) <= k) vis[l--] = 1;
                int r = i + 1;
                while(r < n && abs(r - i) <= k) vis[r++] = 1;
            }
        }
        int c = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='0' && !vis[i]){
                c++;
                 int l = i-1;
                while(l >= 0 && abs(l - i) <= k) vis[l--] = 1;
                int r = i + 1;
                while(r < n && abs(r - i) <= k) vis[r++] = 1;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}