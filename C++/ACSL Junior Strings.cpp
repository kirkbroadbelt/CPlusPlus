//Kirk broadbelt
//period 7
// 2/1/2016
#include<iostream>
#include<string>
using namespace std;

int main (){
int f,leng,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;
string input,input2,input3,input4,input5,input6;
cout<<"Enter input 1: ";
getline(cin,input);
cout<<"Enter input 2: ";
cin>>a1>>a2;
cout<<"Enter input 3: ";
cin>>b1>>b2;
cout<<"Enter input 4: ";
cin>>c1>>c2;
cout<<"Enter input 5: ";
cin>>d1>>d2;
cout<<"Enter input 6: ";
cin>>e1>>e2;
leng=input.length();
f=leng;
input2=input;
input3=input;
input4=input;
input5=input;
input6=input;
if (a1>=0&&a2>0){
    input2.erase(a1,a2);
}
if (b1>=0&&b2>0){
    input3.erase(b1,b2);
}
if (c1>=0&&c2>0){
    input4.erase(c1,c2);
}
if (d1>=0&&d2>0){
    input5.erase(d1,d2);
}
if (e1>=0&&e2>0){
    input6.erase(e1,e2);
}
cout<<input2<<endl;
cout<<input3<<endl;
cout<<input4<<endl;
cout<<input5<<endl;
cout<<input6<<endl;
}
