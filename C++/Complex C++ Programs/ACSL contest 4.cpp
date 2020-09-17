//Kirk Broadbelt
//Period 7
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void fInput(string firstInput[]){
    int position=0;
    string fInput;

    cout<<"Seperate by commas: ";
    getline(cin,fInput);
    // EXAMPLE fInput=",a,aa,aaa,ab,abb,aabb,aaab,abbb,b";


    //Seperate first input by commas
    for(int i=0;i<10;i++){
        while( (fInput[position]!=',' )&&(position!=fInput.length()) ){
            firstInput[i]=firstInput[i]+fInput[position];
            if(fInput[position]==' ' ){
                firstInput[i]='#';
            }
            position++;
        }
        position++;
    }
    cout<<endl;
    // EXAMPLE firstInput={"","a","aa","aaa","ab","abb","aabb","aaab","abbb","b"}
}

void splitFirstInput(string firstInput[], string parsedFirstInput[], int &length){
    ostringstream tempAdd;
    vector<int> count;
    vector<char> id;
    string temp;
    int j=0, x=1;

    //If empty replace with #
    for(int i=0;i<10;i++){
        if(firstInput[i].empty()){
            firstInput[i] ="#";
        }
    }
    // EXAMPLE firstInput={"#","a","aa","aaa","ab","abb","aabb","aaab","abbb","b"}

    //Split input into characters (aaaaab->ab) and number of characters (aaabbc->321)
    for(int i=0;i<10;i++){
        for(int k=0;k<3;k++){
            if( (isalpha(firstInput[i][j+1]))|| (k==0) ){
                if(k==0){
                    id.push_back(firstInput[i][0]);
                }
                else{
                    j++;
                    id.push_back(firstInput[i][j]);
                }

                while(firstInput[i][j]==firstInput[i][j+1]){
                    j++;
                    x++;
                }
                count.push_back(x);
                x=1;
            }
        }

        //Combine characters and numbers together, exm. a1b2c4 (abbcccc)
        for(int i=0;i<count.size();i++){
            if(id[i]!='#'){
                tempAdd<<temp<<id[i]<<count[i];
            }
            else{
                tempAdd<<temp<<id[i];
            }

        }
        parsedFirstInput[i]=tempAdd.str();
        // EXAMPLE parsedFirstInput={"#","a1","a2","a3","a1b1","a1b2","a2b2","a3b1","a1b3","b1"};

        //Reset for next loop run
        id.clear();
        count.clear();
        temp.clear();
        tempAdd.str("");
        tempAdd.clear();
        j=0;
    }

    //Find largest length of first input, used in possibility generation as limit
    for(int i=0;i<10;i++){
        if(firstInput[i].length()>length){
            length=int(firstInput[i].length());
        }
    }
    // EXAMPLE length=4; (longest are aabb, abbb, aaab)
}

void inputSearch(string &input, int i){
    //Input regular expression
    cout<<"Input "<<i+1<<": ";
    cin>>input;
    // EXAMPLE input=a?b*;
}

void splitInput(string input, int length, vector<char> &id, vector<string> &seperatedInput, vector<vector<int> > &count){
    int tempLength;
    vector<int> row;

    //Char values for input ( exm. a?b* -> ab )
    for(int i=0;i<input.length();i++){
        if( isalpha(input[i]) ){
            id.push_back(input[i]);
        }
    }
    // EXAMPLE id={'a','b'};

    //Split into individual elements ( exm. a?b*c -> a?,b*,c )
    for(int i=0;i<input.length();i++){
        if(isalpha(input[i+1])){
            seperatedInput.push_back(input.substr(i,1));
        }
        else{
            seperatedInput.push_back(input.substr(i,2));
            i++;
        }
    }
    // EXAMPLE seperatedInput={"a?","b*"};

    for(int i=0; i<seperatedInput.size();i++){
        if(seperatedInput[i][1]=='?'){
            row.push_back(0);
            row.push_back(1);
        }
        else if(seperatedInput[i][1]=='*'){
            for(int j=0;j<5;j++){
                row.push_back(j);
            }
        }
        else if(seperatedInput[i][1]=='+'){
            for(int j=1;j<5;j++){
                row.push_back(j);
            }
        }
        else{
            row.push_back(1);
        }

        //Each row corresponds to each element
        count.push_back(row);
        // EXAMPLE count[0]={0,1}, count[1]={0,1,2,3,4};

        row.clear();
    }
}

