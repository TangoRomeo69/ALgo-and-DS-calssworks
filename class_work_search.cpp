#include<iostream>
#include"sort.h"

template <typename T>
int linearSearchFO(T* a,T b, int n){
    for(int i=0;i<n;i++){
        if(a[i]==b){
            return i;
        }
        else{
            return -1;
        }
    }
}

template <typename T>
int binarySearchFO(T* a,T b, int n){
    insertionSort(a,n);
    int beg=0,end=n-1;
    int mid=(beg+end)/2;
    while(beg<=end&&a[mid]!=b){
        if(a[mid]<b){
            beg=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(beg+end)/2;
    }
    if(a[mid]==b){
        return mid;
    }
    else{
        return -1;
    }
}
