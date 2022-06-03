#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define var auto
#define MOD 1000000007


typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;

int X, X1, Y, Y1;
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
     int w, h, n; cin>>w>>h>>n;
    X1 = w, Y1 = h;
    for(int i =0; i<n; i++){
        int x, y, a; cin>>x>>y>>a;
        if(x<X) x = X;
        else if(x>X1) x = X1;
        if(y<Y) y = Y;
        else if(y>Y1) y = Y1;
        switch(a){
            case 1:
                    X = x;
                    break;
            case 2:
                    X1 = x;
                    break;
            case 3:
                    Y = y;
                    break;
            case 4:
                    Y1 = y;
                    break;
        }
    }
    cout<<abs(X-X1)*abs(Y-Y1);
	return 0;
}
