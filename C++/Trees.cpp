//Kirk Broadbelt
//Period 7th
// 10/13/15

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int seed,c,r, height;
    cout<<"Please input a seed fam. \n";
    cin>>seed;
    cout<<"Please enter a height please. By the way I love you Ms.Davis.\n";
    cin>>height;
    cout<<"\n";
    int a=height;
for(int r=1;r<=height;r++){
    while(a>0){
        cout<<" ";
        a--;
}
for(int c=1;c<=r;c++){
        cout<<seed<<" ";
        seed++;
        if(seed>=10){
            seed=0;
    }
     a=height-r;
}
    cout<<"\n";
}
return 0;
}
