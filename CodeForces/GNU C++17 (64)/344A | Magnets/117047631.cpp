 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n; cin>>n;
    int cnt =1;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<n; i++){
        if(arr[i][1]==arr[i-1][0])cnt++;
    }
    cout<<cnt;
    return 0;
}