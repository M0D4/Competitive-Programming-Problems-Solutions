#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i = tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define endl "\n";
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
void fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll pow (ll a, ll b);
int freq[1001];
int main()
{
    fast();
    int n; cin>>n;
    int arr[n];
    fori(0,n){
        cin>>arr[i];
    }
    vector<int> v;
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(freq[arr[i]]==0){
            cnt++;
            freq[arr[i]]++;
            v.push_back(arr[i]);
        }
    }
    cout<<cnt<<"\n";
    vector <int> ::reverse_iterator it;
    for(it= v.rbegin(); it!=v.rend(); it++){
        cout<<*it<<" ";
    }
    return 0;
}
 ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}