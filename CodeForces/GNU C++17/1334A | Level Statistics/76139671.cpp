#include <bits/stdc++.h>
#include <ext/numeric>
 
using namespace std;
using namespace __gnu_cxx;
 
#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
typedef string str;
typedef pair<int, int> pii;
 
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> p(n), cle(n);
        for(int i = 0; i<n; i++) cin>>p[i]>>cle[i];
        if(p[0]<cle[0]){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag  = 1;
        for(int i = 1; i<n; i++){
            if(p[i]<p[i-1]) {
                flag = 0;
                break;
            }
            if(cle[i]<cle[i-1]) {
                flag = 0;
                    break;
            }
            if(cle[i]>p[i]) {
                flag = 0;
                    break;
            }
            if(cle[i]-cle[i-1]>p[i]-p[i-1]){
                flag = 0;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
 return 0;
 
}