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
        int n, x; cin>>n>>x;
        int freq[3000] = {0};
        vector<int> v;
        for(int i =0; i<n; i++){
            int a; cin>>a;
            freq[a]++;
        }
        for(int i = 1; i<=300&& x; i++){
            if(!freq[i])freq[i]++, x--;
        }
        int y;
        for(int i  = 1; i<=300; i++){
            if(!freq[i]){
                y = i-1;
                break;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}
  