void generatePoss(vector<string> &poss, vector<char> id, vector<vector<int> > count, int length){
    ostringstream tempAdd;

    if(id.size()==3){
        for(int i=0;i<count[0].size();i++){
            for(int j=0;j<count[1].size();j++){
                for(int k=0;k<count[2].size();k++){
                    if(count[0][i]+count[1][j]+count[2][k]<=length){
                        tempAdd<<id[0]<<count[0][i]<<id[1]<<count[1][j]<<id[2]<<count[2][k]<<endl;
                        poss.push_back(tempAdd.str());
                        //Reset for next
                        tempAdd.str("");
                        tempAdd.clear();

                    }
                }
            }
        }

    }
    else if(id.size()==2){
        for(int i=0;i<count[0].size();i++){
            for(int j=0;j<count[1].size();j++){
                if(count[0][i]+count[1][j]<=length){
                    tempAdd<<id[0]<<count[0][i]<<id[1]<<count[1][j]<<endl;
                    poss.push_back(tempAdd.str());
                    //Reset for next
                    tempAdd.str("");
                    tempAdd.clear();

                }
            }
        }
        // EXAMPLE poss={"a0b0","a0b1","a0b2","a0b3","a0b4","a1b0","a1b1","a1b2","a1b3"};
    }
    //If 1 Element... 1 loop
    else{
        for(int i=0;i<count[0].size();i++){
            if(count[0][i]<=length){
                tempAdd<<id[0]<<count[0][i]<<endl;
                poss.push_back(tempAdd.str());
                tempAdd.str("");
                tempAdd.clear();
            }
        }
    }

    //Remove elements with value of 0, if all replaced, replace with #
    for(int i=0;i<poss.size();i++){
        for(int j=0;j<poss[i].length();j++){
            if( poss[i][j]=='0' ){
                poss[i].erase(j-1,2);
                j=0;
            }
        }
        poss[i].erase(poss[i].find('\n'), 1);
        if(poss[i].empty()){
            poss[i]="#";
        }
    }
    // EXAMPLE poss={"#","b1","b2","b3","b4","a1","a1b1","a1b2","a1b3"};
}

void matchOutput(vector<string> poss, string parsedFirstInput[], string firstInput[], int  matchFoundFlag){
    vector<string> output;

    //If possibility matches parsed first input, cout
    for(int i=0;i<poss.size();i++){
        for(int j=0;j<10;j++){
            if(parsedFirstInput[j]==poss[i]){
                cout<<firstInput[j]<<" ";
                matchFoundFlag=1;
            }
        }
    }

    //If no match is found, output NONE
    if( matchFoundFlag=0){
        cout<<"NONE";
    }
    cout<<endl<<endl;
}

int main() {
    vector<vector<int> > count;
    vector<char> id;
    vector<string> seperatedInput, poss;
    string firstInput[10], parsedFirstInput[10], input;
    int length=0,  matchFoundFlag=0;

    fInput(firstInput);
    splitFirstInput(firstInput,parsedFirstInput, length);

    for(int i=0;i<5;i++){
        inputSearch(input,i);
        splitInput(input, length, id, seperatedInput, count);
        generatePoss(poss,id,count,length);
        matchOutput(poss, parsedFirstInput, firstInput,  matchFoundFlag);
        seperatedInput.clear();
        poss.clear();
        id.clear();
        count.clear();
    }

    return 0;
}
