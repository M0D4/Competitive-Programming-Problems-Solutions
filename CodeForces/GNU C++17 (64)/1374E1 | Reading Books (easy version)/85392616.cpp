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
 
int n, k;
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    const int N = 1e5;
    int n, k; cin >> n >> k;
    vi alice, bob, both;
    for(int i = 0; i < n; i++){
        int t, a, b; cin >> t >> a >> b;
        if(a && b) both.push_back(t);
        else if(a) alice.push_back(t);
        else if(b) bob.push_back(t);
    }
    sort(all(alice));
    sort(all(bob));
    sort(all(both));
 
    int a = 0, b = 0, x, y, z;
    x = y = z = 0;
    ll sum = 0;
    while(a < k || b < k){
        bool flag = 0;
        if(z < sz(both) && both[z] <= (x < sz(alice) ? alice[x] : N) + (y < sz(bob) ? bob[y] : N)){
            sum += both[z++];
            a++, b++;
            flag = 1;
        }else{
            if(x < sz(alice) && a < k) sum += alice[x++], a++, flag = 1;
            if(y < sz(bob) && b < k) sum += bob[y++], b++, flag = 1;
        }
        if(!flag) break;
    }
    if(a < k || b < k) sum = -1;
    cout << sum;
    return 0;
}