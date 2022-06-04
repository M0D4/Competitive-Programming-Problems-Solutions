#include <iostream>
 using namespace std;
 int main(){
    int n ,ns;
 cin >> n;
 char arr[n][n];
 char c1, c2;
 for (int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
 c1 = arr[0][0];
 c2 = arr[0][1];
 if(c1==c2){
        cout << "NO\n";
            return 0;
 }
 for(int i=0; i<n; i++){
        if(arr[i][i]!=c1){
            cout << "NO\n";
            return 0;
        }
        if(arr[i][n-i-1]!=c1){
            cout << "NO\n";
            return 0;
        }
 }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j && j!=n-i-1){
                if(arr[i][j]!= c2){
                     cout << "NO\n";
                    return 0;
                }
            }
 cout << "YES\n";
 return 0;
}