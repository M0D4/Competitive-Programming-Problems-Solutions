#include <bits/stdc++.h>
 /**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
   string s;
int n;
 bool palindrome(string s){
    string t = s;
    reverse(all(t));
     return s == t;
}
 int main()
{
    START
//    freopen("test cases\\in.txt", "r", stdin) ;
//    freopen("test cases\\in.txt", "w", stdout);
//    cout<<"6 36\n";
//    int t = 36;
//    while(t--){
//        for(int i = 1; i<=6; i++){
//            for(int j = 1; j<=6; j++){
//                cout<<i<<" "<<j<<endl;
//            }
//        }
//    }
//    return 0;
    ll n, q; cin>>n>>q;
    int a[n][n];
    while(q--){
        ll x, y; cin>>x>>y;
        x--, y--;
        if(!isOdd(x)){
            if(!isOdd(y)){
                ll cellAtRow0 = (y)/2 + 1;
                ll sub = x/2;
                cout<<sub * n + cellAtRow0<<endl;
            }else{
                ll nsq = (n*n)/2 + (isOdd(n*n));//8
                ll cellAtRow0 = (y)/2 + 1 + nsq;
                ll sub = x/2;
                cout<<sub * n + cellAtRow0<<endl;
            }
        }else{//x is odd
            if(!isOdd(y)){
                ll nsq = (n*n)/2 + (isOdd(n*n));//18
                ll lastCol = n - 1 - (isOdd(n));//5
                ll lastOdd =  nsq + (n/2);// 18 + 3
                ll row1 = lastOdd + (1+y)/2 + 1; //21 + 1
                cout<<(x/2) * n + row1<<endl;
            }else{
                ll nsq = (n*n)/2 + (isOdd(n*n));//8
                ll lastCol = n - 1 - (!isOdd(n));//2
                ll lastEven = lastCol/2 + 1;//2
                ll row1 = lastEven + (1 + y)/2;//2 + 1
                ll sub = (x - 1)/2;
                cout<<sub * n + row1<<endl;
            }
        }
    }
  return 0;
}