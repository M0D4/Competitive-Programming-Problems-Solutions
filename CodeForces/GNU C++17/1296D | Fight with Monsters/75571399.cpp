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
 
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int n, myPower, hisPower, k; cin>>n>>myPower>>hisPower>>k;
    int arr[n]; // to store mod
    int sumPower = myPower + hisPower;
    for(int i =0; i<n; i++){
        int a; cin>>a;
        int modu = a%sumPower;
        if(!modu) modu = sumPower;
        else if(modu<=myPower) modu = -1;
        arr[i] = modu;
    }
    sort(arr, arr+n);
    //for(auto it:arr)cout<<it<<" "; return 0;
    int points = 0;
    for(int i =0; i<n && k; i++){
        if(arr[i]!=-1){
            int mn = arr[i]/myPower + (arr[i]%myPower != 0) - 1;
            if(mn<=k) k-=mn, points++;
        }else points++;
    }
    cout<<points;
    return 0;
}
 