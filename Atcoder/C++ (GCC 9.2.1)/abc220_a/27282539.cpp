//testing


#include <iostream>

using namespace std;
int main(){
int a,b,c;

cin>>a>>b>>c;
int d=a;
while(d>=a&&d<b){
	if((d%c)==0)
	break;
	d++;
}
if((d%c)!=0)
	cout<<"-1";
	else 
	cout<<d;}