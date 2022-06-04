#include <iostream>
//#include <bits/stdc++.h>
bool check (char c1, char c2, char c3, char c4);
using namespace std;
 int main(){
    char arr[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            cin>>arr[i][j];
     for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(check(arr[i][j],arr[i][j+1],arr[i+1][j],arr[i+1][j+1])){
                cout<<"YES\n";
                return 0;
            }
    cout<<"NO\n";
    return 0;
}
 bool check (char c1, char c2, char c3, char c4){
return  (c1==c2 && c2==c3)||
        (c1==c2 && c2==c4)||
        (c2==c3 && c3==c4)||
        (c1==c3 && c3==c4);
}