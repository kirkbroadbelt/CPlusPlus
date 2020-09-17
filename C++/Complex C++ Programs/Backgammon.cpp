//Kirk Broadbelt
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<ctime>
#include<vector>
using namespace std;
COORD coord={0,0};
int redbar=0,whitebar=0;
struct location{
    int color=2;
    int numPieces=0;
};
class Piece{
private:
    int location;
    int color;
public:
    Piece();
    void setPiece(int,int);
    void setLocation(int);
    int checkLocation(int);
    int checkToGoHome;
    int getColor();
    int getLocation();
    void display();
};
Piece::Piece(){
location=99;
color=1;
}
void gotoxy(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Piece::setPiece(int c,int l){
color=c;
location=l;
}
int Piece::getColor(){
return color;
};
int Piece::getLocation(){
return location;
};
void Piece::setLocation(int lo){
location=lo;
}
void Piece:: display(){             // Shows what a piece looks like based on color
            if (color == 1){
                cout<<'R';
            }
            else if (color == -1){
                cout<<'W';
            }
            else{
                cout<<"Nothing to see here";
            }
            }
class Board{
private:
    Piece list[20];
    location loc[27];
    int status=1;
    int pieceAtLoc(int,int);
    void turn();
    void move();
    int checkbar(int);
    int checkmove(int,int);
    void validateLoc(int,int);
    void display();
    void bump(Piece);
    int diceRoll(int&,int&);
public:
    Board();
    void execute();
};
int Board:: diceRoll(int &dice1, int &dice2){
srand(time(NULL));
dice1= rand()%6+1;
dice2=rand()%6+1;

}
void Board::bump(Piece tobump){
tobump.setLocation(26);
}
Board::Board(){
    list[0].setPiece(1,1);
    list[1].setPiece(1,1);
    list[2].setPiece(1,1);
    list[3].setPiece(1,1);
    list[4].setPiece(1,2);
    list[5].setPiece(1,2);
    list[6].setPiece(1,2);
    list[7].setPiece(1,2);
    list[8].setPiece(1,2);
    list[9].setPiece(1,2);
    list[10].setPiece(-1,3);
    list[11].setPiece(-1,3);
    list[12].setPiece(-1,3);
    list[13].setPiece(-1,3);
    list[14].setPiece(-1,3);
    list[15].setPiece(-1,3);
    list[16].setPiece(-1,3);
    list[17].setPiece(-1,3);
    list[18].setPiece(-1,3);
    list[19].setPiece(-1,3);
//    list[0].setPiece(1,1);
//    list[1].setPiece(1,1);
//    list[2].setPiece(1,6);
//    list[3].setPiece(1,6);
//    list[4].setPiece(1,6);
//    list[5].setPiece(1,8);
//    list[6].setPiece(1,8);
//    list[7].setPiece(1,12);
//    list[8].setPiece(1,12);
//    list[9].setPiece(1,12);
//    list[10].setPiece(-1,13);
//    list[11].setPiece(-1,13);
//    list[12].setPiece(-1,13);
//    list[13].setPiece(-1,17);
//    list[14].setPiece(-1,17);
//    list[15].setPiece(-1,19);
//    list[16].setPiece(-1,19);
//    list[17].setPiece(-1,19);
//    list[18].setPiece(-1,24);
//    list[19].setPiece(-1,24);
}
void Board::turn(){
status=status*-1;
}
void Board::move(){
    for (int k = 1;k<25;k++){
    loc[k].numPieces=0;
}
for (int k = 0;k<20;k++){
   int x = list[k].getLocation();
    loc[x].numPieces++;
}
for(int d=1;d<24;d++){
    loc[list[d].getLocation()].color=list[d].getColor();
}
int d1,d2,startloc,newloc,colormove,klm=0,cannotmove=0,x=1;
//diceRoll(d1,d2);
d1=1;
d2=2;

int d11=d1,d12=d2;
int counter=0,combinemove=0,goagain=0,skip=0;
while (true){
if(status==1){
    cout<<"Player 1's Turn\n";
}
else{
    cout<<"Player 2's Turn\n";
}
vector <int> skiploc;
for(int j=0;j<=24;j++){
    if(loc[j].color==status){
    skiploc.push_back(j);
    }
}
int locnum=0,locnum2=0,locnum3=0;
for(int g=0;g<skiploc.size();g++){
     int check1=skiploc[g]+(d1*status);
     int check2=skiploc[g]+(d2*status);
     int check3=skiploc[g]+((d1+d2)*status);
    if((loc[check1].numPieces>1 ||loc[check1].numPieces==0)&& loc[check1].color==-1*status){
       locnum++;
    }
     if((loc[check2].numPieces>1 ||loc[check2].numPieces==0)&& loc[check2].color==-1*status){
       locnum2++;
    }
    if((loc[check3].numPieces>1 ||loc[check3].numPieces==0)&& loc[check3].color==-1*status){
       locnum3++;
    }
}
if(locnum==skiploc.size() && locnum2==skiploc.size() && locnum3==skiploc.size()){
    skip=1;
}
if(skip==1){
    status=status*-1;
    cout<<"\nNo possible moves, turn skipped\n\n\n";
    system("PAUSE");
    move();
}
int homecountr=0,homecountw=0,canmovehome=0;
for(int yo=0;yo<20;yo++){
                if(list[yo].getLocation()== (19 || 20 || 21|| 22 || 23 || 24)){
                homecountr++;
                }
                else if(list[yo].getLocation()==(1 || 2 || 3 || 4 || 5 || 6)){
                    homecountw++;
                }
}
if(homecountr==10 ||homecountw==10){
    cout<<"You can move pieces home";
    canmovehome=1;
}

cout<<"You rolled a "<<d1<<" and a "<<d2<<endl;
int sloc,moveint,doubles=0;
if(d1==d2){
    cout<<"You rolled doubles!\n";
     doubles=1;
}
cout<<"Enter position of the piece you want moved\n";
cin>>sloc;
cout<<"Enter how many spaces you want to move\n";
cin>>moveint;
newloc=sloc+(moveint*status);
if(moveint!=d1 && moveint!=d2 && moveint !=(d1+d2)){
cout<<"Not what you rolled\n\n\n";
continue;
}
else if(loc[sloc].numPieces<1){
cout<<"No pieces there\n\n\n";
continue;
}
else if((loc[newloc].numPieces>=2 && loc[newloc].color!=status)){
cout<<"Cannot move there\n\n\n";
continue;
}

if(moveint==d1||moveint==d2){
goagain++;
}
else if(moveint==(d1+d2)){
goagain=goagain+2;
}


if (canmovehome==0){
if(loc[newloc].numPieces==1 && loc[newloc].color==(status*-1)){

            for (int gas=0;gas<20;gas++){
                if(list[gas].getLocation()==newloc) {
                    if(status==1){
                        list[gas].setLocation(26);
                              whitebar++;
                    }
                    else{
                    list[gas].setLocation(27);
                       redbar++;
    }

                    break;
     }
}
        int co=0;
            while (true){
                if(sloc==list[co].getLocation()) {
                        list[co].setLocation(newloc);
                        break;
                        cout<<loc[newloc].numPieces;
            }
                co++;
            }
system("CLS");
display();
gotoxy(1,20);
status=status*-1;
}
else if ((loc[newloc].numPieces!=1 && status==loc[newloc].color)|| loc[newloc].numPieces==0) {
        int co=0;
            while (true){
                if(sloc==list[co].getLocation()) {
                        list[co].setLocation(newloc);
                        break;
                           cout<<loc[newloc].numPieces;
            }
               co++;
            }
system("CLS");
display();
gotoxy(1,20);
}
else{
    cout<<"Cannot move there";
    continue;
}
}
else if(canmovehome==1){
    if (homecountr==10 && newloc==0){
        while (true){
            int co=0;
            if(sloc==list[co].getLocation()) {
                        list[co].setLocation(newloc);
                        break;
            }
               co++;
            }
    }
    else{
        cout<<"Must roll exact value";
    }
     if (homecountw==10 && newloc==25){
        while (true){
            int co=0;
            if(sloc==list[co].getLocation()) {
                        list[co].setLocation(newloc);
                        break;
            }
               co++;
            }
    }
    else{
        cout<<"Must roll exact value";
    }
}
if(doubles==1 && goagain==2){
goagain=0;
}
else if(goagain==2 && doubles==0){
goagain=0;
    break;
}
else if(goagain==1&& doubles==0){
    continue;
}
}
}
void Board::display(){
//system("CLS");
for (int k = 1;k<25;k++){
    loc[k].numPieces=0;
}
for (int k = 0;k<20;k++){
    int x = list[k].getLocation();
    loc[x].numPieces++;
}
for(int d=1;d<24;d++){
//        for(int op=0;op<20;op++){
//                if(list[op].getLocation()==d){
    loc[list[d].getLocation()].color=list[d].getColor();
//    break;
//}
//
//else{
//    loc[d].color=2;
//    break;
//}
//        }
}
for(int x=1;x<=12;x++){
    gotoxy((6*x),0);
    cout<<x;
}
int c=0;
for(int x=1;x<13;x++){
    gotoxy((6*x),1);
    c=0;
    for(int a=0;a<20;a++){
        if(list[a].getLocation()==x && c!=1){
    if((list[a].getColor()==1)&&(loc[x].numPieces>=1)){
        cout<<"R";
    }
    else if((list[a].getColor()==-1)&&(loc[x].numPieces>=1)){
        cout<<"W";
    }
    else{
        cout<<" ";
    }
    c=1;
        }
    }
}
for(int x=1;x<=12;x++){
    gotoxy((6*x),2);
if(loc[x].numPieces>0){
    cout<<loc[x].numPieces;
    }
    else{
    cout<<" ";
}
}

int m=1;
for(int x=24;x>12;x--){
    gotoxy((6*m),15);
    cout<<x;
    m++;
}
m=1;
for(int x=24;x>12;x--){
    gotoxy((6*m),13);
if(loc[x].numPieces>0){
    cout<<loc[x].numPieces;
    }
    else{
        cout<<" ";
    }
m++;
}
for(int x=13;x<25;x++){
    gotoxy((25-x)*6,14);
    c=0;
    for(int a=0;a<20;a++){
        if((list[a].getLocation()==x) && (c!=1)){
    if((list[a].getColor()==1)&&(loc[x].numPieces>=1)){
        cout<<"R";
    }
    else if((list[a].getColor()==-1)&&(loc[x].numPieces>=1)){
        cout<<"W";
    }
    else{
        cout<<" ";
    }
    c=1;
        }
    }
}
gotoxy(15,8);

//for(int x=0;x<20;x++){
//        if((list[x].getLocation()==26)&&(list[x].getColor()==1)){
//                redbar++;
//}
//else if((list[x].getLocation()==27)&&(list[x].getColor()==-1)){
//        whitebar++;
//}
//}
cout<<"Number of Pieces on Bar:     Red: "<<redbar<<"      White: "<<whitebar;
cout<<endl;
}

void Board::execute(){
    int p1,p2;
while(true){
    diceRoll(p1,p2);
cout<<"Dice roll to see who goes first\nPlayer 1 rolls: "<<p1<<"\nPlayer 2 rolls: "<<p2<<endl<<endl;

if(p1>p2){
    status=1;
    cout<<"Player 1 goes first\n";
    break;
}
else if(p1<p2){
    status=-1;
    cout<<"Player 2 goes first\n";
    break;
}
else if (p1==p2){
    cout<<"Tied! Reroll\n\n";
    system("PAUSE");
    continue;

}
}
system("PAUSE");
system("CLS");
display();
gotoxy(1,20);
int player1win=0,player2win=0;
while (true){
if(loc[0].numPieces==10){
    player2win=1;
}
else if(loc[25].numPieces==10){
    player1win=1;
}
if (player1win==1 && player2win==1){
    system("CLS");
    if (player1win==1){
        cout<<"PLAYER 1 WINS!";
    }
    else{
        cout<<"PLAYER 2 WINS!";
    }
break;
}
move();
turn();
}
}
int main(){
Board b;
b.execute();
gotoxy(1,25);
return 0;
}

