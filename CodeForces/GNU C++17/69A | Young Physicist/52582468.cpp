#include <iostream>
 using namespace std;
 int main()
{
    int n;
    cin>>n;
    int arr[n][3];
    int sum [3] ={0,0,0};
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
            sum[j] += arr[i][j];
        }
    }
    //cout<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<"\n";
    if(!sum[0] && !sum[1] && !sum[2])
        cout<<"YES\n";
    else
        cout<<"NO\n";
     return 0;
}