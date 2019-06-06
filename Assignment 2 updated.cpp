#include<iostream>

template<typename T>
void swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<typename T>
void bubbleSort(T *a, int n, int &m){
    for(int i=0;i<n-1;i++) {
        m++;
        for(int j=i+1;j<n;j++) {
            m++;
            if(a[i]>a[j]) {
                swap(a[i],a[j]);
                m++;
            }
        }
    }
}

template<typename T>
void selectionSort(T *a, int n, int &m){
    T k;
    int i,j;
    for (i=0;i<n-1;i++) {
        m++;
        k = i;
        for (j = i+1; j < n; j++) {
            m++;
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[k], a[i]);
    }
}

template<typename T>
void insertionSort(T *a, int n, int &m){
    int i,j;
    for(i=1;i<n;i++){
        m++;
        for(j=i-1;j>=0;j--){
            m++;
            if(a[j+1]<a[j]){
                swap(a[j+1],a[j]);
                m++;
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

template<typename T>
void Copy(T* a, T*b, int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

int main(){
    using namespace std;
    char funcChoice;
    int *arr;
    int c = 0, n=0;
    while(true){
        cout << "Please enter the array size: ";
        cin >> n;
        getchar();
        if(n<1 || n>99999){
            cout<<"Please enter a valid input\n";
        }
        else{
            break;
        }
    }
    arr = new int[n];

    for(int i=0; i < n; i++){
        cout<<"Enter array elemnt at index "<<i<<": ";
        cin >> arr[i];
        getchar();
    }

    while(true) {
        cout << "\n\nChoose actions: \n0.exit\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Display unsorted array\n\n" << endl;
        cin >> funcChoice;
        getchar();
        switch (funcChoice){
            case '1': {
                int* s= new int[n];
                Copy(arr,s,n);
                c=0;
                bubbleSort(s,n,c);
                cout<<"bubble sort successfull"<<endl<<"Number of operations: "<<c<<endl;
                display(s,n);
                delete[]s;
                break;
            }
            case '2': {
                int* s= new int[n];
                Copy(arr,s,n);
                c=0;
                selectionSort(s,n,c);
                cout<<"Selection sort successfull"<<endl<<"Number of operations: "<<c<<endl;
                display(s,n);
                delete[]s;
                break;
            }
            case '3': {
                int* s= new int[n];
                Copy(arr,s,n);
                c=0;
                insertionSort(s,n,c);
                cout<<"insertion sort successfull"<<endl<<"Number of operations: "<<c<<endl;
                display(s,n);
                delete[]s;
                break;
            }
            case '4': {
                display(arr,n);
                break;
            }
            case '0': {
                exit(0);
            }
            default: {
                cout<<"\nPlease enter valid input."<<endl;
                }
        }
    }
    return 0;
}

