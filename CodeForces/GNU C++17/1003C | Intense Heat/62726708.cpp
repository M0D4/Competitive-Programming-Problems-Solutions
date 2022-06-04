#include <bits/stdc++.h>
using namespace std;
 #define fori( t,a)      for(long long i = t; i<a; i++)
#define forj( y,b)      for(long long j=y; j<b; j++)
#define fork( u,c)      for(long long k=u; k<c; k++)
#define endl "\n";
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
 ll pow (ll a, ll b);
const dd PI = 3.141592;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    ll pre[n+1]={0};
    fori(1,n+1){
        int tmp;
        cin>>tmp;
        pre[i] = tmp + pre[i-1];
    }
    ld mx = 0;
    while(k<=n){
        for(int i=n; i>=k; i--){
                int j = i-k+1;
            ld sum = pre[i] - pre[j-1];
            sum /=(i-j+1.0);
            if(sum>mx)
                mx = sum;
        }
        k++;
    }
    cout<<fixed<<setprecision(15)<<mx;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}