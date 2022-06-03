#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")


using namespace std;

#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;


bool hasSeven(int n, int base){
    while(n){
        int x = n % base;
        if(x == 7) return 0;
        n /= base;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n; cin >> n;
    int c = 0;
    for(int i = 1; i <= n; i++){
        c += (hasSeven(i, 10) && hasSeven(i, 8));
    }
    cout << c;
    return 0;
}
