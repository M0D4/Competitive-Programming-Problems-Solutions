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

int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
     string s; cin>>s;
     int n = s.size();
     char c = s.back();
     int c1 = 0, c2 = 0;
     for(int i = n-1; i+1>=0; i--)
        if(s[i]!=c)c1++, c = s[i];

    c = s[0];
    for(int i = 0; i<n; i++)
        if(s[i]!=c)c2++, c = s[i];
    cout<<min(c1, c2);
	return 0;
}
