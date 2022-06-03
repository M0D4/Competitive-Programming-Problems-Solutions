//testing

/*                                بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحِيمِ

                                       ( إِنِ الْحُكْمُ إِلَّا لِلَّهِ )

*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const long double pi=acos(-1);
#define x  first
#define y  second
#define read(n,a) for(int i=0;i<n;i++)cin>>a[i];
#define rep(i,z,n)for(ll i=z;i<n;i++)
#define all(v)    v.begin(),v.end()

ll a[200002]={};
ll b[200002]={};

string s="",ss="";

ll n,m,k,w;
ll ans ;
ll mod = 1e9 +7;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("lazy.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m;
        read(n,a);
        rep(i,0,n)
        {
            int j=0;
            while(a[i])
            {
                b[j]+=a[i]%2;
                a[i]/=2;
                j++;
            }
        }
        w=0;
        for(ll i = 60;i>=0;i--)
        {
            ll te= max(b[i],n-b[i]);
            if(te == b[i] || w+powl(2,i)>m)ans+=b[i]*powl(2,i);
            else ans+=(n-b[i])*powl(2,i) , w+=powl(2,i);
        }
        cout<<ans;
    }
    return 0;
}
