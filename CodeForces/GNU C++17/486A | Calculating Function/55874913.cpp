#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
 int main(){
    long long n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<"\n";
    }else{
        cout<<"-"<<(n/2)+1<<"\n";
    }
    return 0;
}
 