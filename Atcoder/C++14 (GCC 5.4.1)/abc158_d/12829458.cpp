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
#define sz(x)          (int) x.size()
#define var auto
#define MOD 1000000007


typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;

int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;

    string s; cin>>s;
    int n = s.size(), m; cin>>m;
    deque<char> v;
    for(char &i: s)v.pb(i);
    int rev = 0;
    while(m--){
        int type; cin>>type;
        if(type==1) rev++;
        else {
            int d; char val; cin>>d>>val;
            if(isOdd(rev)) d = (d==1?2:1);
            if(d==1) v.push_front(val);
            else v.pb(val);
        }
    }
    if(isOdd(rev)) reverse(all(v));
    for(var &i: v)cout<<i;
	return 0;
}
