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
   string s;
int n;
 bool palindrome(string s){
    string t = s;
    reverse(all(t));
     return s == t;
}
 int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        cin>>n>>s;
        bool ok = 1;
        for(int i = 0; i<n/2; i++){
            if(s[i]==s[n - i - 1] || s[i] + 2==s[n - i - 1] || s[i] - 2 == s[n - i - 1]);
            else ok = 0;
        }
        cout<<(ok? "YES" : "NO")<<endl;
    }
 return 0;
}