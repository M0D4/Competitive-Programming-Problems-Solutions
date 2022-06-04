#include <iostream>
#include <algorithm>
 using namespace std;
 int main()
{
    int counter=0;
    int n;
   cin>>n;
   int h[n]; int g[n];
   for(int i=0; i<n; i++){
    cin>>h[i]>>g[i];
   }
   for(int i=0; i<n; i++){
    int c = count(g,g+n, h[i]);
    counter +=c;
   }
   cout<<counter<<"\n";
    return 0;
}