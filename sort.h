#include<iostream>

template<typename T>
void swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<typename T>
void bubbleSort(T *a, int n){
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(a[i]>a[j]) {
                swap(a[i],a[j]);
            }
        }
    }
}

template<typename T>
void selectionSort(T *a, int n){
    T k;
    int i,j;
    for (i=0;i<n-1;i++) {
        k = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[k], a[i]);
    }
}

template<typename T>
void insertionSort(T *a, int n){
   int i,j;
   for(i=1;i<n;i++){
       for(j=i-1;j>=0;j--){
           if(a[j+1]<a[j]){
               swap(a[j+1],a[j]);
           }
           else{
               break;
           }
       }
   }
}
template<typename T>
void display(const T* j,int cn) {
    std::cout<<"array={ ";
    for (int x = 0; x < cn; x++) {
        std::cout << j[x] <<' ';
    }
    std::cout<<"}"<<std::endl;
}
