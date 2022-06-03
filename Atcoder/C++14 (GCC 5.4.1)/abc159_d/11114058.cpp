#include <bits/stdc++.h>
using namespace std;

#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
#define pow POW
#define INF 1e9

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
	ios_base::sync_with_stdio(0);
}

bool compare(pii &a, pii &b) {
	return a.F > b.F;
}

ll numOfDigits(ll n) {
	if (!n) return 1;
	return (ll) (log10(n)) + 1;
}

ll POW(ll a, ll b);

/*

*/

ll BN();

int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int n; cin>>n;
    int arr[n];
    map<int, ll> mp;
    map<int, int> freq;
    for(int i=0; i<n; i++) cin>>arr[i], freq[arr[i]]++;
    ll sum = 0;
    for(auto &it: freq){
        mp[it.F] = (ll)it.S * (it.S-1)/2;
        sum += mp[it.F];
    }
    ll tmpSum = sum;
    for(int i=0; i<n; i++){
        sum = tmpSum;
        freq[arr[i]]--;
        sum -= mp[arr[i]];
        sum += (ll)freq[arr[i]] * (freq[arr[i]]-1)/2;
        cout<<sum<<endl;
        freq[arr[i]]++;
    }
    return 0;
}

ll BN() {
	int low = 1, up = 0;
	int ans = -1;
	while (low <= up) {
		ll mid = (((ll)low + up) / 2);
		if (mid){
			ans = mid;
			low = mid + 1;
		} else
			up = mid - 1;
	}
	return ans;
}

ll POW(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
