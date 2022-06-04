#include "bits/stdc++.h"
 using namespace std;
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
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n];
        for(auto &i: a) cin >> i;
        vector<int> pos, neg;
        for(int i = 0; i < n; i++){
            if(!a[i]) continue;
            if(a[i] > 0) pos.push_back(a[i]);
            else{
                while(a[i] < 0 && pos.size()){
                    a[i] += pos.back();
                    pos.pop_back();
                }
                if(a[i] > 0) pos.push_back(a[i]);
                else if(a[i] < 0) neg.push_back(a[i]);
            }
        }
        ll cost = 0;
        for(auto &i: neg) cost += abs(i);
        cout << cost << endl;
    }
    return 0;
}