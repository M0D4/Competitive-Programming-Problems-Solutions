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
 
    ll n, x; cin >> n >> x;
    ll sum = 0, c = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        sum += a;
    }
    sum = abs(sum);
    while(sum > x){
        c++;
        sum -= min(sum, x);
    }
    if(sum != 0) c++;
    cout << c;
    return 0;
}