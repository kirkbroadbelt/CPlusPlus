//Kirk Broadbelt
#include <iostream>
using namespace std;
const int arraysize=10;
void bubble(int a[]){
for(int x=0;x<arraysize;x++){
for(int i=0;i<arraysize;i++){
for(int z=i+1;z<arraysize;z++){
    int temp;
    if(a[i]>a[z]){
        temp=a[i];
        a[i]=a[z];
        a[z]=temp;
}
}
}
}

for(int abc=0;abc<arraysize;abc++){
    cout<<a[abc]<<",";
}
    cout<<endl<<endl<<endl<<a[0]<<endl<<a[9]<<endl;
    cout<<(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])/8.0;
}
int main(){
int bubbsort[arraysize]={3,6,4,9,3,0,15,7,1,4};
bubble(bubbsort);
}
