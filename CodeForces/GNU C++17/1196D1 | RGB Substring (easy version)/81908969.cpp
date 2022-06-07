#include <bits/stdc++.h>
#include <ext/numeric>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
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
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define MAX 100000
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct pro{
    int x, y, f[4];
};
 
int n, k;
int calc(string &s, string &t){
    int cnt = 2000;
    for(int i = 0; i<=n-k; i++){
        int c = 0;
        for(int j = i, x = 0; x<k; j++, x++)
            if(s[j]!=t[x]) c++;
        cnt =  min(cnt , c);
    }
    return cnt;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        string s; cin>>s;
        string t1 = "RGB", t2 = "GBR", t3 = "BRG";
        while(t1.size()< 2000){
            t1 += t1;
            t2 += t2;
            t3 += t3;
        }
        string sub = t1.substr(0, k);
        int mn =  calc(s, sub);
        sub = t2.substr(0, k);
        mn = min(mn, calc(s, sub));
        sub = t3.substr(0, k);
        mn = min(mn, calc(s, sub));
        cout<<mn<<endl;
    }
 return 0;
}