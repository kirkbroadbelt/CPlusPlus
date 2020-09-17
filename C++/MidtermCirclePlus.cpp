//Kirk Broadbelt
//Period 7
// 1/13/16
#include<iostream>
#include<iomanip>
using namespace std;

void input(int as,int bs){
cout<<"Enter two integers";
cin>>as;
cin>>bs;
}
int main(){
int a,b,out,out2;
double outfinal;
cout<<"Enter two integers\n";
cin>>a;
cin>>b;
out=(2*a)+(3*b)-(a*b);
out2=a%b;
outfinal=out/out2;
cout<<outfinal;
}
