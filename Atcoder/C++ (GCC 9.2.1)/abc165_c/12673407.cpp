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
#define MOD 1000000007
#define EPS 1e-7
#define lp(i, o, m)     for(int i = o; i<=m ; i++)
#define lol(x)        if(n==x){ cal(); continue;}

typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;

struct qq{
    int a, b, c, d;

    bool operator < (const qq &x) const
    {
        return d > x.d;
    }
}arr[50];

 int n, m, q;

ll mx = 0;
int v[11];
void cal(){
    ll sum  = 0;
//    for(int i  = 1; i<=n; i++)
//        cout<<v[i]<<" "; cout<<endl;
    for(int i = 0; i<q; i++){
        if(v[arr[i].b] - v[arr[i].a] == arr[i].c) sum += arr[i].d;
    }
    mx = max(mx, sum);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    cin>>n>>m>>q;

    for(int i =0; i<q; i++)cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;

        lp(i, 1, m){
            v[1] = i;
           lp(i2, i, m){
                v[2] = i2;
                lol(2);
                lp(i3, i2, m){
                    v[3] = i3;
                    lol(3);
                    lp(i4, i3, m){
                        v[4] = i4;
                        lol(4);
                        lp(i5, i4, m){
                            v[5] = i5;
                            lol(5);
                            lp(i6, i5, m){
                                v[6] = i6;
                                lol(6);
                                lp(i7, i6, m){
                                    v[7]  = i7;
                                    lol(7);
                                    lp(i8, i7, m){
                                        v[8] = i8;
                                        lol(8);
                                        lp(i9, i8, m){
                                            v[9] = i9;
                                            lol(9);
                                            lp(i10, i9, m){
                                                v[10] = i10;
                                                cal();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }
    cout<<mx;
	return 0;
}
