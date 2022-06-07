#include <bits/stdc++.h>
 
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
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
    //freopen("test cases\\input.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    int n, m; cin>>n>>m;
    int a[n], LIS[n + 1] = {}, mxG = 1;
    ld de7k;
    for(int i = 0; i<n; i++)
        cin>>a[i]>>de7k;
 
    /*
     we need to find the longest non-decreasing sequence.
     plants in this sequence will remain in its position
     and other plants (n - LIS) will be replanted
    */
    LIS[0] = 1;
    for(int i = 1; i<n; i++){
        int mx = 0;
        for(int j = 0; j<i; j++)
            if(a[j] <= a[i] && LIS[j] > mx) mx = LIS[j];
        LIS[i] = mx + 1;
        mxG = max(mxG, LIS[i]);
    }
    cout<< n - mxG;
 return 0;
}