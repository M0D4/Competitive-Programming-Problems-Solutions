#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int q; cin>>q;
    while(q--){
        string s; cin>>s;
        int n; cin>>n;
        int b[n];
        for(auto &i: b) cin>>i;
        vector<vi> groups;
        while(1){
            vi v;
            for(int i = 0; i<n; i++)
                if(!b[i]) v.push_back(i);
 
            if(!sz(v)) break;
            groups.push_back(v);
 
            for(int i = 0; i<n; i++){
                if(!b[i]) b[i] = INT_MAX;
                else{
                    for(auto x : v){
                        b[i] -= abs(x - i);
                    }
                }
            }
        }
        map<char, int> mp;
        for(auto &c : s) mp[c]++;
        auto cur = mp.rbegin();
        string t(n, '?');
        for(auto x : groups){
            while(cur -> second < sz(x)) cur++;
            for(auto y : x){
                t[y] = cur -> first;
            }
            cur++;
        }
        cout<<t<<endl;
    }
    return 0;
}