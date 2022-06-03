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

    int l, r, d; cin >> l >> r >> d;
    int c = 0;
    for(int i = l; i <=r ; i++){
        if(i%d==0) c++;
    }
    cout << c;
    return 0;
}
