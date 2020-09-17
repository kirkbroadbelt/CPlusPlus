// Kirk Broadbelt
#include<iostream>
using namespace std;
const int arnum=10;
int check1=0, check2=0,check3=0,check4=0,check5=0;
void qSort(int ar[],int b, int e){
    check1++;
if (b!=e){
    int p=b, temp;
    int start=p+1;
    int end=e;
    int f=start;
    int l=e;
    if(start==end){
        check2++;
        if(ar[p]>ar[l]){
            temp=ar[p];
            ar[p]=ar[l];
            ar[l]=temp;
        }
    }
else{
        do{
        while (ar[p]<ar[l] && l>start){
            l--;
        }
        while (ar[p]>ar[f] && f<end){
            f++;
        }
        if (f<l){
            temp=ar[f];
            ar[f]=ar[l];
            ar[l]=temp;
        }

       }
       while (f<l);

           if (f==end){
                temp=ar[p];
                ar[p]=ar[end];
                ar[end]=temp;
                check4++;
                qSort(ar, p , end-1);
            }
            else if (f==l) {
            check3++;
            qSort(ar,start,end);
        }
            else {
                temp=ar[p];
                ar[p]=ar[l];
                ar[l]=temp;
                check5++;
                qSort(ar, p , l-1);
                qSort(ar, l+1 , end);
            }
        }

    }
}

int main(){
int beg=0, ending=(arnum-1);
int array[arnum]={1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
for(int abc=0;abc<arnum;abc++){
    cout<<array[abc]<<" ";
}
cout<<endl;
qSort(array, beg, ending);
for(int abc=0;abc<arnum;abc++){
    cout<<array[abc]<<" ";
}
cout<<"\n";
cout<<check1<<endl;
cout<<check2<<endl;
cout<<check3<<endl;
cout<<check4<<endl;
cout<<check5<<endl;
return 0;
}
