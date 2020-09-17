//Kirk Broadbelt
// 9/3/2015
// Period 7
#include<iostream>
#include<iomanip>
using namespace std;
double bmi,htlb,htht,ht,lb,bmi2,htlb2,htht2,ht2,lb2;




void input(int &h, int &w){
cout<<"Please enter your weight in pounds: "<<endl;
cin>>w;
cout<<"Please enter your height in inches: "<<endl;
cin>>h;

}
void output(double &bmi){
cout<<"Your BMI is: "<<bmi<<"."<<endl;

}

double BMIcalc(int &w, int &h){

double bmi=w/double(h*h)*703;
return bmi;
}

int main() {
cout<<setprecision(1);
cout.setf(ios::fixed|ios::showpoint);
int h1;
int h2;
int w1;
int w2;
double bmi1;
double bmi2;

input( h1, w1);
bmi1=BMIcalc( h1, w1);

output(bmi1);


input(  h2, w2);
bmi2=BMIcalc(  h2, w2);

output(bmi2);


return 0;
}
