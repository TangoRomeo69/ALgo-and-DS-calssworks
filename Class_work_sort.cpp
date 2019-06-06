#include"sort.h"

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
        cout << "\n\nChoose actions: \n0.exit\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Display array\n\n" << endl;
        cin >> funcChoice;
        getchar();
        switch (funcChoice){
            case '1': {
                bubbleSort(arr,n);
                cout<<"Bubble sort successfull"<<endl;
                break;
            }
            case '2': {
                selectionSort(arr,n);
                cout<<"Selection sort successfull"<<endl;
                break;
            }
            case '3': {
                insertionSort(arr,n);
                cout<<"Insertion sort successfull"<<endl;
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
