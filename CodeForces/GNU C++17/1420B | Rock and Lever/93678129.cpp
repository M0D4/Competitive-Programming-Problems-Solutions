#include "bits/stdc++.h"
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        multiset<int> s;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            s.insert(a);
        }
        ll c = 0;
        for(int bit = 31; ~bit && s.size(); bit--){
            ll cur = 0;
            multiset<int> temp = s;
            for(auto &i: s){
                if((i & (1 << bit))){
                    cur++;
                    temp.erase(temp.find(i));
                }
            }
            c += cur * (cur - 1) / 2;
            s = temp;
        }
        cout << c << endl;
    }
    return 0;
}