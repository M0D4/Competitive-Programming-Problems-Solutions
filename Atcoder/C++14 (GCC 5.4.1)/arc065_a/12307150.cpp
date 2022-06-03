#include <bits/stdc++.h>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define all(v)   v.begin(), v.end()
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
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


const int N = 1e5;
string arr[4] = {"dream", "dreamer", "erase" ,"eraser"};
string s;
int n;

int main()
{
    START
    //freopen("test cases\\out.txt", "r", stdin) ;
    cin>>s;
    n = s.size();
    reverse(all(s));
    for(int i =0; i<n; i++){
        if(i+4<n && s.substr(i, 5)=="maerd") i+=4;
        else if(i+6<n && s.substr(i, 7)=="remaerd") i+=6;
        else if(i+4<n && s.substr(i, 5)=="esare") i+=4;
        else if(i+5<n && s.substr(i, 6)=="resare") i+=5;
        else return cout<<"NO", 0;
    }
    cout<<"YES";
	return 0;
}
