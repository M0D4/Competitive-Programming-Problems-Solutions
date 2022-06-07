#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
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
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define var auto
#define MOD 1000000007
 
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        string x = "", y = "";
        bool flag = 1;
        for(int i =1; i<n; i++){
            if(s[i]!=s[i-1]){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<s<<endl;
            continue;
        }
        for(int i =0; i<2*n; i+=2) x+="10";
        for(int i =0; i<2*n; i+=2) y+="01";
        int c = 0, z = 0;
        for(int i =0; i<2*n; i++)
            if(x[i]==s[c])c++;
        if(c==n){
            cout<<x<<endl;
            continue;
        }
        c = 0;
        for(int i =0; i<2*n; i++)
            if(y[i]==s[c])c++;
        cout<<y<<endl;
    }
 return 0;
}