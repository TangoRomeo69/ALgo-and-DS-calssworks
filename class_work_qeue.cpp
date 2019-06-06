#include<iostream>

template<typename T>
class Qeue{
private:
    int qeueSize;
    T* qeueValues;
    int front;
    int rear;
public:
    Qeue(int=10);
    ~Qeue();
    void enqeue( T );
    void deqeue();
    void extendSize(int = 10);
    void display();
    T frontValue();
    void reset();
    bool isEmpty();
    bool isFull();
};

template< typename T > Qeue<T>::Qeue(int x): qeueSize(x), qeueValues(new T[qeueSize]), front(-1), rear(-1){}

template< typename T > Qeue<T>::~Qeue() {
    delete[] qeueValues;
}

template< typename T > bool Qeue<T>::isFull() {
    if((rear + 1) == qeueSize )
        return true;
    else
        return false;
}

template< typename T > bool Qeue<T>::isEmpty() {
    if(front == -1 && rear == -1 )
        return true;
    else
        return false;
}

template< typename T > void Qeue<T>::enqeue(T x) {
    if(!Qeue<T>::isFull()) {
        qeueValues[++rear] = x;
    }
    else {
        extendSize();
        qeueValues[++rear] = x;
    }
}

template< typename T > void Qeue<T>::deqeue(){
    if(isEmpty()) {
        std::cout<<"deletion failed,Queue is Empty\n";
        return;
    }
    else if(front == rear ) {
        rear = front = -1;
    }
    else{
        front++;
    }
}

template< typename T > T Qeue<T>::frontValue() {
    if(front==-1){
        std::cout<<"Qeue is empty\n";
        return -1;
    }
    else{
        return qeueValues[front];
    }
}

template< typename T > void Qeue<T>::reset(){
    front=rear=-1;
}

template< typename T > void Qeue<T>::extendSize(int size){
    T *S = new T[qeueSize + size];
    for (int i = 0; i < qeueSize; i++) {
        S[i] = qeueValues[i];
    }
    qeueSize += size;
    delete[] qeueValues;
    qeueValues = S;
}

template< typename T > void Qeue<T>::display(){
    if(!Qeue<T>::isEmpty()){
        std::cout<<"\nQeue: "<<std::endl;
        for( int i=front; i<=rear; i++ ){
            std::cout << qeueValues[i] << std::endl;
        }
    }
    else
    {
        std::cout<< "\nQeue is Empty\n";
    }
}
