#include <bits/stdc++.h>
 using namespace std;
 int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
     int n, x, y; cin>>n>>x>>y;
    int per = y*n/100, r = (y*n)%100;
    cout<<max(0, per - x + (r!=0));
    return 0;
}