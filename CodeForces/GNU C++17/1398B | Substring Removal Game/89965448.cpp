#include "bits/stdc++.h"
 
using namespace std;
 
#define pb              push_back
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t; cin>>t;
    while(t--){
        string s; cin >> s;
        vector<int> v;
        int c = 0, n = s.size();
        for(int i = 0; i < n + 1; i++){
            if(i == n){
                if(c) v.push_back(c);
                break;
            }
            if(s[i] == '0'){
                if(c) v.push_back(c);
                c = 0;
            }
            else c++;
        }
        sort(all(v));
        ll score = 0, alice = 1;
        for(int i = v.size() - 1; ~i; i--){
            if(alice) score += v[i];
            alice ^= 1;
        }
        cout << score << endl;
    }
    return 0;
}