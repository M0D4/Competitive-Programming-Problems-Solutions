#include <iostream>
using namespace std;
 long double pow (long double a,long double b);
 int main()
{
    int64_t n, m=0;
    cin>>n;
    int counter =0;
    while(n){
           int64_t temp = n%10;
           if(temp>=5){
                if(n/10==0 && temp==9){}
               else temp = 9 - temp;
           }
           int64_t t = (int64_t) ((int64_t)temp*pow(10,counter));
           m += t;
           counter++;
           n /=10;
       }
    cout<<m<<"\n";
    return 0;
    }
long double pow (long double a,long double b){
    long double pow =1;
for(int i=0; i<b; i++)
    pow *=a;
return pow;
}
 