#include <bits/stdc++.h>
using namespace std;

#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
#define pow POW

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;

void fast() {
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
}

bool compare(int &a, int &b) {
	return a > b;
}

ll numOfDigits(ll n) {
	if (!n)
		return 1;
	return (ll) (log10(n)) + 1;
}

ull POW(ll a, ll b);

/*

 */

ll BN();
int main() {
	JULEE_DO_THE_THING;
	//freopen("test cases\\Strings of Impurity.txt", "r", stdin) ;
	str s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    map<char, bool> vis;
    for(int i=0; i<n; i++)vis[s[i]] = 1;
    for(int i=0; i<m; i++){
        if(vis.find(t[i])==vis.end())
            return cout<<-1, 0;
    }
    map<char, set<int>> mp;
    t = " " + t; m++;
    for(int i=0; i<n; i++) mp[s[i]].insert(i);
    int index[m+1]={IMAX}; index[m] = IMAX;
    for(int i=1; i<m; i++){
        int up;
        auto it = mp[t[i]].upper_bound(index[i-1]);
        if(it==mp[t[i]].end()) up = *mp[t[i]].begin();
        else up = *it;
        index[i] = up;
    }
    ull subSequnce = 0;
    for(int i=1; i<m; i++){
       if(index[i]<=index[i-1])subSequnce++;
    }
    //cout<<subSequnce<<endl;
    int j = m-1, x;
    while(j>=1 && index[j]<index[j+1]) j--;
    str lastSequence = t.substr(j+1);
    t = t.substr(1); m--;
    ull lastSubLenght  = 0 ;
    for( j=0, x = 0; j<n && x<lastSequence.size(); j++){
       if(s[j]==lastSequence[x])x++;
    }
    lastSubLenght = j;
    //cout<<lastSubLenght<<endl;
    cout<<(subSequnce-1)*s.size() + lastSubLenght;
	return 0;
}

ll BN() {
	ll low = 0;
	ll up = 0;
	ll ans = 0;
	while (low <= up) {
		ll mid = ((low + up) / 2);
		if (mid) {
			ans = mid;
			low = mid + 1;
		} else
			up = mid - 1;
	}
	return ans;
}

ull POW(ll a, ll b) {
	ull res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
