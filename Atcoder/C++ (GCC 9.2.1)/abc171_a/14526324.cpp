#include <bits/stdc++.h>

using namespace std;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);

    char a; cin >> a;
    if(islower(a))cout<<"a";
        else cout<<"A";
    return 0;
}
