#include <iostream>
using namespace std;
 int main()
{
        int n ;
        cin>>n;
        int cards [n];
        for (int i = 0; i < n; i++) {
            cin>>cards[i];
        }
        int leftMost = 0;
        int rightMost = n-1;
        int Sereja=0, Dema = 0;
        for (int i = 0; i < n; i++) {
            if(i%2==0){
                if(cards[leftMost]>cards[rightMost]){
                    Sereja +=cards[leftMost];
                    leftMost++;
                }else{
                    Sereja +=cards[rightMost];
                    rightMost--;
                }
            }else{
                if(cards[leftMost]>cards[rightMost]){
                    Dema +=cards[leftMost];
                    leftMost++;
                }else{
                    Dema +=cards[rightMost];
                    rightMost--;
                }
            }
        }
           cout<<Sereja<<" "<<Dema<<endl;
    return 0;
}