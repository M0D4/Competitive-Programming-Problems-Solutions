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
        string s; cin>>s;
        map<pii, int> mp;
        pii cur = {0, 0};
        mp[cur] = 0;
        ll left = -1, right = n;
        for(int i = 0; i<n; i++){
            if(s[i]=='L') cur.F--;
            else if(s[i]=='R') cur.F++;
            else if(s[i]=='U') cur.S++;
            else cur.S--;
            if(mp.find(cur)!=mp.end()){//reached this point before
                if(i - mp[cur] + 1 < right - left + 1)//has shorter path
                    left = mp[cur], right = i;
            }
            mp[cur] = i+1;
        }
        if(~left) cout<<left+1<<" "<<right+1<<endl;
        else cout<<"-1\n";
    }
 return 0;
 
}