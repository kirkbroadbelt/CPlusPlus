//Kirk Broadbelt
//Period 7th
// 9/24/15
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
int number, fact=1;

cout<<"Please enter a integer: "<<endl;
cin>>number;

for(int a=1; a<=number; a=a+1){
    fact=fact*a;
            }
cout<<"The Factorial is: "<<fact<<endl;
return 0;
}
