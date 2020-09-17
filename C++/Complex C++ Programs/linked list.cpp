//Kirk Broadbelt
#include<stdlib.h>
#include<iostream>
#include<ctype.h>
#include<vector>
using namespace std;
class listnode {
    private:
        int data;
        listnode *next;
    public:
        listnode(int d,listnode *n){data=d,next=n;}
        int getData(){return(data);}
        listnode* getNext(){return(next);}
        void setNext(listnode *n){next=n;}
};
class list{
    private:
        listnode *first;
    public:
        list(){first=NULL;}
        void print();
        void insert (int x);
        void deleteint (int y);
        void menu();
};
void list::print(){
        listnode *temp=first;
        while (temp!=NULL){
            cout<<temp->getData()<<" ";
            temp=temp->getNext();
        }
}
void list::insert(int i){
   listnode *newbie = new listnode(i,NULL);
    if(first){
        listnode *current=first;
        //Less than
        if(newbie->getData()<first->getData()){
            newbie->setNext(first);
            first=newbie;
        }
        else{
            while(current->getNext() && newbie->getData() > current->getNext()->getData()){
                current=current->getNext();
            }
            if(current->getNext()){
                newbie->setNext(current->getNext());
                current->setNext(newbie);
            }
            else{
                current->setNext(newbie);
            }
        }
    }
    else{
        first=newbie;
    }
}
void list::deleteint(int a){
    if(first){
        listnode *current=first;
        while(current->getData()!=a&&current->getNext()){
            current=current->getNext();
        }
        if(current==first){
            first=first->getNext();
        }
        else if(current->getNext()->getNext()){
            current->setNext(current->getNext()->getNext());
        }
        else{
            current->setNext(NULL);
        }
    }
}
void list::menu(){
    int entry,num,num1;
    while(entry!=4){
        cout<<"\n1. Print list\n2. Insert into list\n3. Delete from list\n4. Exit\n";
        cin>>entry;
        cout<<endl;
        if(entry==1){
            print();
            cout<<endl;
        }
        else if(entry==2){
            cout<<"\n\nEnter number you want to insert\n";
            cin>>num;
            insert(num);
            cout<<endl;
        }
        else if(entry==3){
            cout<<"\n\nEnter number you want to delete\n";
            cin>>num1;
            deleteint(num1);
            cout<<endl;
        }
    }

}
int main(){
list l;
l.menu();
return 0;
}
