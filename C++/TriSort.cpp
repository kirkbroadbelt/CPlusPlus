//Kirk Broadbelt
//Period 7
// 9/10/15
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int a, b;
double ari, geo, har;

void input(int &a, int &b){
cout<<"Please input integer a."<<endl;
cin>>a;
cout<<"Please input integer b."<<endl;
cin>>b;
}
double Arith (int a, int b){
double ari=double(a+b)/2;
return ari;
}
double Geom(int a, int b){
double geo= sqrt(a*b);
return geo;
}
double Harm(int a, int b){
    double har= 2/(1/(double(a))+(1/double(b)));
    return har;
}
void output(double ari, double har, double geo){
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision (3);
cout<<"The Arithmetic solution is: "<<ari<<endl;
cout<<"The Geometric solution is: "<<geo<<endl;
cout<<"The Harmonic solution is: "<<har<<endl;
}
int main(){
input(a,b);
ari=Arith(a,b);
geo=Geom(a,b);
har=Harm(a,b);
output(ari,har,geo);
return 0;
}
