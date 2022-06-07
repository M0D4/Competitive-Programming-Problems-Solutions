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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        ll sumL = 0, sumR = 0;
        int freqL[n] = {0}, freqR[n] = {0};
        int moreThanOne = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i], sumR +=arr[i];
            freqR[arr[i]]++;
            if(freqR[arr[i]]==2)moreThanOne++;
 
        }
        vector<pii> ways;
        for(ll i =0; i<n-1; i++){
            freqL[arr[i]]++;
            if(freqL[arr[i]]>1) break;
            freqR[arr[i]]--;
            if(freqR[arr[i]]==1)moreThanOne--;
            sumL += arr[i];
            sumR  -= arr[i];
           // cout<<sumL<<" "<<sumR<<endl;
            ll ii = i+1, jj = n-i-1;
            if(sumL== ii * (ii+1)/2 && sumR== jj * (jj+1)/2 && moreThanOne==0)
            ways.pb({ii, jj});
        }
        cout<<ways.size()<<endl;
        for(auto &it: ways)cout<<it.F<<" "<<it.S<<endl;
    }
    return 0;
}
 
 