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
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 bool isPrime(ll q){
    if(q==2) return 1;
    if(q<2 || (q>2 && !(q%2))) return 0;
     for(ll i = 2; i*i<q; i++)
        if(!(q%i)) return 0;
     return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(auto &i: arr) cin>>i;
        if(n<=11){
            cout<<n<<endl;
            for(int i = 1; i<=n; i++)
                cout<<i<<" ";
            cout<<endl;
        }else{
            int c = 1, cnt = 0;
            vector<int> v(n);
            for(int i = 2; cnt<n; i++){
                bool flag = 0;
                if(isPrime(i)){
                    for(int j = 0; j<n; j++){
                        if(!v[j] && arr[j]%i==0)
                            v[j] = c, cnt++, flag = 1;
                    }
                    if(flag)c++;
                }
            }
            set<int> s;
            for(int &i: v)s.insert(i);
            cout<<s.size()<<endl;
            for(int &i: v)cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}
    