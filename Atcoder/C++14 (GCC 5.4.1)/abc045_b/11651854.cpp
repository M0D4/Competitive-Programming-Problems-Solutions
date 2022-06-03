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


int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    string a, b, c; cin>>a>>b>>c;
    int x = a.size(), y = b.size(), z = c.size();
    bool b1 = 1, b2 = 0, b3 = 0;
    int i =0, j = 0, k = 0;
      for( ; ; ){
        if(b1){
            if(i==x) return cout<<"A", 0;
            if(a[i]=='b') b1 = 0, b2 = 1;
            else if(a[i]=='c') b1 = 0, b3 = 1;
            i++;
        }else if(b2){
            if(j==y) return cout<<"B", 0;
            if(b[j]=='a')b1 = 1, b2 = 0;
            else if(b[j]=='c') b2 = 0, b3 = 1;
            j++;
        }else{
            if(k==z) return cout<<"C", 0;
            if(c[k]=='a')b1 = 1, b3 = 0;
            else if(c[k]=='b')b2 = 1, b3 = 0;
            k++;
        }
    }

	return 0;

}
