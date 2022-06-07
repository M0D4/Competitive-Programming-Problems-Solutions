#include <bits/stdc++.h>
#include <ext/numeric>
 
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
#define sz(x)          (int) x.size()
#define MOD 1000000007
#define EPS 1e-7
 
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
        int n, k; cin>>n>>k;
        int  arr[n];
        int freq[n+1] = {}, dis = 0;
        vector<int> v;
        for(int i =0; i<n; i++){
         cin>>arr[i];
         if(!freq[arr[i]]) v.pb(arr[i]);
         dis += (!freq[arr[i]]);
         freq[arr[i]]++;
         }
         if(k==n){
            cout<<n<<endl;
            for(int &i: arr)cout<<i<<" ";
            cout<<endl;
            continue;
        }
        if(dis>k){
            cout<<"-1\n";
            continue;
        }
 
       
        while(v.size()<k) v.pb(arr[v.size()]);
        int ss = v.size();
        cout<<n*k<<endl;
        for(int i = 0; i < n; i++)
           for(int &j: v) cout << j << " ";
        cout<<endl;
    }
 return 0;
}