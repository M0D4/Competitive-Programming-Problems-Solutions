#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
*/
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
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
 
int fix(int n, int m){
    int ans = n%m;
    if(ans<0){
        ll x = -ans/m + (-ans%m != 0);
        ans += x * m;
    }
    return ans;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int freq[n];
        fill(freq, freq+n, 1);
        for(int i =0; i<n; i++){
            int a; cin>>a;
            freq[i]--;
            freq[(i + fix(a, n))%n]++;
        }
        bool flag = 1;
        for(int i =0; i<n && flag; i++)
            if(freq[i]!=1) flag = 0;
        cout<<(flag?"YES":"NO")<<endl;
    }
 return 0;
}