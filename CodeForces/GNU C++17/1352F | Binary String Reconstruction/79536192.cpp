#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
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
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
  typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
  int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int a, b, c; cin>>a>>b>>c;
        string s1(a+1-!a, '0');
        string s2 = "";
        if(isOdd(b)) for(int i = 0; i<b; i++) s2 += (!isOdd(i)?'1':'0');
        else for(int i = 0; i+1<b; i++) s2 += (!isOdd(i)?'1':'0');
        string s3(c, '1');
        if(!a && b)cout<<'0';
        cout<<s1;
        cout<<s2;
        if(!b && c)cout<<1;
        cout<<s3;
        if(b && !isOdd(b))cout<<'0';
        cout<<endl;
    }
 return 0;
}
 