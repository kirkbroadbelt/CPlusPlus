#include<iostream>
using namespace std;
class Addition{
    private:
        int a,b,c;
    public:
        int d;
        void input();
        void sum();
        void display();
        int geta();
        void operator-();
        void operator+(Addition);
};
void Addition::input(){
    cout<<"Enter three numbers: ";
    cin>>a>>b>>c;
}
void Addition::operator+(Addition temp){
    cout<<"Mr.Potter's a: "<<a<<endl;//Paul + dr.lyerlys paul
    cout<<"Dr.Lyerly's a: "<<temp.geta()<<endl;
    cout<<"Sum: "<<a+temp.geta();
}
void Addition::operator-(){
    a=-a;
    b=b+2;
    c=-c+10;
}
int Addition::geta(){
    return a;
}
void Addition::sum(){
    d=a+b+c;
}
void Addition::display(){
    cout<<a<<b<<c<<endl;
    sum();//******redundant to say potter.sum();
    //cout<<"Sum is "<<d;
}
int main(){
    Addition potter,lyerly;
    potter.input();
    lyerly.input();
    //potter.sum();
    //potter.display();
    //-potter;
    potter.display();
    lyerly.display();
    potter+lyerly;
    return 0;
}
