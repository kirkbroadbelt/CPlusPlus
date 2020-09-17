//Kirk Broadbelt
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm> //can reverse name.reverse
//#include <stdio.h>
using namespace std;
int main(){
    for(int asd=0;asd<5;asd++){
        int firstdigit,tempi;
        string input,temps;
        vector <string> vstring;
        vector <int> vint;
        cin>>input;
        string fd=input.substr(0,1);
        firstdigit=strtol(fd.c_str(), NULL, 10);
        vstring.push_back(input.substr(1,firstdigit));
        temps=input.substr(1,firstdigit);
        tempi=strtol(temps.c_str(), NULL, 10);
        vint.push_back(tempi);
        input.erase(0,firstdigit+1);
        input=string( input.rbegin(), input.rend() );
        temps=input.substr(0,firstdigit);
        //error for if firstthing is .ess than next thing
        int count=0;
        while (input.size()>0){
            char temp[100];
            strcpy(temp,input.c_str());

            if(strtol(temp, NULL, 10)<vint[count]){
                break;
            }

            temps=input.substr(0,1);
            if(strtol(temps.c_str(), NULL, 10)>vint[count]){
                vstring.push_back(temps);
                vint.push_back(strtol(temps.c_str(), NULL, 10));
                input.erase(0,1);
            }
            //123456
            else {
                int x=1;
                while(true){
                    temps=input.substr(0,x);

                    if(strtol(temps.c_str(), NULL, 10)>vint[count]){
                        break;
                    }
                    if(x>input.length()){
                        break;
                    }
                    x++;
                }
                vstring.push_back(temps);
                vint.push_back(strtol(temps.c_str(), NULL, 10));
                input.erase(0,x);
            }
            count++;
        }
        for(int m=0;m<vint.size();m++){
            cout<<vint[m]<<" ";
        }
        cout<<endl;
        //if v string+1> vstring then add
    }
}
