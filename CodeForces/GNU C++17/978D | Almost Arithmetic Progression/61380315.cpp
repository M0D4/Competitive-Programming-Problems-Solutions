#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   (v.begin(), v.end())
#define endl "\n";
#define pb push_back
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
int BN(int freq[],dd arr[], int n, dd val);
int main()
{
    fast();
    int n; cin>>n;
    vector<int> arr;
    fori(0,n){
        int t; cin>>t;
        arr.pb(t);
    }
    if(n<=2) return cout<<0, 0;
    int mn = 100000, howMany = 9;
    fori(0,9){
            bool flag = 1;
        int cnt = 0;
        vector<int> v = arr;
        switch(i){
            case 0:
                    break;
            case 1:
                    v[0]++;
                    break;
            case 2:
                    v[0]--;
                    break;
            case 3:
                    v[1]--;
                    break;
            case 4:
                    v[0]++, v[1]--;
                    break;
            case 5:
                    v[0]--, v[1]--;
                    break;
            case 6:
                    v[1]++;
                    break;
            case 7:
                    v[0]--, v[1]++;
                    break;
            case 8:
                    v[0]++, v[1]++;
        }
        int sub = v[1] - v[0];
        fori(2,n){
            v[i] = v[i-1] + sub;
        }
        fori(0,n){
            if(arr[i]==v[i]+1 || arr[i]==v[i]-1) cnt++;
            else if(arr[i]!=v[i]) {
                howMany--;
                flag = 0; break;
            }
        }
        if(flag) mn =min(mn, cnt);
    }
    if(!howMany) cout<<-1;
    else cout<<mn;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
  int BN(int freq[],dd arr[], int n, dd val){
    int low  = 0;
    int up = n-1;
    int ans = -1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
         if(arr[mid]==val && !freq[mid]) return mid;
        if(arr[mid]<val){
            low = mid+1;
        }else up = mid -1;
    }
    return ans;
}