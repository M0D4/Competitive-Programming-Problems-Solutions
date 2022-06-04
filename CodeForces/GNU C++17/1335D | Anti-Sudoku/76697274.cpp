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
  char change(char a){
    return(a=='1'?'2':'1');
}
int main()
{
    START
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        for(int i =0; i<9; i++){
            for(int j = 0; j<9; j++){
                char a; cin>>a;
                if((!i && !j)||
                   (i==1 && j==4)||
                   (i==2 && j==8)||
                   (i==3 && j==1)||
                   (i==5 && j==5)||
                   (i==4 && j==7)||
                   (i==6 && j==2)||
                   (i==7 && j==3)||
                   (i==8 && j==6))a = change(a);
                cout<<a;
            }
            cout<<endl;
        }
    }
 return 0;
}