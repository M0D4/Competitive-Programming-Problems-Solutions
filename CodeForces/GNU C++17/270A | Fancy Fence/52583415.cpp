#include <iostream>
 using namespace std;
 int main()
{
    int n;
    cin>>n;
    string ans[n];
    for(int i=0; i<n; i++){
        int angle;
        cin>>angle;
        float element =360.0/(180-angle); //to find the number of sides
        if((int)element == element)
            ans[i]="YES";
        else
            ans[i]="NO";
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<"\n";
    }
     return 0;
}