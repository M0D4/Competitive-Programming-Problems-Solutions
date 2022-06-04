#include <iostream>
using namespace std;
 int main()
{
        int n ;
        cin>>n;
        int police=0, crimes=0;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            if(num==-1 && police==0)
                crimes++;
            else if(num==-1 && police!=0)
                    police--;
            else police+=num;
        }
        cout<<crimes<<endl;
    return 0;
}