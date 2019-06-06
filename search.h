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
    bubbleSort(a,n);
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

template <typename T>
int linearSearchLO(T* a,T b, int n){
    int LO=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            LO=i;
        }
        else{

            return -1;
        }
    }
    return LO;
}

template <typename T>
int linearSearchNO(T* a,T b, int n){
    int NO=0;
    for(int i=0;i<n;i++){
        if(a[i]==b){
            NO++;
        }
        else{
            return -1;
        }
    }
    return NO;
}
