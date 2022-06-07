#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x)) //be careful of value and TLE
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int f[1001] = {0};
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(!f[a])f[a]++;
        }
        for(int i = 0; i < m; i++){
            int a; cin >> a;
            if(f[a] == 1)f[a]++;
        }
        for(int i = 0; i <= 1000; i++){
           if(f[i] >= 2){
                cout << "YES\n";
                cout << "1 " << i << endl;
                goto EmergencyGate;
           }
        }
        cout << "NO\n";
        EmergencyGate:;
    }
    return 0;
}