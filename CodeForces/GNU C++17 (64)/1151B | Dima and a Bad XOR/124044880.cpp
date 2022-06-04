//testing
 #include <bits/stdc++.h>
 using namespace std;
 #define F first
#define S second
#define modulo ll (1e9 + 7)
 typedef long long ll;
typedef pair<int,int> pii;
 void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
 const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;
  int main(){
    init();
     int n, m;   cin >> n >> m;
     int a[n][m];
     int xoor = 0;
    vector<int> ans(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
            if(j == 0)
                xoor ^= a[i][j], ans[i] = j;
        }
    }
      if(xoor == 0) {
        for (int i = 0;!xoor && i < n; i++) {
            for (int j = 0;!xoor && j < m; j++) {
                if((xoor ^ a[i][0] ^ a[i][j]) > 0){
                    ans[i] = j;
                    xoor ^= a[i][0] ^ a[i][j];
                }
            }
        }
    }
     if(xoor == 0)
        cout << "NIE";
    else{
        cout << "TAK\n";
        for(auto &v : ans)
            cout << v + 1 << " ";
    }
}