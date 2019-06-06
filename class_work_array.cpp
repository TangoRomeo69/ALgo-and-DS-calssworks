#include <iostream>
/*
#include <cstdio>
#include <cstdlib>
*/
void del(int* j, int pos, int &cn){
    for(int n=pos;n<cn;n++) {
        j[n] = j[n + 1];
    }
    cn--;
}
void insert(int* j, int pos, int input, int &cn){
    for(int n=cn-1;n>=pos;n--) {
        j[n + 1] = j[n];
    }
    cn++;
    j[pos]=input;
}
void search( const int* j, int x, int cn){
    bool found=false;
    int index=0;
    for(int i=0;i<cn;i++){
        if(j[i]==x){
            found=true;
            index=i;
        }
    }
    if(found==true){
        std::cout<<"Element found at index: "<<index<<std::endl;
    }
    else{
        std::cout<<"element not found"<<std::endl;
    }
}

float avrg(const int* j,int cn){
    float average=0;
    float total=0;
    for(int i=0;i<cn;i++) {
        total+=j[i];
    }
    average=total/cn;
    return average;
}

void display(const int* j,int cn) {
    std::cout<<"array={ ";
    for (int x = 0; x < cn; x++) {
        std::cout << j[x] <<' ';
    }
    std::cout<<"}"<<std::endl;
}


int main() {
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
    while(true){
        cout << "Please enter number of Elements: ";
        cin >> c;
        getchar();
        if(c<1 || c>n){
            cout<<"Please enter a valid input\n";
        }
        else{
            break;
        }
    }

    for(int i=0; i < c; i++){
        cout<<"Enter elemnt at index "<<i<<": ";
        cin >> arr[i];
        getchar();
    }

    while(true) {
        cout << "\n\nChoose actions: \n0.exit\n1.Search\n2.average\n3.display\n4.insert element\n5.delete element\n\n" << endl;
        cin >> funcChoice;
        getchar();
        switch (funcChoice) {
            case '1': {
                int searchElement;
                cout << "\nEnter search element" <<endl;
                cin >> searchElement;
                search(arr, searchElement, c);
                break;
            }
            case '2': {
                cout << "\naverage is: " << avrg(arr, c) <<endl;
                break;
            }
            case '3': {
                display(arr, c);
                break;
            }
            case '4': {
                int pos = 0, input = 0;
                cout << "\nEnter position to insert element" << endl;
                cin >> pos;
                cout << "Enter element to insert" << endl;
                cin >> input;
                if (c >= n) {
                    std::cout << "Insertion failed, array limit exceeded" <<endl;
                } else {
                    insert(arr, pos, input, c);
                    cout << "Element inserted successfully" << endl;
                }
                break;
            }
            case '5': {
                int pos = 0;
                cout << "\nEnter position to delete element" << endl;
                cin >> pos;
                if (c == 0) {
                    std::cout << "Element deletion failed,array is empty" << endl;
                } else {
                    del(arr, pos, c);
                    std::cout << "Element deleted successfully" << endl;
                }
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
