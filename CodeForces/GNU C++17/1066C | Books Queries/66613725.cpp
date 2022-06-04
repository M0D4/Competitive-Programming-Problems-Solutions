#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE fast()
#define to_str to_string
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
  int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Books Queries.txt", "r", stdin);
    int q; cin >> q;
    map<int, int> ml, mr;
    map<int, char> pos;
    int left = -1, right = -1;
    while(q--){
     char c; int id; cin>>c>>id;
     if(left==-1){
         left = 0, right = 0;
         if(c=='L'){ ml[id]= 0, pos[id]='L';}
         else {mr[id] = 0; pos[id] = 'R';}
     }else{
        if(c=='L'){ml[id]= ++left, pos[id]='L';}
      else if(c=='R'){mr[id]=++right;pos[id] = 'R';}
       else{
              if(pos[id]=='L')
               { cout<<min(left-ml[id], ml[id]+right)<<endl;}
             else
              cout<<min(right-mr[id],mr[id] + left)<<endl; 
           }
      }
    }
        return 0;
}
  