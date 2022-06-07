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
        int n; cin>>n;
        vector<int> arr(n);
        for(auto &i: arr)cin>>i;
        /*
            we can make prefix strictly increasing iff for[1:k] each arr[i]>=i
            and we can make suffix strictly decreasing iff for(n-1:k) each arr[i]>=n-1-i (0-indexed)
            so we need to find max suffix length we can make
            and max suffix length we can make,
            if the max suffix index <= max prefix index, the answer is Yes.
        */
        int mxPrefix = -1, mxSuffix = n;
        for(int i = 0; i<n; i++)
            if(arr[i]>=i) mxPrefix = i;
            else break;
        for(int i = n-1; i>=0; i--)
            if(arr[i]>=n-1-i)mxSuffix = i;
            else break;
        cout<<(mxSuffix<=mxPrefix?"Yes":"No")<<endl;
    }
 return 0;
}
 