#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define pb       push_back
#define sz(x)    (int) (x.size())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = sz(s);
        ll pfx[n + 3] = {};
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){
            pfx[i] = pfx[i - 1] + (s[i - 1] == '+' ? 1 : -1);
            if(!mp[pfx[i]]) mp[pfx[i]] = i;
        }
        ll l = 0, r = n + 5, ans = n + 5;
        while(l <= r){ //find the smallest number which breaks the loop
            int mid = (l + r) >> 1, x = mid;
            bool can = 1;
            for(int i = 0; i < n; i++){
                if(s[i] == '+') x++;
                else x--;
                if(x < 0) can = 0;
            }
            if(!can) l = mid + 1;
            else ans = mid, r = mid - 1;
        }
        ll sum = n; //this number (ans) can reach all string
        for(int i = 0; i < ans; i++){
            sum += mp[-(i + 1)];
        }
        cout << sum << endl;
    }
    return 0;
}