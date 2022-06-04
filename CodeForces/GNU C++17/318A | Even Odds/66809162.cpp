#include <bits/stdc++.h>
using namespace std;
 #define fori( t,a)      for(long long i = t; i<a; i++)
#define forj( y,b)      for(long long j=y; j<b; j++)
#define fork( u,c)      for(long long k=u; k<c; k++)
#define endl "\n";
typedef long long ll;
typedef long double ld;
typedef long double dd;
typedef string String;
typedef string str;
 ll pow (ll a, ll b);
const dd PI = 3.141592;
 int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll k,n, mid;
    cin>>n>>k;
    if(!(n%2)) 
        mid=n/2; //shrink to 2 equal boxes
    else{
        mid = (n/2)+1; //shrink to 2 boxes, the left has 1 more
    }
    if(k<=mid){ // if the position is odd (in the left side)
        cout<<(2*k)-1; 
    }else{ // if the position is even (in the right side)
        ll rightPos = k - mid; //counting from zero after half
        cout<<2*rightPos;
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}