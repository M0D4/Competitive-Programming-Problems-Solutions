//testing
 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 int main()
{
 cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
        ll n, k;
 cin >> n >> k;
        ll sq = sqrt(n);
        vector<ll> v;
 for (ll i = 1; i <= sq; i++)
 {
  if (n % i == 0){
   v.push_back(i);
  if (n / i != i)
   v.push_back(n / i);
                }
 }
  if (k > v.size())
  return cout << -1, 0;
 else{
                sort(v.begin(), v.end());
  cout << v[k - 1];
        }
}