//Kirk broadbelt
//period 7
// 1/5/2016
#include<iostream>
#include<string>
using namespace std;

int main(){
string x,y;
int length;
int f;
cout<<"Enter the string\n";
getline(cin,x);
length=x.length()-1;
f=length;
y=x;
for(length;f>=0;f--){
    y[length-f]=x[f];
    }
    if(x==y){
        cout<<x<<" Is a palindrome";
    }
    else{
        cout<<"It is not a palindrome";
    }

   }
