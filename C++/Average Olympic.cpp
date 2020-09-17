//Kirk Broadbelt
//4/25/16
//Period 7
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

const int arraysize=10;

void bubble(double a[]){
for(int x=0;x<arraysize;x++){
for(int i=0;i<arraysize;i++){
for(int z=i+1;z<arraysize;z++){
    double temp;
    if(a[i]>a[z]){
        temp=a[i];
        a[i]=a[z];
        a[z]=temp;
}
}
}
}
cout<<"The Olympic Average is: "<<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])/8.0<<endl;
cout<<"The lowest score was: "<<a[0]<<endl;
cout<<"The highest score was: "<<a[9]<<endl;
}

int main(){
    double inputs[10];
    ifstream myfile("S:/Public/Davis/test.txt");
    if (myfile.is_open() && myfile.good()) {
   for(int k=0;k<10;k++){
    myfile>>inputs[k];
}
    }
    myfile.close();
    cout<<setprecision(2);
    cout.setf(ios::fixed|ios::showpoint);
    bubble(inputs);
    return 0;
    }
