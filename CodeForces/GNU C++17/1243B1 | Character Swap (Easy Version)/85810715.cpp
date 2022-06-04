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
     int q; cin >> q;
    while(q--){
        int n;
        string s, t; cin >> n >> s >> t;
        vector<char> ss, tt;
        for(int i = 0; i < n; i++)
            if(s[i] != t[i]) ss.push_back(s[i]), tt.push_back(t[i]);
         if(ss.size() != 2) cout << "NO\n";
        else{
            cout << (ss[0] == ss[1] && tt[0] == tt[1] ? "YES" : "NO") << endl;
        }
    }
    return 0;
}