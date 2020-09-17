//Kirk Broadelt
//Period 7
//1/13/16
#include<iostream>
#include<string>
using namespace std;

int main(){
int length,fors,a,b,c,d,e,f,g,h,i,j,cot;
string parag;
a=0;
b=0;
c=0;
d=0;
e=0;
f=0;
g=0;
h=0;
i=0;
j=0;
cot=0;
cout<<"Enter a sentence or a paragraph\n";
getline(cin,parag);
cout<<endl;
length=parag.length();
fors=length;
for(cot;cot<=fors;cot++){
if (parag[cot]=='A'){
    a++;
}
else if(parag[cot]=='a'){
    b++;
}
else if (parag[cot]=='E'){
    c++;
    }
else if (parag[cot]=='e'){
    d++;
    }
else if (parag[cot]=='I'){
    e++;
}
else if (parag[cot]=='i'){
    f++;
}
else if (parag[cot]=='O'){
    g++;
}
else if (parag[cot]=='o'){
    h++;
}
else if (parag[cot]=='U'){
    i++;
}
else if (parag[cot]=='u'){
    j++;
}
}
a=a+b;
c=c+d;
e=e+f;
g=g+h;
i=i+j;
cout<<"(Lower and Uppercase combined for all vowels)\n";
cout<<"Number of a's "<<a<<endl;
cout<<"Number of e's "<<c<<endl;
cout<<"Number of i's "<<e<<endl;
cout<<"Number of o's "<<g<<endl;
cout<<"Number of u's "<<i<<endl;
}

