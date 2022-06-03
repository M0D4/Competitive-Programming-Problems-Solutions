#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define Unique(x)       (x).erase(unique(all(x)), (x).end())
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int f[2000] = {};
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        f[a]++;
    }

    int mx = 0, mxN = 0;
    for(int i = 2; i <= 1000; i++){
        int c = 0, x = i;
        while(x <= 1000){
            c += f[x];
            x += i;
        }
        if(mx < c){
            mx = c;
            mxN = i;
        }
    }
    cout << mxN;
    return 0;
}
