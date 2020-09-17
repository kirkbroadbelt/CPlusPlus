//Kirk Broadbelt
// 9.7.15
// 6th

#include<iomanip>
#include<iostream>
using namespace std;

void input(int &a1, int &a2,int &a3, int &term){

    cout<<"Please enter seed 1\n";
    cin>>a1;
    cout<<"Please enter seed 2\n";
    cin>>a2;
    cout<<"What term do you wish to request? \n";
    cin>>term;
}

void output (int term,int &o1,int &o2,int &o3){
    cout<<o1<<", ";
    cout<<o2;
for (int c=1; c<=term-2;c++){

    o3=o1+o2;
    cout<<", "<<o3;
    o1=o2;
    o2=o3;
    }
    cout<<".";
}

int main (){
    int t1,t2,t3,term,urmumlad;
    input(t1,t2,t3,urmumlad);
    output(urmumlad,t1,t2,t3);

}
