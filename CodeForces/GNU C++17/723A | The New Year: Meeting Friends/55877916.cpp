#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 int main(){
    int x[3];
    cin>>x[0]>>x[1]>>x[2];
    sort(x, x+3);
    int sum1 = x[1] - x[0];
    int sum2 = x[2] - x[1];
    cout<<sum1+sum2<<"\n";
    return 0;
}
 