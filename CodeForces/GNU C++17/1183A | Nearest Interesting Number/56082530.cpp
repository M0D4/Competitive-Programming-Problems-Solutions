#include <bits/stdc++.h>
int findSum(int a);
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=n; ; i++){
        int t= findSum(i);
       if(t%4==0) {
            cout<<i;
            return 0;
       }
    }
    return 0;
}
 int findSum(int a)
{
    int sum =0;
    while(a){
      sum +=a%10;
      a/=10;
    }
    return sum;
}