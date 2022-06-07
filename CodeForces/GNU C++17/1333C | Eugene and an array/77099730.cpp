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
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
 
 
int main()
{
    START
    //freopen("test cases\\out.txt", "w", stdout) ;
    int n; cin>>n;
    ll pre[n+3] = {0};
    for(int i = 1; i<=n; i++){
        int a; cin>>a;
        pre[i] = pre[i-1] + a;
    }
    set<ll> s = {0}; //contains 0
    ll p1 = 0, p2 = 0, cnt = 0;
    /*
        a sub-array has 0 sum if is has duplicates in its prefix
        ex:
        elements:   1 2 -3
        prefix  : 0 1 3  0
        the 0 is already at index 0
        so the sum from index 1 to index 3 is 0
    */
    while(p1<n){
        while(p2<n && s.find(pre[p2+1])==s.end()){
            p2++;
            s.insert(pre[p2]);
        }
        cnt += p2 - p1;
        s.erase(pre[p1]);
        p1++;
    }
    cout<<cnt;
 return 0;
}
 