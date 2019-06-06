#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int &a,int &b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}

int linear_search(const int* arr, int searchItem, int len){
  for(int i = 0; i < len; i++){
    if(arr[i] == searchItem){
      return i;
    }
    else{
      return -1;
    }
  }
}

void bubble_sort(int *arr, int len){
  for(int i = 0; i < len-1; i++) {
    for(int j = i+1; j < len; j++) {
      if(arr[i] > arr[j]) {
        swap(arr[i],arr[j]);
      }
    }
  }
}

void selection_sort(int* arr, int len){
  int leastPointer = 0;
  for(int i = 0; i < len - 1; i++){
    leastPointer = i;
    for(int j = i + 1; j < len; j++){
      if(arr[j] < arr[leastPointer]){
        leastPointer = j;
      }
    }
    swap(arr[leastPointer], arr[i]);
  }
}

void insertionSort(int *arr, int len){
   int i,j;
   for(i=1;i<len;i++){
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

int binary_search(int* arr,int b, int len){
  bubble_sort(arr, len);
  int beg = 0,end = len-1;
  int mid=(beg+end)/2;
  while(beg <= end && arr[mid]!=b){
    if(arr[mid] < b){
      beg = mid+1;
    }
    else{
      end = mid-1;
    }
    mid =(beg+end)/2;
  }
  if(arr[mid] == b){
    return mid;
  }
  else{
    return -1;
  }
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

int main() {
  int arrSize = 0;
  cout<<"Enter array size: ";
  cin>>arrSize;
  int arr[arrSize];
  for(int i = 0; i < arrSize; i++){
    cout<<"Input item at index "<<i<<": ";
    cin>>arr[i];
    cout<<endl;
  }
  while(true){
    char choice;
    cout << "\n\nChoose actions: \n0.exit\n1.linear Search\n2.Binary search\n3.Bubble sort\n"
         <<"4.Quick sort\n5.Selection sort\n6.Display array."<< endl;
    cin>>choice;
    cin.ignore();
    switch(choice){
      case '0': {
        exit(0);
      }
      case '1': {
        int searchElement = 0;
        cout << "\nEnter search element:" <<endl;
        cin >> searchElement;
        int index = linear_search(arr, searchElement, arrSize);
        if(index == -1){
          cout<<"Element not found"<<endl;
        }
        else{
          cout<<"Element found at index: "<<index<<endl;
        }
        break;
      }
      case '2': {
        int searchElement = 0;
        cout << "\nEnter search element:" <<endl;
        cin >> searchElement;
        int index = binary_search(arr, searchElement, arrSize);
        if(index == -1){
          cout<<"Element not found"<<endl;
        }
        else{
          cout<<"Element found at index: "<<index<<endl;
        }
        break;
      }
      case '3': {
        bubble_sort(arr,arrSize);
        cout<<"Array is bubble sorted"<<endl;
        break;
      }
      case '4': {
        quick_sort(arr, 0, arrSize - 1);
        cout<<"Array is quick sorted"<<endl;
        break;
      }
      case '5': {
        selection_sort(arr, arrSize);
        cout<<"Array is selection sorted"<<endl;
        break;
      }
      case '6': {
        cout<<"array={ ";
        for (int x = 0; x < arrSize; x++) {
          cout << arr[x] <<' ';
        }
        cout<<"}"<<endl;
        break;
      }
      default: {
        cout<<"\nPlease enter valid input."<<endl;
      }
    }
  }
  return 0;
}
