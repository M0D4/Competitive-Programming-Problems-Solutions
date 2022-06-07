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
 
int n, k;
string s;
 
int main()
{
    START
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        cin>>n>>k>>s;
        string tmp = s;
        bool freq[n+1] = {false};
        bool flag = 1;
        for(int i =0; i<n && flag; i++){
            if(freq[i]){
                flag  = 1;
                break;
            }
            map<char, int> mp;
            int mxFreq = i;
            for(int j = i; j<n; j+=k){
                freq[j] = 1;
                mp[s[j]]++;
                if(mp[s[j]]>mp[s[mxFreq]])
                    mxFreq = j;
            }
            for(int j = i; j<n; j+=k){
                int x = n - j - 1;
                freq[x] = 1;
                mp[s[x]]++;
                if(mp[s[x]]>mp[s[mxFreq]])
                    mxFreq = x;
            }
            for(int j = i; j<n; j+=k){
                int x = n - j - 1;
                s[j] = s[x] = s[mxFreq];
            }
        }
        int cost = 0;
        for(int i = 0; i<n; i++)
            if(s[i]!=tmp[i])
                cost++;
        cout<<cost<<endl;
    }
 return 0;
}
 