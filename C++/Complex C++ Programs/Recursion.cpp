#include <iostream>
using namespace std;
int f(int a){
if (a>=9){
    return f(a-1)-f(a-2);
}
else if(a<9 &&(a%2!=0)){
    return f(a-3)-5;
}
else{
    return 2*a;
}
}
int main(){
int in;
cin>>in;
cout<<f(in);
return 0;
}
