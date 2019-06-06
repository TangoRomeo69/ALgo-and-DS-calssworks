#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int &a,int &b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}

int quick_sort_partition(int* arr, int beg, int end){
  int pivotVal = arr[end];
  int pointer = beg - 1;
  for(int i = beg; i <= end - 1; i++){
    if(arr[i] <= pivotVal){
      pointer++;
      swap(arr[pointer], arr[i]);
    }
  }
  swap(arr[pointer + 1], arr[end]);
  return pointer + 1;
}

void quick_sort(int* arr, int beg, int end){
  if(beg < end) {
    int newPivot = quick_sort_partition(arr, beg, end);
    quick_sort(arr, beg, newPivot - 1);
    quick_sort(arr, newPivot + 1, end);
  }
}

int find_max(int* arr, int length){
  int max = INT32_MIN;
  for(int i = 0; i < length; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

void count_sort(int* arr, int len){
  int max = find_max(arr, len);
  int* testArr = new int[max +1];
  for(int i = 0; i < max + 1; i++){
    testArr[i] = 0;
  }
  for(int i = 0; i < len; i++){
    testArr[arr[i]]++;
  }
  int k = 0;
  for(int i = 0; i < max + 1; i++){
    for(int j = 0; j < testArr[i]; j++){
      arr[k] = i;
      k++;
    }
  }
}

int main(){
  int arr[5] = {0, 54, 23, 34, 88};
  for(int i = 0; i < 5; i++){
    cout<<arr[i]<<" ";
  }
  count_sort(arr, 5);
  cout<<endl;
  for(int i = 0; i < 5; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
