//kirk broadbelt pd 7

#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

struct song{
    string title;
    string artist;
    double length;
};

void addSong(vector<song> &playlist){
    string title, artist;
    double length;
    cin.sync();
    cout<<"Adding song "<<playlist.size()+1<<endl<<"Title:  ";
    getline(cin,title);
    cout<<"Artist: ";
    getline(cin,artist);
    cout<<"Length: ";
    cin>>length;
    cout<<endl;
    playlist.push_back( {title,artist,length} );
}

vector<song> sortPlaylist(vector<song> &playlist, string order){
    vector<song> sortedPlaylist=playlist;
    song temp;

    if(order=="title"){
        for(int i=0; i<sortedPlaylist.size()-1; i++){
            for(int j=i+1;j<sortedPlaylist.size();j++){
                if (sortedPlaylist[i].title>sortedPlaylist[j].title){
                    temp=sortedPlaylist[i];
                    sortedPlaylist[i]=sortedPlaylist[j];
                    sortedPlaylist[j]=temp;
                }
            }
        }
    }
    else if(order=="artist"){
        for(int i=0; i<sortedPlaylist.size()-1; i++){
            for(int j=i+1;j<sortedPlaylist.size();j++){
                if (sortedPlaylist[i].artist>sortedPlaylist[j].artist){
                    temp=sortedPlaylist[i];
                    sortedPlaylist[i]=sortedPlaylist[j];
                    sortedPlaylist[j]=temp;
                }
            }
        }
    }
    else if(order=="length"){
        for(int i=0; i<sortedPlaylist.size()-1; i++){
            for(int j=i+1;j<sortedPlaylist.size();j++){
                if (sortedPlaylist[i].length>sortedPlaylist[j].length){
                    temp=sortedPlaylist[i];
                    sortedPlaylist[i]=sortedPlaylist[j];
                    sortedPlaylist[j]=temp;
                }
            }
        }
    }
    else{}

    return sortedPlaylist;
}

void displayPlaylist(vector<song> playlist){
    cout<<left<<setw(20)<<"Title"<<setw(20)<<"Artist"<<setw(20)<<"Length"<<endl;
    for(int i=0;i<playlist.size();i++){
        cout<<setw(20)<<playlist[i].title<<setw(20)<<playlist[i].artist<<setw(20)<<playlist[i].length<<endl;
    }
    cout<<endl;
}

int main(){
    vector<song> playlist, temp;
    int menuInput=0;

    while(menuInput!=6){
        cout<<"Hello, welcome to VSPod.\nWould you like to: \n <1> Add a song. \n <2> Sort By Title. \n <3> Sort By Artist. \n <4> Sort By Length. \n <5> Print Your Playlist. \n <6> Exit.\n ";
        cin>>menuInput;
        cout<<endl;

        if(menuInput==1){
            addSong(playlist);
        }
        else if(menuInput==2){
            temp=sortPlaylist(playlist,"title");
            displayPlaylist(temp);
        }
        else if(menuInput==3){
            temp=sortPlaylist(playlist,"artist");
            displayPlaylist(temp);
        }
        else if(menuInput==4){
            temp=sortPlaylist(playlist,"length");
            displayPlaylist(temp);
        }
        else if(menuInput==5){
            displayPlaylist(playlist);
        }

    }

    return 0;
}
