//Kirk Broadbelt
#include<string>
#include<iostream>
using namespace std;

int main(){
string sent,temp,finale;
int coun,leng,index;
string letter;
cout<<"Enter sentence: "<<endl;
getline(cin,sent);

while(sent.length() !=0){
temp=sent.substr(0,sent.find(" ")-1);
if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U'){
        temp=temp+"way";
}
else{
            leng = temp.length();
            letter=temp[0];
            temp.insert(leng,letter);
            leng = temp.length();
            temp.insert(leng, "ay");
            temp.erase(0, 1);

}
finale=finale+temp+' ';
sent.erase(0,sent.find(' '));

}
cout<<finale;
}
