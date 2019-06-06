#include<iostream>

template <typename T>
struct node{
    explicit  node(T val) : val(val), next(NULL) {}
    T val;
    node<T>* next;
};

template <typename T>
class LL{
private:
    node<T>* head;
public:
    LL();
    ~LL();
    void pushBack(T val);
    void pushFront(T val);
    void popFront();
    void popBack();
    void removeVal(T val);
    void insertPos(int pos, T val);
    void removePos(int pos);
    bool isEmpty();
    void display();
    int count();
};

template <typename T> LL <T> :: LL() : head(NULL){}

template <typename T> LL <T> :: ~LL(){
    while(head != NULL){
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
}

template <typename T> bool LL<T> :: isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <typename T> void LL<T> :: pushBack(T val) {
    if (isEmpty()){
        head = new node<T>(val);
        return;
    }
    else{
        node<T>* prev = head;
        while(prev->next != NULL){
            prev = prev->next;
        }
        prev->next = new node<T>(val);
        return;
    }
}

template <typename T> void LL<T> ::pushFront(T val) {
    auto* temp = new node<T>(val);
    temp->next = head;
    head = temp;
}

template <typename T> void LL<T> ::insertPos(int pos, T val) {
    if(pos == 0) {
        pushFront(val);
        return;
    }
    else{
        node<T>* prev = head;
        for(int i=0;i<pos-1;i++){
            prev=prev->next;
        }
        node<T>* aft = prev->next;
        auto* temp = new node<T>(val);
        temp->next = aft;
        prev->next= temp;
        return;
    }
}

template <typename T> void LL<T> :: removeVal(T val) {

    node<T>* prev;
    node<T>* curr;
    if(isEmpty()) {
        std::cout<<"\nList is empty"<<std::endl;
        return;
    }

    if (head->val == val) {
        node<T>* temp = head;
        head = head->next;
        delete temp;

        return;
    }

    for (curr = head->next, prev = head; curr != NULL; curr = curr->next) {
        if (curr->val == val)
        {
            node<T>* temp = curr;
            prev->next = curr->next;
            delete temp;
        }
        prev = curr;
    }
}

template <typename T> void LL<T> :: popFront() {
    if(isEmpty()) {
        std::cout<<"\nList is empty"<<std::endl;
        return;
    }
    else{
        node<T> * temp = head;
        temp = head;
        head = head->next;
        delete temp;
        return;
    }
}

template <typename T> void LL<T> ::popBack() {
    if(isEmpty()) {
        std::cout<<"\nList is empty"<<std::endl;
        return;
    }
    else{
        node<T>* prev = head;
        node<T>* del = head->next;
        while(del->next!= NULL){
            prev = prev->next;
            del = del->next;
        }
        prev->next = NULL;
        delete del;
        return;
    }
}

template <typename T> void LL<T> :: removePos(int pos) {
    if(isEmpty()) {
        std::cout<<"\nList is empty"<<std::endl;
        return;
    }

    if(pos == 0){
        popFront();
    }
    else{
        node<T>* prev = head;
        for(int i=0;i<pos-1;i++){
            prev=prev->next;
        }
        node<T>* del = prev->next;
        node<T>* aft = del->next;
        prev->next = aft;
        delete del;
    }
}

template <typename T> void LL<T> :: display() {
    node<T>* curr = head;
    std::cout<<"List: ";
    while(curr != NULL){
        std:: cout<< curr->val << " ";
        curr = curr->next;
    }
    std::cout<<"\n";
}

template <typename T> int LL<T> ::count() {
    int count = 0;
    node<T>* curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}

int main(){
    using namespace std;
    char choice;
    auto* myList = new LL<int>;

    while(true) {
        cout << "\n\nChoose actions: \n0. Exit\n1. Push element at the tail\n2. Push element at the front\n"
                "3. Insert element at a certain position\n4. Pop front element\n5. Pop tail element\n"
                "6. Remove an element with certain value\n7. Remove element at a certain position\n8. Display list\n\n" << endl;
        cin >> choice;
        getchar();
        switch (choice) {
            case '1': {
                int x=0;
                cout<<"Please insert the value to be pushed at the tail"<<endl;
                cin>>x;
                getchar();
                myList->pushBack(x);
                cout<<"Value pushed successfully"<<endl;
                break;
            }
            case '2': {
                int x=0;
                cout<<"Please insert the value to be pushed at the front"<<endl;
                cin>>x;
                getchar();
                myList->pushFront(x);
                cout<<"Value pushed successfully"<<endl;
                break;
            }
            case '3': {
                int x=0,y=0,c=0;
                cout<<"Please enter the value to be inserted"<<endl;
                cin>>x;
                getchar();
                while(true){
                cout<<"Please enter the position to insert"<<endl;
                cin>>y;
                getchar();
                c = myList->count();
                    if (y < c) {
                        myList->insertPos(y, x);
                        cout << "Value inserted successfully" << endl;
                        break;
                    } else {
                        cout << "Wrong position input, please enter a valid location" << endl;
                    }
                }
                break;
            }
            case '4': {
                myList->popFront();
                cout<<"Value popped successfully"<<endl;
                break;
            }
            case '5': {
                myList->popBack();
                cout<<"Value popped successfully"<<endl;
                break;
            }
            case '6': {
                int x=0;
                cout<<"Insert the value to be deleted"<<endl;
                cin>>x;
                getchar();
                myList->removeVal(x);
                cout<<"Value removed successfully"<<endl;
                break;
            }
            case '7': {
                int x = 0;
                cout << "Insert the position of data to be deleted" << endl;
                cin >> x;
                getchar();
                myList->removePos(x);
                cout << "Value at position removed successfully" << endl;
                break;
            }
            case '8': {
                myList->display();
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
