#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;

int n;
string s, cur;
ll sum;
ll func(string x){
    //cout<<x<<endl;
    string tmp;
    stringstream ss(x);
    ll tot = 0;
    while(getline(ss, tmp, '+'))
        tot += stoll(tmp);
    //cout<<tot<<endl;
    return tot;
}
ll solve(int i, string cur, bool last){
    if(i==n) {
        //cout<<cur<<endl;
        return func(cur);
    }

    ll cnt = 0;
    cur.pb('+'), cur.pb(s[i]), cnt += solve(i+1, cur, 1);
    cur.pop_back(), cur.pop_back(), cur.push_back(s[i]);
    cnt += solve(i+1, cur, 0);
    return cnt;
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    cin>>s;
    n = s.size();
    cur.pb(s[0]);
    cout<<solve(1, cur, 0)<<endl;
	return 0;

}
