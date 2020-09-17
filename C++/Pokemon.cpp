#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Pet{
	private:
		string name;
        int health;
		int exper;
    public:
		Pet();
		void setName(string);
		string getName(string);
		int getHealth(int);
		int getExp(int);
		void fight(int,int);
		void rest(int,int);
		void Attributes(int,int,string);
	};
Pet::Pet(){
health=100;
exper=0;
}

void Pet::setName(string namepet){
    cout<<"Enter your pet's name!\n";
    cin>>name;
    namepet=name;
}

string Pet::getName(string gName){
    gName=name;
    return name;
}

int Pet::getHealth(int gHealth){
    gHealth=health;
    return health;
}

int Pet::getExp(int gExp){
    gExp=exper;
    return exper;
}

void Pet::fight(int fxp,int fhp){
    srand(time (NULL));
    int random=rand()%3+1;
if(random==1){//LOSS
    fxp=fxp+5;
    fhp=fhp-15;
    cout<<"\n You LOST the fight!\n";
}
else if(random==2){ //TIE
    fxp=fxp+10;
    fhp=fhp-10;
    cout<<"\n You TIED the fight!\n";
}
else{
    fxp=fxp+15;
    fhp=fhp-5;
    cout<<"\n You WON the fight!\n";
}
}

void Pet::rest(int rxp,int rhp){
    rxp=rxp-5;
    rhp=rhp+10;
if (rhp>100){
    rhp=100;
}
cout<<"\nYOU RESTED\n";
}

void Pet::Attributes(int axp,int ahp, string aname){
    cout<<"\n\n\n\nName: "<<aname<<"\nExperience: "<<axp<<"\nHealth: "<<ahp;
}

int main(){
    int mHealth,mExp,selection;
    string mName;
    Pet p;
    p.getExp(mExp);
    p.getHealth(mHealth);
    p.setName(mName);
    p.getName(mName);
while(mHealth!=0){
    cout<<"\nMenu\n<1> Fight\n<2> Rest\n<3> Attributes\n";
    cin>>selection;
if(selection==1){
    p.fight(mExp,mHealth);
    p.Attributes(mExp,mHealth,mName);
}
else if(selection==2){
    p.rest(mExp,mHealth);
    p.Attributes(mExp,mHealth,mName);
}
else{
    p.Attributes(mExp,mHealth,mName);
}
}
if (mHealth=0){
    cout<<"\n YOUR PET HAS BEEN SLAIN";
}
else{
    cout<<"\n YOUR PET HAS EVOLVED";
}
}
