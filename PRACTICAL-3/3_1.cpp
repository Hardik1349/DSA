#include<iostream>
using namespace std;

int main(){
    int a[5] = {35,60,25,15,98};
    int i,j,temp;
    cout << "Sorting by Bubble Sort Method:" << endl;
    cout << endl;
    cout << "Array before sorting"<< endl;
    for(i=0;i<5;i++){
        cout << a[i] << " ";
    }
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(a[j]<a[i]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout << "\nArray after sorting"<< endl;
    for(i=0;i<5;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Sorting by Selection Sort Method:" << endl;
    cout << endl;
    int ar[5]={38,19,68,57,29};
    int b,c,tempp;
    cout << "Array before sorting"<< endl;
    for(b=0;b<5;b++){
        cout << ar[b] << " ";
    }
    cout << endl;
    for(b=0;b<5;b++){
        int min = b;
        for(c=b+1;c<5;c++){
            if(ar[min]>ar[c]){
                min=c;
            }
        }
        tempp=ar[b];
        ar[b]=ar[min];
        ar[min]=tempp;  
    }
    cout << "Array after sorting"<< endl;
    for(b=0;b<5;b++){
        cout << ar[b] << " ";
    }

    cout << "Sorting by Insertion Sort Method:" << endl;
    cout << endl;
    int ar[5]={38,19,68,57,29};
    int d,e,temp;
    cout << "Array before sorting"<< endl;
    for(d=0;d<5;d++){
        cout << ar[d] << " ";
    }
    cout << endl;
    
    return 0;
}