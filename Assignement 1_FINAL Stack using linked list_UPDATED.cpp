#include <iostream>

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
    void pushFront(T val);
    void popFront();
    bool isEmpty();
    void display();
    T topElement();
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
    return head == NULL;
}

template <typename T> void LL<T> ::pushFront(T val) {
    auto* temp = new node<T>(val);
    temp->next = head;
    head = temp;
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

template <typename T> void LL<T> :: display() {
    node<T>* curr = head;
    std::cout<<"Stack: "<<std::endl;
    while(curr != NULL){
        std:: cout<< curr->val <<std::endl;
        curr = curr->next;
    }
    std::cout<<"\n";
}

template <typename T> T LL<T> ::topElement() {
    if(isEmpty()) {
        return -1;
    }
    else{
        return head->val;
    }
}

template< typename T >
class Stack{
private:
    LL<T>* stackValues;
public:
    Stack();
    ~Stack();
    void push( T );
    void pop();
    void display();
    T topElement();
    bool isEmpty();
};

template< typename T > Stack<T>::Stack() {
   stackValues = new LL<int>;
}

template< typename T > Stack<T>::~Stack() {
    delete [] stackValues;
}

template< typename T > bool Stack<T>:: isEmpty(){
    return stackValues->isEmpty();
}

template< typename T > void Stack<T>:: push(T x){
    stackValues->pushFront(x);
}

template< typename T > void Stack<T>:: pop() {
    stackValues->popFront();
}

template< typename T > T Stack<T>::topElement() {
    return stackValues->topElement();
}

template< typename T > void Stack<T>::display() {
    stackValues->display();
}

int main() {
    using namespace std;
    char choice;
    auto *S = new Stack<int>;

    while(true) {
        cout
                << "\n\nChoose actions: \n0. Exit\n1. Push element\n2. Pop element\n3. Show top Element\n4. Display stack\n"
                << endl;
        cin >> choice;
        getchar();

        switch (choice) {
            case '0': {
                exit(0);
            }
            case '1': {
                int x=0;
                cout<<"Please insert the value to be pushed: "<<endl;
                cin>>x;
                getchar();
                S->push(x);
                cout<<"Value pushed successfully\n"<<endl;
                break;
            }
            case '2': {
                if(S->isEmpty()){
                    cout<<"Operation failed.Stack is empty\n"<<endl;
                }
                else{
                    S->pop();
                    cout<<"Value popped successfully\n"<<endl;
                }
                break;
            }
            case '3': {
                int x = S->topElement();
                if(x==-1){
                    cout<<"Stack is empty\n"<<endl;
                }
                else{
                    cout<<"Top value is: "<<x<<endl;
                }
                break;
            }
            case '4': {
                S->display();
                break;
            }
            default: {
                cout<<"Invalid input. Please choose a valid input\n"<<endl;
            }
        }
    }
    return 0;
}
