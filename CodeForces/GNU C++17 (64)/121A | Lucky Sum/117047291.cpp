//testing
 
 
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl "\n"
//fill_n(arr , n , 0);
// pi = 3.14159265359
#define lop(n) for(int i = 0 ;i < n ; i++)
#define len length
#define mod 1000000000
using namespace std;
 
set < ll >  st;
ll n = 1e9 + 9;
void fun(string s)
{
    // base
    if(stoll(s) > n) return;
 
    // trans
    fun(s + '4'), st.insert(stoll(s));
    fun(s + '7'), st.insert(stoll(s));
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll l, r; cin >> l >> r;
    fun("4");
    fun("7");
 
    st.insert(4444444444);
    st.insert(4444477777);
    
    ll ans = 0;
    ll idx = l;
    for(auto it : st)
    {
        ll k = it;
        if(k >= idx)
        {
            if(k < r) ans += k * (k - idx + 1);
            else{
                ans += k * (r - idx + 1);
                break;
            }
            idx = k + 1;
        }
    }
    cout << ans;
 
 
}