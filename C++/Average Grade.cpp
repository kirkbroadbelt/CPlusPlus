//Kirk Broadbelt
//4/25/16
//Period 7
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
double avg(double input[]){
double a=(input[0]+input[1]+input[2]+input[3]+input[4]+input[5]+input[6]+input[7]+input[8]+input[9])/10.0;
    return a;
    }
void output(double a){
    cout<<"Your average is "<<a<<". This is ";
    if(a>=90){
        cout<<"an A."<<endl;
    }
    else if(a>=80){
        cout<<"a B."<<endl;
    }
    else if(a>=70){
        cout<<"a C."<<endl;
    }
    else if(a>=60){
        cout<<"a D."<<endl;
    }
    else{
        cout<<"an F."<<endl;
    }
}
int main(){
    double inputs[10];
    ifstream myfile;
    ofstream output1;
    myfile.open("S:\\Public\\Davis\\test.txt");
    if (myfile.is_open() || myfile.good()) {
   for(int k=0;k<10;k++){
    myfile>>inputs[k];
}
    }
    myfile.close();
    cout<<setprecision(2);
    cout.setf(ios::fixed|ios::showpoint);
    double gradeA=avg(inputs);
    output(gradeA);
    output1.open("H:\\AverageOutput");
    output1<<gradeA;
    output1.close();
    return 0;
    }
