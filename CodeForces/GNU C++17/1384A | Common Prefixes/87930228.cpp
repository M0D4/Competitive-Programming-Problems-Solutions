#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
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
        int a[n];
        for(auto &i: a) cin >> i;
        string s[n + 1] = {};
        s[0] = string(200, 'a');
        for(int i = 1; i <= n; i++){
            s[i] = string(200, 'a');
            int x = a[i - 1];
 
            for(int j = 0; j < x; j++)
                s[i][j] = s[i - 1][j];
 
            if(x < 200) s[i][x] = (s[i - 1][x] == 'b' ? 'a' : 'b');
        }
        for(int i = 0; i <= n; i++){
            cout << s[i] << endl;
        }
    }
    return 0;
}