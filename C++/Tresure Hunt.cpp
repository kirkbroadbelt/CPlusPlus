// Kirk Broadbelt
// 11/23/2015
// Period 7
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
void input (char test3[][5],char test2[][5],int a){
//TEST2 IS SHOWN BOARD, TEST3 IS SOLUTION
int x,ri,ci,counter;
x=0;
counter=1;


while(x<10){
cout<<"Enter y-coordinate ";
cin>>ci;
cout<<"\nEnter x-coordinate \n\n\n\n\n\n\n";
cin>>ri;
ri--;
ci--;
    if (test3[ri][ci]==' '){
        test2[ri][ci]=' ';
        a++;
    }
    else if (test3[ri][ci]=='$'){
        test2[ri][ci]='$';
        x++;
        a++;
    }
    counter=1;
    cout<<"  1 2 3 4 5\n\n";
for(int i=0;i<5;i++){
        cout<<counter<<" ";
        counter++;
    for(int h=0;h<5;h++){
       cout<<test2[i][h]<<" ";
    }
    cout<<endl<<endl;
    }
    counter=1;
}
}
void starterboard (char sboard[][5],char pb[][5]){
int counter;
counter=1;
cout<<"  1 2 3 4 5\n\n";
for(int i=0;i<5;i++){
    cout<<counter<<" ";
counter++;
    for(int h=0;h<5;h++){
        sboard[i][h]='#';
        pb[i][h]=' ';
        cout<<sboard[i][h]<<" ";
    }
cout<<endl<<endl;
}
}
int main(){
    int thing,counter,b;
    thing=0;
    counter=1;
    b=0;
    char ssboard[5][5];
    char proboard[5][5];
    starterboard(ssboard,proboard);
    cout<<endl<<endl<<endl;
    srand(time (NULL));
    while(thing<10){
        int random = rand()%5;
        int random2= rand()%5;
        if(proboard[random][random2]!='$'){
            proboard[random][random2]='$';
             thing++;
        }
    }
    input(proboard,ssboard,b);
cout<<"\n\n\n\n\n\n\n\n\n\n You guessed "<<b<<" times";
return 0;
}
